/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_three_mand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:38:19 by reben-ha          #+#    #+#             */
/*   Updated: 2023/01/19 23:16:29 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	short_find_lis(t_list **stack_a, int i, int lis, int sub_index)
{
	in(*stack_a, i)->lis = lis;
	in(*stack_a, i)->sub_index = sub_index;
}

void	ft_find_lis(t_list **stack_a)
{
	int	i;
	int	j;
	int	lis;
	int	sub_index;

	i = 0;
	while (in(*stack_a, ++i))
	{
		j = 0;
		lis = 1;
		sub_index = -1;
		while (j < i)
		{
			if (in(*stack_a, j)->data < in(*stack_a, i)->data)
			{
				if (lis < (in(*stack_a, j)->lis + in(*stack_a, i)->lis))
				{
					lis = in(*stack_a, j)->lis + in(*stack_a, i)->lis;
					sub_index = in(*stack_a, j)->index;
				}
			}
			j++;
		}
		short_find_lis(stack_a, i, lis, sub_index);
	}
}

void	ft_part_find_lis(t_list **stack_a)
{
	int	max_lis;
	int	i;
	int	j;

	max_lis = -1;
	i = -1;
	j = -1;
	while (in(*stack_a, ++i))
	{
		while (in(*stack_a, ++j))
			if (max_lis < in(*stack_a, j)->lis)
				max_lis = in(*stack_a, j)->lis;
		if (max_lis == in(*stack_a, i)->lis)
			break ;
	}
	j = max_lis - 1;
	while (j >= 0)
	{
		in(*stack_a, i)->lis = -1;
		i = in(*stack_a, i)->sub_index;
		j--;
	}
}

void	ft_apply_lis(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 1;
	while ((*stack_a)->h_lis != 1)
	{
		if ((*stack_a)->lis == -1)
		{
			if (i == 1)
				(*stack_a)->h_lis = 1;
			i = 0;
			rr_ab(stack_a, stack_b, 'a');
		}
		else
			p_ab(stack_a, stack_b, 'b');
	}
	ft_indexing(*stack_a);
	ft_indexing(*stack_b);
}
