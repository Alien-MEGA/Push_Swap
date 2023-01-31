/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_psr_mand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:20:20 by reben-ha          #+#    #+#             */
/*   Updated: 2023/01/20 23:54:10 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	p_ab(t_list **from_lst, t_list **to_lst, int option)
{
	t_list	*tmp_node;

	ft_lstadd_front(to_lst, ft_lstnew((*from_lst)->data));
	tmp_node = (*from_lst);
	(*from_lst) = (*from_lst)->next;
	free(tmp_node);
	if (option == 'a')
		write(1, "pa\n", 3);
	if (option == 'b')
		write(1, "pb\n", 3);
}

void	short_ss_ab(t_list *head)
{
	int	tmp;

	tmp = head->data;
	head->data = head->next->data;
	head->next->data = tmp;
}

void	ss_ab(t_list *head_of_a, t_list *head_of_b, int option)
{
	if (((!head_of_a) || (!head_of_b)) && option == 'X')
		return ;
	if (option == 'a' || option == 'b' || option == 'X')
	{
		if (option == 'a' || option == 'X')
		{
			if ((!head_of_a))
				return ;
			short_ss_ab(head_of_a);
			if (option == 'a')
				write(1, "sa\n", 3);
		}
		if (option == 'b' || option == 'X')
		{
			if ((!head_of_b))
				return ;
			short_ss_ab(head_of_b);
			if (option == 'b')
				write(1, "sb\n", 3);
		}
		if (option == 'X')
			write(1, "ss\n", 3);
	}
}

void	rr_ab(t_list **head_of_a, t_list **head_of_b, int option)
{
	t_list	*tmp_node;

	if (option == 'a' || option == 'b' || option == 'X')
	{
		if (option == 'a' || option == 'X')
		{
			tmp_node = (*head_of_a);
			(*head_of_a) = (*head_of_a)->next;
			tmp_node->next = NULL;
			ft_lstadd_back(head_of_a, tmp_node);
			if (option == 'a')
				write(1, "ra\n", 3);
		}
		if (option == 'b' || option == 'X')
		{
			tmp_node = (*head_of_b);
			(*head_of_b) = (*head_of_b)->next;
			tmp_node->next = NULL;
			ft_lstadd_back(head_of_b, tmp_node);
			if (option == 'b')
				write(1, "rb\n", 3);
		}
		if (option == 'X')
			write(1, "rr\n", 3);
	}
}
