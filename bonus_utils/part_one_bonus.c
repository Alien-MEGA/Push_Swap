/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_one_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:54:58 by reben-ha          #+#    #+#             */
/*   Updated: 2023/01/23 21:45:04 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

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

int	ft_check_sort(t_list **stack_a)
{
	int	i;

	if (!stack_a)
		return (0);
	if (!(*stack_a))
		return (0);
	i = 0;
	while (in(*stack_a, i)->next != NULL)
	{
		if (in(*stack_a, i)->data > in(*stack_a, (i + 1))->data)
			return (0);
		i++;
	}
	return (1);
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

void	ft_error(int option)
{
	if (option == 1)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	else if (option == 2)
	{
		write(1, "OK\n", 3);
		exit(EXIT_SUCCESS);
	}
	else if (option == 3)
	{
		write(2, "KO\n", 3);
		exit(EXIT_FAILURE);
	}
}
