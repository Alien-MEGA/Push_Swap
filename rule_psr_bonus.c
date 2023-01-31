/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_psr_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:20:20 by reben-ha          #+#    #+#             */
/*   Updated: 2023/01/20 17:35:24 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	p_ab(t_list **from_lst, t_list **to_lst)
{
	t_list	*tmp_node;

	if (!from_lst)
		return ;
	if (!(*from_lst))
		return ;
	ft_lstadd_front(to_lst, ft_lstnew((*from_lst)->data));
	tmp_node = (*from_lst);
	(*from_lst) = (*from_lst)->next;
	free(tmp_node);
}

void	ss_ab(t_list *head_of_a, t_list *head_of_b, int option)
{
	int	tmp;

	if (((!head_of_a) || (!head_of_b)) && option == 'X')
		return ;
	if (option == 'a' || option == 'b' || option == 'X')
	{
		if (option == 'a' || option == 'X')
		{
			if ((!head_of_a))
				return ;
			tmp = head_of_a->data;
			head_of_a->data = head_of_a->next->data;
			head_of_a->next->data = tmp;
		}
		if (option == 'b' || option == 'X')
		{
			if ((!head_of_b))
				return ;
			tmp = head_of_b->data;
			head_of_b->data = head_of_b->next->data;
			head_of_b->next->data = tmp;
		}
	}
}

void	rr_ab(t_list **head_of_a, t_list **head_of_b, int option)
{
	t_list	*tmp_node;

	if ((option == 'a' && !head_of_a) || (option == 'b' && !head_of_b))
		return ;
	if (option == 'a' || option == 'b' || option == 'X')
	{
		if (option == 'a' || option == 'X')
		{
			if (!(*head_of_a))
				return ;
			tmp_node = (*head_of_a);
			(*head_of_a) = (*head_of_a)->next;
			tmp_node->next = NULL;
			ft_lstadd_back(head_of_a, tmp_node);
		}
		if (option == 'b' || option == 'X')
		{
			if (!(*head_of_b))
				return ;
			tmp_node = (*head_of_b);
			(*head_of_b) = (*head_of_b)->next;
			tmp_node->next = NULL;
			ft_lstadd_back(head_of_b, tmp_node);
		}
	}
}

void	short_rrr_ab(t_list **head)
{
	t_list	*tmp;
	t_list	*last;

	tmp = (*head);
	while (tmp->next)
	{
		last = tmp;
		tmp = tmp->next;
	}
	last->next = NULL;
	ft_lstadd_front(head, tmp);
}

void	rrr_ab(t_list **head_of_a, t_list **head_of_b, int option)
{
	if ((option == 'a' && !head_of_a) || (option == 'b' && !head_of_b))
		return ;
	if (option == 'a' || option == 'b' || option == 'X')
	{
		if (option == 'a' || option == 'X')
		{
			if (!(*head_of_a))
				return ;
			short_rrr_ab(head_of_a);
		}
		if (option == 'b' || option == 'X')
		{
			if (!(*head_of_b))
				return ;
			short_rrr_ab(head_of_b);
		}
	}
}
