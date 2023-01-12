/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:23:40 by reben-ha          #+#    #+#             */
/*   Updated: 2023/01/12 20:40:33 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_print_lst(t_list *head, int option)
{	
	while (head != NULL)
	{
		printf("\nindex = %d  data = %d  lis = %d  sub_index = %d  h_lis = %d  instr_s = %d", head->index, head->data, head->lis, head->sub_index, head->h_lis, head->instr_s);
		head = head->next;
	}
	if (option == 'A')
		printf("\n--------------------------------------------------------------------\n				A\n");
	if (option == 'B')
		printf("\n--------------------------------------------------------------------\n				B\n");
}


static t_list	*in(t_list *head, int index)
{
	while (head)
	{
		if (head->index == index)
			return (head);
		head = head->next;
	}
	return (NULL);
}

void	ft_indexing(t_list *stack_a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		stack_a->index = i;
		stack_a->sub_index = -1;
		stack_a->lis = 1;
		stack_a->h_lis = 0;
		stack_a->instr_s = 1;
		i++;
		stack_a = stack_a->next;
	}
}

void	ft_instra(t_list **stack_a, t_list **stack_b)
{
	t_list	*max_n;
	t_list	*min_n;
	t_list	*min_max_n;
	t_list	*target;
	int		i;
	int		j;
	int		len_a;
	int		len_b;

	j = -1;
	len_a = ft_lstsize((*stack_a));
	len_b = ft_lstsize((*stack_b));
	while (in((*stack_b), ++j))
	{
		target = in((*stack_b), j);
		max_n = (*stack_a);
		min_n = (*stack_a);
		min_max_n = ft_lstnew(INT_MAX);
		i = 0;
		while (in((*stack_a), i))
		{
			max_n = (max_n->data < in((*stack_a), i)->data ? in((*stack_a), i) : max_n);
			min_n = (min_n->data > in((*stack_a), i)->data ? in((*stack_a), i) : min_n);
			i++;
		}
		// instraction that need the position to be in the first in top
		if (target->data > ft_lstlast((*stack_a))->data && target->data < (*stack_a)->data)
		{
			target->instr_s += 0;
			target->sub_index = 0;
		}
		else if (target->data < min_n->data)
		{
			if (min_n->index <= (len_a / 2))
				target->instr_s += (min_n->index);
			else if (min_n->index > (len_a / 2))
				target->instr_s += (len_a - (min_n->index + 1)) + 1;
			target->sub_index = min_n->index;
		}
		else if (target->data > max_n->data)
		{
			if (max_n->index <= (len_a / 2))
				target->instr_s += (max_n->index) + 1;
			else if (max_n->index > (len_a / 2))
				target->instr_s += (len_a - (max_n->index)) - 1;
			target->sub_index = (-1) * (max_n->index);
			printf("\n\n\n\n+ %d + %d\n\n\n", max_n->index, max_n->data);
		}
		else
		{
			i = -1;
			while (in((*stack_a), ++i)->next)
				if (target->data > in((*stack_a), i)->data && target->data < in((*stack_a), (i + 1))->data)
					min_max_n = in((*stack_a), (i + 1));
			if (min_max_n->index <= (len_a / 2))
				target->instr_s += (min_max_n->index);
			else if (min_max_n->index > (len_a / 2))
				target->instr_s += (len_a - (min_max_n->index + 1)) + 1;
			target->sub_index = min_max_n->index;
		}
		// instraction that need the target to be in the first in top
		if (target->index <= (len_b / 2))
		{
			target->instr_s += target->index;
		}
		else if (target->index > (len_b / 2))
		{
			target->instr_s += (len_b - target->index);
		}
	}
}

int	main(int argc, char *argv[]) // Add function to check
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		lis;
	int		sub_index;
	int		max_lis;
	int		*expected;
	int		i;
	int		j;

	if (argc <= 1) // if there just 1 arg
		return (write(1, "Error\n", 6), 0);
// make arg to linked list
	i = 1;
	while (i < argc)
		ft_lstadd_back(&stack_a, (ft_lstnew(ft_atoi(argv[i++]))));
/*	
	* 1 : Find LIS
	* 2 : Move not LIS to stack B
	* 3 : Find fast way number that can moving to here 
			place with lowest possible number of operations
*/
// add some info
	tmp_a = stack_a;
	ft_indexing(tmp_a);
//test
	ft_print_lst(stack_a, 'A');
//                                  * 1 : Find LIS
// find LIS
	i = 1;
	while (in(stack_a, i))
	{
		j = 0;
		lis = 1;
		sub_index = -1;
		while (j < i)
		{
			if (in(stack_a, j)->data < in(stack_a, i)->data)
			{
				if (lis < (in(stack_a, j)->lis + in(stack_a, i)->lis))
				{
					lis = in(stack_a, j)->lis + in(stack_a, i)->lis;
					sub_index = in(stack_a, j)->index;
				}
			}
			j++;
		}
		in(stack_a, i)->lis = lis;
		in(stack_a, i)->sub_index = sub_index;
		i++;
	}
//test
	ft_print_lst(stack_a, 'A');
// find len of LIS and the node that has max len_lis
	max_lis = -1;
	i = -1;
	j = -1;
	while (in(stack_a, ++i))
	{
		while (in(stack_a, ++j))
			max_lis = (max_lis < in(stack_a, j)->lis ? in(stack_a, j)->lis : max_lis);
		if (max_lis == in(stack_a, i)->lis)
			break;
	}
//test
	ft_print_lst(stack_a, 'A');
// move LIS to array
	expected = (int *)malloc(max_lis * sizeof(int));
	if (!expected)
		return (write(1, "Error\n", 6) ,0);
	j = max_lis - 1;
	while (j >= 0) 
	{
		expected[j] = in(stack_a, i)->data;
		in(stack_a, i)->lis = -1;
		i = in(stack_a, i)->sub_index;
		j--;
	}
//test
	ft_print_lst(stack_a, 'A');
//                                  * 2 : Move not LIS to stack B

	i = 1;
	while (stack_a->h_lis != 1)
	{
		if (stack_a->lis == -1)
		{
			if (i == 1)
				stack_a->h_lis = 1;
			i = 0;
			rr_ab(&stack_a, &stack_b, 'a');
		}
		else
			p_ab(&stack_a, &stack_b, 'a');
	}
//indexing
	tmp_a = stack_a;
	ft_indexing(tmp_a);
	tmp_b = stack_b;
	ft_indexing(tmp_b);
//test
	ft_print_lst(stack_a, 'A');
	ft_print_lst(stack_b, 'B');

// 						* 3 : Find fast way number that can moving to here 
// 								place with lowest possible number of operations
	t_list	*target;
	t_list	*position;
	int		len_a;
	int		len_b;


	while (stack_b)
	{
		ft_indexing(stack_a);
		ft_indexing(stack_b);
		ft_instra(&stack_a, &stack_b);
		//test
		ft_print_lst(stack_b, 'B');
		// 
		target = stack_b;
		len_a = ft_lstsize(stack_a);
		len_b = ft_lstsize(stack_b);
		j = -1;
		while (in(stack_b, ++j))
			target = target->instr_s > in(stack_b, j)->instr_s ? in(stack_b, j) : target;
		position = in(stack_a, (target->sub_index));
		ft_print_lst(stack_a, 'A');
		

// seg fault ?? 
// and handle case (if the target is big than max number in stack a)


		printf("\ntarget = %p\v position = %p\v stack_a = %p\v stack_b = %p\v\nStart :{ \n", target, position, stack_a, stack_b);
		if ((target->index <= (len_b / 2)) && (position->index <= (len_a / 2)))
			while (!(stack_b->data == target->data) && !(stack_a->data == position->data))
				rr_ab(&stack_a, &stack_b, 'X');
		else if ((target->index > (len_b / 2)) && (position->index > (len_a / 2)))
			while (!(stack_b->data == target->data) && !(stack_a->data == position->data))
				rrr_ab(&stack_a, &stack_b, 'X');
		if ((target->index <= (len_b / 2)))
			while (!(stack_b->data == target->data))
				rr_ab(&stack_a, &stack_b, 'b');
		else if ((target->index > (len_b / 2)))
			while (!(stack_b->data == target->data))
				rrr_ab(&stack_a, &stack_b, 'b');
		if ((position->index <= (len_a / 2)))
			while (!(stack_a->data == position->data))
				rr_ab(&stack_a, &stack_b, 'a');
		else if ((position->index > (len_a / 2)))
			while (!(stack_a->data == position->data))
				rrr_ab(&stack_a, &stack_b, 'a');


		p_ab(&stack_b, &stack_a, 'a');



		printf("\n} End\n");
	}






				// printf("\n%d === %d", stack_a->data, position->data);

	// ft_instra(&stack_a, &stack_b);

// //test
	ft_print_lst(stack_a, 'A');
	ft_print_lst(stack_b, 'B');













	// ft_print_lst(head_of_a, 'A');
	// ft_print_lst(head_of_b, 'B');
}
