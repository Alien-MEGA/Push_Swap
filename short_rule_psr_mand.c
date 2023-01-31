/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_rule_psr_mand.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:10:35 by reben-ha          #+#    #+#             */
/*   Updated: 2023/01/20 17:11:17 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (option == 'a' || option == 'b' || option == 'X')
	{
		if (option == 'a' || option == 'X')
		{
			if (*head_of_a == NULL)
				return ;
			short_rrr_ab(head_of_a);
			if (option == 'a')
				write(1, "rra\n", 4);
		}
		if (option == 'b' || option == 'X')
		{
			if (*head_of_b == NULL)
				return ;
			short_rrr_ab(head_of_b);
			if (option == 'b')
				write(1, "rrb\n", 4);
		}
		if (option == 'X')
			write(1, "rrr\n", 4);
	}
}
