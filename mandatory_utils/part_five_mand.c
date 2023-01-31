/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_five_mand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:39:10 by reben-ha          #+#    #+#             */
/*   Updated: 2023/01/24 18:41:43 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_one_side(t_list **stack_a, t_list **stack_b,
			t_list *target, t_list *position)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize((*stack_a));
	len_b = ft_lstsize((*stack_b));
	if ((target->index <= (len_b / 2)) && (position->index <= (len_a / 2)))
		while (!((*stack_b)->data == target->data)
			&& !((*stack_a)->data == position->data))
			rr_ab(stack_a, stack_b, 'X');
	else if ((target->index > (len_b / 2))
		&& (position->index > (len_a / 2)))
		while (!((*stack_b)->data == target->data)
			&& !((*stack_a)->data == position->data))
			rrr_ab(stack_a, stack_b, 'X');
}

static void	ft_make_it_first_t(t_list **stack_b, t_list *target)
{
	int	len_b;

	len_b = ft_lstsize((*stack_b));
	if ((target->index <= (len_b / 2)))
		while (!((*stack_b)->data == target->data))
			rr_ab(NULL, stack_b, 'b');
	else if ((target->index > (len_b / 2)))
		while (!((*stack_b)->data == target->data))
			rrr_ab(NULL, stack_b, 'b');
}

static void	ft_make_it_first_p(t_list **stack_a, t_list *target, t_list *pos)
{
	int	len_a;

	len_a = ft_lstsize((*stack_a));
	if ((pos->index <= (len_a / 2)))
		while (!((*stack_a)->data == pos->data))
			rr_ab(stack_a, NULL, 'a');
	else if ((pos->index > (len_a / 2)))
	{
		while (!((*stack_a)->data == pos->data))
		{
			if (ft_lstlast((*stack_a))->data == pos->data
				&& target->data > pos->data)
				break ;
			rrr_ab(stack_a, NULL, 'a');
		}
	}
}

void	ft_lamsa(t_list **stack_a)
{
	t_list	*target;
	int		len_a;
	int		i;

	target = (*stack_a);
	i = -1;
	while (in((*stack_a), ++i))
		if (target->data > in((*stack_a), i)->data)
			target = in((*stack_a), i);
	target->h_lis = 1;
	len_a = ft_lstsize((*stack_a));
	if (target->index <= (len_a / 2))
		while (!((*stack_a)->h_lis == 1))
			rr_ab(stack_a, NULL, 'a');
	else if (target->index > (len_a / 2))
		while (!((*stack_a)->h_lis == 1))
			rrr_ab(stack_a, NULL, 'a');
}

void	ft_apply_instra(t_list **stack_a, t_list **stack_b)
{
	t_list	*target;
	t_list	*position;
	int		j;

	while ((*stack_b))
	{
		ft_indexing((*stack_a));
		ft_indexing((*stack_b));
		ft_instra(stack_a, stack_b);
		target = (*stack_b);
		j = -1;
		while (in((*stack_b), ++j))
			if (target->instr_s > in((*stack_b), j)->instr_s)
				target = in((*stack_b), j);
		position = in((*stack_a), (target->sub_index));
		ft_one_side(stack_a, stack_b, target, position);
		ft_make_it_first_t(stack_b, target);
		ft_make_it_first_p(stack_a, target, position);
		if (((*stack_a)->data == position->data)
			&& (target->data > position->data))
			rr_ab(stack_a, stack_b, 'a');
		p_ab(stack_b, stack_a, 'a');
	}
	ft_indexing((*stack_a));
	ft_lamsa(stack_a);
}
