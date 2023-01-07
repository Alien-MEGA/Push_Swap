/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:23:40 by reben-ha          #+#    #+#             */
/*   Updated: 2023/01/07 18:04:03 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_print_lst(t_list *head, int option)
{	
	while (head != NULL)
	{
		printf("\nindex = %d  data = %d  lis = %d  sub_index = %d", head->index, head->data, head->lis, head->sub_index);
		head = head->next;
	}
	if (option == 'A')
		printf("\n-----------------------------------------------\n                      A\n");
	if (option == 'B')
		printf("\n-----------------------------------------------\n                      B\n");
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

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*tmp_node;
	int		lis;
	int		sub_index;
	int		max_lis;
	int		*expected;
	int		i;
	int		j;

	if (argc <= 1) // if there just 1 arg
		return (write(2, "Error\n", 6), 0);
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
	i = 0;
	tmp_node = stack_a;
	while (tmp_node)
	{
		tmp_node->index = i;
		tmp_node->sub_index = -1;
		tmp_node->lis = 1;
		tmp_node->h_lis = 0;
		i++;
		tmp_node = tmp_node->next;
	}
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
		return (write(2, "Error\n", 6) ,0);
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
//test
	ft_print_lst(stack_a, 'A');
	ft_print_lst(stack_b, 'B');

//                                  * 2 : Move not LIS to stack B


























	// ft_print_lst(head_of_a, 'A');
	// ft_print_lst(head_of_b, 'B');
}
