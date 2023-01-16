/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_psr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:20:20 by reben-ha          #+#    #+#             */
/*   Updated: 2023/01/16 20:50:06 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	p_ab(t_list **from_lst, t_list **to_lst)
{
	t_list	*tmp_node;

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

	if (option == 'a' || option == 'b' || option == 'X')
	{
		if (option == 'a' || option == 'X')
		{
			tmp_node = (*head_of_a);
			(*head_of_a) = (*head_of_a)->next;
			tmp_node->next = NULL;
			ft_lstadd_back(head_of_a, tmp_node);
		}
		if (option == 'b' || option == 'X')
		{
			tmp_node = (*head_of_b);
			(*head_of_b) = (*head_of_b)->next;
			tmp_node->next = NULL;
			ft_lstadd_back(head_of_b, tmp_node);
		}
	}
}

void	rrr_ab(t_list **head_of_a, t_list **head_of_b, int option)
{
	t_list	*tmp_a;
	t_list	*last_a;
	t_list	*tmp_b;
	t_list	*last_b;

	if (option == 'a' || option == 'b' || option == 'X')
	{
		if (option == 'a' || option == 'X')
		{
			if (*head_of_a == NULL)
				return ;
			tmp_a = (*head_of_a);
			while (tmp_a->next)
			{
				last_a = tmp_a;
				tmp_a = tmp_a->next;
			}
			last_a->next = NULL;
			ft_lstadd_front(head_of_a, tmp_a);
		}
		if (option == 'b' || option == 'X')
		{
			if (*head_of_b == NULL)
				return ;
			tmp_b = (*head_of_b);
			while (tmp_b->next)
			{
				last_b = tmp_b;
				tmp_b = tmp_b->next;
			}
			last_b->next = NULL;
			ft_lstadd_front(head_of_b, tmp_b);
		}
	}
}
