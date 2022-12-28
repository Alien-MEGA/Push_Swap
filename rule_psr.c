/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_psr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:20:20 by reben-ha          #+#    #+#             */
/*   Updated: 2022/12/27 22:55:14 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	p_ab(t_list **head_of_a, t_list **head_of_b, int option)
{
	t_list	*tmp_node;

	if (option == 'a')
	{
		ft_lstadd_front(head_of_a, (*head_of_b));
		(*head_of_b) = (*head_of_b)->next;
		(*head_of_a)->next = NULL;
		write(1, "pa\n", 3);
	}
	if (option == 'b')
	{
		ft_lstadd_front(head_of_b, ft_lstnew((*head_of_a)->data));
		tmp_node = (*head_of_a);
		(*head_of_a) = (*head_of_a)->next;
		free(tmp_node);
		write(1, "pb\n", 3);
	}
}
	// if (option == 'b')
	// {
	// 	ft_lstadd_front(head_of_b, (*head_of_a));
	// 	(*head_of_a) = (*head_of_a)->next;
	// 	(*head_of_b)->next = NULL;
	// 	write(1, "pb\n", 3);
	// }
//Take the data and make new node and link with addfront
void	ss_ab(t_list *head_of_a, t_list *head_of_b, int option)
{
	int	tmp;

	if (option == 'a' || option == 'b' || option == 'X')
	{
		if (option == 'a' || option == 'X')
		{
			tmp = head_of_a->data;
			head_of_a->data = head_of_a->next->data;
			head_of_a->next->data = tmp;
			if (option == 'a')
				write(1, "sa\n", 3);
		}
		if (option == 'b' || option == 'X')
		{
			tmp = head_of_b->data;
			head_of_b->data = head_of_b->next->data;
			head_of_b->next->data = tmp;
			if (option == 'b')
				write(1, "sb\n", 3);
		}
		if (option == 'X')
			write(1, "ss\n", 3);
	}
}

void	rr_ab(t_list *head_of_a, t_list *head_of_b, int option)
{
	t_list	*tmp_node;

	if (option == 'a' || option == 'b' || option == 'X')
	{
		if (option == 'a' || option == 'X')
		{
			tmp_node = head_of_a;
			head_of_a = head_of_a->next;
			tmp_node->next = NULL;
			ft_lstadd_back(&head_of_a, tmp_node);
			if (option == 'a')
				write(1, "ra\n", 3);
		}
		if (option == 'b' || option == 'X')
		{
			tmp_node = head_of_b;
			head_of_b = head_of_b->next;
			tmp_node->next = NULL;
			ft_lstadd_back(&head_of_b, tmp_node);
			if (option == 'b')
				write(1, "rb\n", 3);
		}
		if (option == 'X')
			write(1, "rr\n", 3);
	}
}

void	rrr_ab(t_list *head_of_a, t_list *head_of_b, int option)
{
	t_list	*tmp_node;
	int		i;

	i = 0;
	if (option == 'a' || option == 'b' || option == 'X')
	{
		if (option == 'a' || option == 'X')
		{
			tmp_node = head_of_a;
			while (i < (ft_lstsize(tmp_node) - 1))
			{
				tmp_node = tmp_node->next;
				i++;
			}
			ft_lstadd_front(&head_of_a, ft_lstlast(head_of_a));
			tmp_node->next = NULL;
			if (option == 'a')
				write(1, "rra\n", 4);
		}
		if (option == 'b' || option == 'X')
		{
			tmp_node = head_of_b;
			while (i < (ft_lstsize(tmp_node) - 1))
			{
				tmp_node = tmp_node->next;
				i++;
			}
			ft_lstadd_front(&head_of_b, ft_lstlast(head_of_b));
			tmp_node->next = NULL;
			if (option == 'b')
				write(1, "rrb\n", 4);
		}
		if (option == 'X')
			write(1, "rrr\n", 4);
	}
}
