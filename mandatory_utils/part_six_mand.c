/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_six_mand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:23:28 by reben-ha          #+#    #+#             */
/*   Updated: 2023/01/24 18:45:56 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra_zayda(t_list **target)
{
	(*target)->instr_s += 0;
	(*target)->sub_index = 0;
}

void	ft_two_numbers(t_list **stack_a)
{
	if (in(*stack_a, 0)->data > in(*stack_a, 1)->data)
		ss_ab(*stack_a, NULL, 'a');
}

void	ft_three_numbers(t_list **stack_a)
{
	if (ft_lstsize(*stack_a) == 2)
		ft_two_numbers(stack_a);
	while (ft_check_sort(stack_a) == 0)
	{
		if ((in(*stack_a, 0)->data > in(*stack_a, 1)->data)
			&& (in(*stack_a, 0)->data > in(*stack_a, 2)->data))
			rr_ab(stack_a, NULL, 'a');
		else if (in(*stack_a, 0)->data > in(*stack_a, 1)->data)
			ss_ab(*stack_a, NULL, 'a');
		else if ((in(*stack_a, 0)->data < in(*stack_a, 1)->data)
			&& (in(*stack_a, 0)->data < in(*stack_a, 2)->data))
			rrr_ab(stack_a, NULL, 'a');
		else if (in(*stack_a, 1)->data > in(*stack_a, 2)->data)
			rr_ab(stack_a, NULL, 'a');
		ft_indexing(*stack_a);
	}
}

void	ft_four_numbers(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 3)
		return (ft_three_numbers(stack_a));
	p_ab(stack_a, stack_b, 'b');
	ft_indexing(*stack_a);
	ft_indexing(*stack_b);
	ft_three_numbers(stack_a);
	ft_apply_instra(stack_a, stack_b);
}

void	ft_five_numbers(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 4)
		return (ft_four_numbers(stack_a, stack_b));
	p_ab(stack_a, stack_b, 'b');
	ft_four_numbers(stack_a, stack_b);
}
