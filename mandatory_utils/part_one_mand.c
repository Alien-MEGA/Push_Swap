/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_one_mand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:32:16 by reben-ha          #+#    #+#             */
/*   Updated: 2023/01/19 22:57:08 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*in(t_list *head, int index)
{
	while (head)
	{
		if (head->index == index)
			return (head);
		head = head->next;
	}
	return (NULL);
}

void	ft_indexing(t_list *stack_a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		stack_a->index = i;
		stack_a->sub_index = -1;
		stack_a->lis = 1;
		stack_a->h_lis = 0;
		stack_a->instr_s = 1;
		i++;
		stack_a = stack_a->next;
	}
}

int	ft_check_sort(t_list **stack_a)
{
	int	i;

	i = 0;
	while (in(*stack_a, i)->next != NULL)
	{
		if (in(*stack_a, i)->data > in(*stack_a, (i + 1))->data)
			return (0);
		i++;
	}
	return (1);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
