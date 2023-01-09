/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_psr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:20:20 by reben-ha          #+#    #+#             */
/*   Updated: 2023/01/09 16:48:41 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// - `pa` (push A): Take the first element at the top of B and put it at the top of A. Do nothing if B is empty.
// - `pb` (push B): Take the first element at the top of A and put it at the top of B. Do nothing if A is empty.
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

// - `sa` (swap A): Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no element.
// - `sb` (swap B): Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no element.
void	ss_ab(t_list *head_of_a, t_list *head_of_b, int option)
{
	int	tmp;

	if (((!head_of_a) || (!head_of_b)) && option == 'X')
		return ;
	if (option == 'a' || option == 'b' || option == 'X')
	{
		if (option == 'a' || option == 'X')
		{
			if ((!head_of_a) && option == 'a')
				return ;
			tmp = head_of_a->data;
			head_of_a->data = head_of_a->next->data;
			head_of_a->next->data = tmp;
			if (option == 'a')
				write(1, "sa\n", 3);
		}
		if (option == 'b' || option == 'X')
		{
			if ((!head_of_b) && option == 'b')
				return ;
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

// - `ra` (rotate A): Shift all elements of stack A up by 1. The first element becomes the last one.
// - `rb` (rotate B): Shift all elements of stack B up by 1. The first element becomes the last one.
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

// - `rra` (reverse rotate A): Shift all elements of stack A down by 1. The last element becomes the first one.
// - `rrb` (reverse rotate B): Shift all elements of stack b down by 1. The last element becomes the first one.
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
				return;
			tmp_a = (*head_of_a);
			while (tmp_a->next)
			{
				last_a = tmp_a;
				tmp_a = tmp_a->next;
			}
			last_a->next = NULL;
			ft_lstadd_front(head_of_a, tmp_a);
			if (option == 'a')
				write(1, "rra\n", 4);
		}
		if (option == 'b' || option == 'X')
		{
			if (*head_of_b == NULL)
				return;
			tmp_b = (*head_of_b);
			while (tmp_b->next)
			{
				last_b = tmp_b;
				tmp_b = tmp_b->next;
			}
			last_b->next = NULL;
			ft_lstadd_front(head_of_b, tmp_b);
			if (option == 'b')
				write(1, "rrb\n", 4);
		}
		if (option == 'X')
			write(1, "rrr\n", 4);
	}
}
