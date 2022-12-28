/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:23:40 by reben-ha          #+#    #+#             */
/*   Updated: 2022/12/28 11:59:22 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_print_lst(t_list *head, int option)
{	
	while (head != NULL) // Print list b
	{
		printf("\n%d", head->data);
		head = head->next;
	}
	if (option == 'A')
		printf("\n-\nA\n");
	if (option == 'B')
		printf("\n-\nB\n");	
}

static void	ft_error(void)
{
	write(1, "\e[1;31m[ERROR]", 14);
	write(1, " : Add more argument!\n", 22);
	write(1 ,"\e[0m        ./a.out . . .\n", 26);
	write(1 ,"\e[1;32m                ^~~~~\n", 29);
	write(1 ,"\e[0m1 warning generated.\n", 25);
}

int	main(int argc, char *argv[])
{
	t_list	*head_of_a;
	t_list	*tmp_node;
	t_list	*head_of_b;
	t_list	*tmp_node_a;
	t_list	*tmp_node_b;
	int		i;

	if (argc <= 1)
		return (ft_error(), 0);
	i = 1;
	while (i < argc)
	{
		ft_lstadd_back(&head_of_a, (ft_lstnew(ft_atoi(argv[i]))));
		i++;
	}
	//Test for linked list
	tmp_node = head_of_a;
	ft_print_lst(head_of_a, 'A');
	

	// Test OK : rrr_ab(tmp_node, NULL, 'a'); 
	// Test OK : rr_ab(tmp_node, NULL, 'a');
	// Test OK : ss_ab(tmp_node, NULL, 'a');
	// printf("\n\n1 = New :");

	// p_ab(&head_of_a, &head_of_b, 'b');
	// p_ab(&head_of_a, &head_of_b, 'b');
	// p_ab(&head_of_a, &head_of_b, 'b');
	// p_ab(&head_of_a, &head_of_b, 'b');
	// p_ab(&head_of_a, &head_of_b, 'b');
	// p_ab(&head_of_a, &head_of_b, 'b');
	// ss_ab(head_of_a, head_of_b, 'b');
	// rr_ab(head_of_a, head_of_b, 'b');
	// rrr_ab(head_of_a, head_of_b, 'b');

	ft_print_lst(head_of_a, 'A');
	
	// ft_print_lst(head_of_b, 'B');

	// ss_ab(head_of_a, head_of_b, 'b');

	
	ft_print_lst(head_of_b, 'B');
	
	//End
}


















