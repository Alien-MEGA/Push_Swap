/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:23:40 by reben-ha          #+#    #+#             */
/*   Updated: 2023/01/05 20:47:51 by reben-ha         ###   ########.fr       */
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

t_list	*in(t_list *head, int index)
{
	while (head)
	{
		if (head->index == index)
			return (head);
		head = head->next;
	}
	return (NULL);
}

static void	ft_error(int option)
{
	if (option == 1)
	{
		write(2, "\e[1;31m[ERROR] : Add more argument!\n", 37);
		write(2 ,"\e[0m        ./a.out . . .\n", 26);
		write(2 ,"\e[1;32m                ^~~~~\n\e[0m1 warning generated.\n", 54);
	}
	if (option == 2)
	{
		write(2, "\e[1;31m[ERROR]", 14);
		write(2, " : Malloc failed to allocate memory\n", 36);
		write(2 ,"\e[0m1 warning generated.\n", 25);
	}
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*tmp_node;
	int		lis;
	int		sub_index;
	int		max_lis;
	int		*expected;
	int		i;
	int		j;

	if (argc <= 1) // if there just 1 arg
		return (ft_error(1), 0);
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
		return (ft_error(2) ,0);
	j = 0;
	while (j < max_lis) 
	{
		expected[j] = in(stack_a, i)->data;
		i = in(stack_a, i)->sub_index;
		j++;
	}
//                                  * 2 : Move not LIS to stack B

	























	// ft_print_lst(head_of_a, 'A');
	// ft_print_lst(head_of_b, 'B');
}





	// My algo :
	// while (head_of_a)
	// {	
	// 	tmp_node = head_of_a;
	// 	min_nb = tmp_node->data;
	// 	tmp_node = tmp_node->next;
	// 	while (tmp_node)
	// 	{
	// 		min_nb = (min_nb <= tmp_node->data ? min_nb : tmp_node->data);
	// 		tmp_node = tmp_node->next;
	// 	}
	// 	while (min_nb != head_of_a->data)
	// 		rr_ab(&head_of_a, &head_of_b, 'a');
	// 	p_ab(&head_of_a, &head_of_b, 'b');
	// }
	// while (head_of_b)
	// 	p_ab(&head_of_b, &head_of_a, 'a');


	// //Test for linked list
	// printf("\n\n\n\nStart :\n\n");
	// head_of_b = NULL;
	// tmp_node = head_of_a;
	// ft_print_lst(head_of_a, 'A');
	// ft_print_lst(head_of_b, 'B');
	// printf("\n\n1 = New :\n\n");

	// p_ab(&head_of_a, &head_of_b, 'a');
	// p_ab(&head_of_a, &head_of_b, 'b');
	// p_ab(&head_of_a, &head_of_b, 'X');

	// ss_ab(head_of_a, head_of_b, 'a');
	// ss_ab(head_of_a, head_of_b, 'b');
	// ss_ab(head_of_a, head_of_b, 'X');

	// rr_ab(&head_of_a, &head_of_b, 'a');
	// rr_ab(&head_of_a, &head_of_b, 'b');
	// rr_ab(&head_of_a, &head_of_b, 'X');

	// rrr_ab(&head_of_a, &head_of_b, 'a');
	// rrr_ab(&head_of_a, &head_of_b, 'b');
	// rrr_ab(&head_of_a, &head_of_b, 'X');

	// ft_print_lst(head_of_a, 'A');

	// ft_print_lst(head_of_b, 'B');
	
	// //End