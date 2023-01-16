/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:23:40 by reben-ha          #+#    #+#             */
/*   Updated: 2023/01/16 15:28:11 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_print_lst(t_list *head, int option) // delete this
{	
	while (head != NULL)
	{
		printf("\nindex = %d  data = %ld  lis = %d  sub_index = %d  h_lis = %d  instr_s = %d", head->index, head->data, head->lis, head->sub_index, head->h_lis, head->instr_s);
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
			target->sub_index = max_n->index;
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

int	main(int argc, char **argv) // Add function to check
{
	char	*full_str;
	char	**str;
	t_list	*stack_a;
	t_list	*stack_b;
	int		lis;
	int		sub_index;
	int		max_lis;
	int		i;
	int		j;
	t_list	*target;
	t_list	*position;
	int		len_a;
	int		len_b;

	if (argc <= 1)
		return (1);
	i = 0;
	while (++i < argc)
	{
		full_str = ft_strjoin(full_str, argv[i]);
		full_str = ft_strjoin(full_str, " ");
	}
	i = 0;
	while (full_str[i] != '\0')
	{
		if (ft_isdigit(full_str[i]) == 0 && full_str[i] != 32
			 && !((full_str[i] == '+' || full_str[i] == '-') && ft_isdigit(full_str[i + 1]) == 1))
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	str = ft_split(full_str, ' ');
	i = -1;
	while (str[++i] != NULL)
		ft_lstadd_back(&stack_a, (ft_lstnew(ft_atoi(str[i]))));
	ft_indexing(stack_a);

	i = 0;
	len_a = 0;
	while (in(stack_a, i))
	{
		j = i + 1;
		while (in(stack_a, j))
		{
			if (in(stack_a, i)->data == in(stack_a, j)->data)
			{
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (in(stack_a, i))
	{
		if (in(stack_a, i)->data > INT_MAX)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		i++;
	}

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
	j = max_lis - 1;
	while (j >= 0) 
	{
		in(stack_a, i)->lis = -1;
		i = in(stack_a, i)->sub_index;
		j--;
	}
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
			p_ab(&stack_a, &stack_b, 'b');
	}
	ft_indexing(stack_a);
	ft_indexing(stack_b);

	while (stack_b)
	{
		ft_indexing(stack_a);
		ft_indexing(stack_b);
		ft_instra(&stack_a, &stack_b);
		target = stack_b;
		len_a = ft_lstsize(stack_a);
		len_b = ft_lstsize(stack_b);
		j = -1;
		while (in(stack_b, ++j))
			target = target->instr_s > in(stack_b, j)->instr_s ? in(stack_b, j) : target;
		position = in(stack_a, (target->sub_index));
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
		{
			while (!(stack_a->data == position->data))
			{
				if (ft_lstlast(stack_a)->data == position->data && target->data > position->data)
					break;
				rrr_ab(&stack_a, &stack_b, 'a');
			}
		}
		if ((stack_a->data == position->data) && (target->data > position->data))
			rr_ab(&stack_a, &stack_b, 'a');
		p_ab(&stack_b, &stack_a, 'a');
	}
	ft_indexing(stack_a);

	target = stack_a;
	i = -1;
	while (in(stack_a, ++i))
		if (target->data > in(stack_a, i)->data)
			target = in(stack_a, i);
	target->h_lis = 1;
	len_a = ft_lstsize(stack_a);
	if (target->index <= (len_a / 2))
		while (!(stack_a->h_lis == 1))
			rr_ab(&stack_a, &stack_b, 'a');
	else if (target->index > (len_a / 2))
		while (!(stack_a->h_lis == 1))
			rrr_ab(&stack_a, &stack_b, 'a');
	// ft_print_lst(stack_a, 'A');
	// ft_print_lst(stack_b, 'B');
	// system("leaks push_swap");
}
