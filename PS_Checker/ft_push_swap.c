/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:23:40 by reben-ha          #+#    #+#             */
/*   Updated: 2023/01/16 20:53:36 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*in(t_list *head, int index)
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

int	main(int argc, char **argv) // Add function to check
{
	char	*full_str;
	char	**str;
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;
	int		j;
	int		len_a;

	if (argc <= 1)
		return (1);
	i = 0;
	while (++i < argc)
	{
		full_str = ft_strjoin(full_str, argv[i]);
		full_str = ft_strjoin(full_str, " ");
	}
	i = 0;
	while (full_str[i] != '\0')
	{
		if (ft_isdigit(full_str[i]) == 0 && full_str[i] != 32
			 && !((full_str[i] == '+' || full_str[i] == '-') && ft_isdigit(full_str[i + 1]) == 1))
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	str = ft_split(full_str, ' ');
	i = -1;
	while (str[++i] != NULL)
		ft_lstadd_back(&stack_a, (ft_lstnew(ft_atoi(str[i]))));
	ft_indexing(stack_a);

	i = 0;
	len_a = 0;
	while (in(stack_a, i))
	{
		j = i + 1;
		while (in(stack_a, j))
		{
			if (in(stack_a, i)->data == in(stack_a, j)->data)
			{
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (in(stack_a, i))
	{
		if (in(stack_a, i)->data > INT_MAX)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	// start in checker
	full_str = get_next_line(0);
	// printf("\n = %s = ", full_str);
	while (full_str)
	{
		if (ft_strncmp(full_str, "pa", 2) == 0)
			p_ab(&stack_b, &stack_a);
		else if (ft_strncmp(full_str, "pb", 2) == 0)
			p_ab(&stack_a, &stack_b);
		else if (ft_strncmp(full_str, "sa", 2) == 0)
			ss_ab(stack_a, stack_b, 'a');
		else if (ft_strncmp(full_str, "sb", 2) == 0)
			ss_ab(stack_a, stack_b, 'b');
		else if (ft_strncmp(full_str, "ss", 2) == 0)
			ss_ab(stack_a, stack_b, 'X');
		else if (ft_strncmp(full_str, "ra", 2) == 0)
			rr_ab(&stack_a, &stack_b, 'a');
		else if (ft_strncmp(full_str, "rb", 2) == 0)
			rr_ab(&stack_a, &stack_b, 'b');
		else if (ft_strncmp(full_str, "rr", 2) == 0)
			rr_ab(&stack_a, &stack_b, 'X');
		else if (ft_strncmp(full_str, "rra", 3) == 0)
			rrr_ab(&stack_a, &stack_b, 'a');
		else if (ft_strncmp(full_str, "rrb", 3) == 0)
			rrr_ab(&stack_a, &stack_b, 'b');
		else if (ft_strncmp(full_str, "rrr", 3) == 0)
			rrr_ab(&stack_a, &stack_b, 'X');
		else
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		full_str = get_next_line(0);
	}
	ft_indexing(stack_a);
	i = 0;
	while (in(stack_a, i)->next)
	{
		// printf("== %ld > %ld\n", in(stack_a, i)->data , in(stack_a, (i + 1))->data);
		if (in(stack_a, i) > in(stack_a, (i + 1)))
		{
			write(2, "KO\n", 3);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	write(2, "OK\n", 3);
	exit(EXIT_SUCCESS);
}
