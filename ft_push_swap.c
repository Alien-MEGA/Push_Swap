/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:23:40 by reben-ha          #+#    #+#             */
/*   Updated: 2023/01/02 20:56:43 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_print_lst(t_list *head, int option)
{	
	while (head != NULL)
	{
		printf("\ndata = %d  index = %d  index_of_last = %d  lis = %d", head->data, head->index, head->index_of_last, head->lis);
		head = head->next;
	}
	if (option == 'A')
		printf("\n-----------------------------------------------\n                      A\n");
	if (option == 'B')
		printf("\n-----------------------------------------------\n                      B\n");
}

t_list	*node_i(t_list *head, int index)
{
	while (head)
	{
		
		if (head->index == index)
			return (head);
		head = head->next;
	}
	return (NULL);
}

static void	ft_error(void)
{
	write(2, "\e[1;31m[ERROR]", 14);
	write(2, " : Add more argument!\n", 22);
	write(2 ,"\e[0m        ./a.out . . .\n", 26);
	write(2 ,"\e[1;32m                ^~~~~\n", 29);
	write(2 ,"\e[0m1 warning generated.\n", 25);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*tmp_node;
	int		i;
	// t_list	*head_of_b;
	// int		min_nb;

	if (argc <= 1)
		return (ft_error(), 0);
	i = 1;
	while (i < argc)
		ft_lstadd_back(&stack_a, (ft_lstnew(ft_atoi(argv[i++]))));
	// printf("\n\n\n\n\n\n\n");
	// ft_print_lst(head_of_a, 'A');
	// printf("\n\n\n\n\n\n\n");

	
	/*
	* Find LIS
	* Move not LIS to stack B
	* Find fast way number that can moving to here 
		place with lowest possible number of operations
	*/
	i = 0;
	tmp_node = stack_a;
	while (tmp_node)
	{
		tmp_node->index = i;
		tmp_node->index_of_last = 0;
		tmp_node->lis = 1;
		i++;
		tmp_node = tmp_node->next;
	}
	






















	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	







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