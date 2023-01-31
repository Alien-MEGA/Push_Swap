/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_four_mand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 23:27:54 by reben-ha          #+#    #+#             */
/*   Updated: 2023/01/23 19:23:56 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_list	*m_m(t_list **stack_a, int option)
{
	t_list	*max_n;
	t_list	*min_n;
	int		i;

	i = 0;
	max_n = (*stack_a);
	min_n = (*stack_a);
	while (in((*stack_a), i))
	{
		if (max_n->data < in((*stack_a), i)->data)
			max_n = in((*stack_a), i);
		if (min_n->data > in((*stack_a), i)->data)
			min_n = in((*stack_a), i);
		i++;
	}
	if (option == 'M')
		return (max_n);
	else if (option == 'm')
		return (min_n);
	return (NULL);
}

static void	ft_taget_bs_mm(t_list **stack_a, t_list **target,
							int len_a, int option)
{
	if (option == 'm')
	{
		if (m_m(stack_a, 'm')->index <= (len_a / 2))
			(*target)->instr_s += (m_m(stack_a, 'm')->index);
		else if (m_m(stack_a, 'm')->index > (len_a / 2))
			(*target)->instr_s += (len_a - (m_m(stack_a, 'm')->index + 1)) + 1;
		(*target)->sub_index = m_m(stack_a, 'm')->index;
	}
	else if (option == 'M')
	{
		if (m_m(stack_a, 'M')->index <= (len_a / 2))
			(*target)->instr_s += (m_m(stack_a, 'M')->index) + 1;
		else if (m_m(stack_a, 'M')->index > (len_a / 2))
			(*target)->instr_s += (len_a - (m_m(stack_a, 'M')->index)) - 1;
		(*target)->sub_index = m_m(stack_a, 'M')->index;
	}
}

static void	ft_other_case(t_list **stack_a, t_list **target, int len_a)
{
	t_list	*min_max_n;
	t_list	*tmp;
	int		i;

	i = -1;
	min_max_n = ft_lstnew(INT_MAX);
	tmp = min_max_n;
	while (in((*stack_a), ++i)->next)
		if ((*target)->data > in((*stack_a), i)->data
			&& (*target)->data < in((*stack_a), (i + 1))->data)
			min_max_n = in((*stack_a), (i + 1));
	if (min_max_n->index <= (len_a / 2))
		(*target)->instr_s += (min_max_n->index);
	else if (min_max_n->index > (len_a / 2))
		(*target)->instr_s += (len_a - (min_max_n->index + 1)) + 1;
	(*target)->sub_index = min_max_n->index;
	free(tmp);
}

static void	ft_one_side_instra(t_list **stack_a, t_list **target,
									int len_a, int len_b)
{
	t_list	*position;
	int		moves_b;
	int		moves_a;

	moves_a = (*target)->instr_s;
	if ((*target)->index <= (len_b / 2))
		(*target)->instr_s += (*target)->index;
	else if ((*target)->index > (len_b / 2))
		(*target)->instr_s += (len_b - (*target)->index);
	moves_b = ((*target)->instr_s - moves_a);
	position = in((*stack_a), ((*target)->sub_index));
	if (((*target)->index <= (len_b / 2) && position->index <= (len_a / 2))
		|| ((*target)->index > (len_b / 2) && position->index > (len_a / 2)))
	{
		if (moves_a > moves_b)
			(*target)->instr_s = moves_a;
		else
			(*target)->instr_s = moves_b;
	}
}

void	ft_instra(t_list **stack_a, t_list **stack_b)
{
	t_list	*target;
	int		j;
	int		len_a;
	int		len_b;

	j = -1;
	len_a = ft_lstsize((*stack_a));
	len_b = ft_lstsize((*stack_b));
	while (in((*stack_b), ++j))
	{
		target = in((*stack_b), j);
		if (target->data > ft_lstlast((*stack_a))->data
			&& target->data < (*stack_a)->data)
			ra_zayda(&target);
		else if (target->data < m_m(stack_a, 'm')->data)
			ft_taget_bs_mm(stack_a, &target, len_a, 'm');
		else if (target->data > m_m(stack_a, 'M')->data)
			ft_taget_bs_mm(stack_a, &target, len_a, 'M');
		else
			ft_other_case(stack_a, &target, len_a);
		ft_one_side_instra(stack_a, &target, len_a, len_b);
	}
}
