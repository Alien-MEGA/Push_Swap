/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_two_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:54:53 by reben-ha          #+#    #+#             */
/*   Updated: 2023/01/20 23:56:54 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static void	ft_check_error_str(int i, char *full_str)
{
	i = -1;
	while (full_str[++i] != '\0')
		if (ft_isdigit(full_str[i]) == 0 && full_str[i] != 32
			&& !((full_str[i] == '+' || full_str[i] == '-')
				&& ft_isdigit(full_str[i + 1]) == 1))
			ft_error(1);
	i = -1;
	while (full_str[++i] != '\0')
		if (ft_isdigit(full_str[i]) == 1
			&& (full_str[i + 1] == '-' || full_str[i + 1] == '+'))
			ft_error(1);
}

void	ft_input_manage(int argc, char **argv, t_list **stack_a, int i)
{
	char	**str;
	char	*full_str;

	full_str = NULL;
	while (++i < argc)
	{
		full_str = ft_strjoin(full_str, argv[i]);
		full_str = ft_strjoin(full_str, " ");
	}
	ft_check_error_str(i, full_str);
	str = ft_split(full_str, ' ');
	i = -1;
	while (str[++i] != NULL)
		ft_lstadd_back(stack_a, (ft_lstnew(ft_atoi(str[i]))));
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	ft_check_error(t_list *stack_a)
{
	int	len_a;
	int	i;
	int	j;

	i = 0;
	len_a = 0;
	while (in(stack_a, i))
	{
		j = i + 1;
		while (in(stack_a, j))
		{
			if (in(stack_a, i)->data == in(stack_a, j)->data)
				ft_error(1);
			j++;
		}
		i++;
	}
	i = -1;
	while (in(stack_a, ++i))
		if (in(stack_a, i)->data > INT_MAX || in(stack_a, i)->data < INT_MIN)
			ft_error(1);
}

void	ft_apply_rules(t_list **stack_a, t_list **stack_b, char *full_str)
{
	if (ft_strncmp(full_str, "pa\n", 3) == 0)
		p_ab(stack_b, stack_a);
	else if (ft_strncmp(full_str, "pb\n", 3) == 0)
		p_ab(stack_a, stack_b);
	else if (ft_strncmp(full_str, "sa\n", 3) == 0)
		ss_ab((*stack_a), (*stack_b), 'a');
	else if (ft_strncmp(full_str, "sb\n", 3) == 0)
		ss_ab((*stack_a), (*stack_b), 'b');
	else if (ft_strncmp(full_str, "ss\n", 3) == 0)
		ss_ab((*stack_a), (*stack_b), 'X');
	else if (ft_strncmp(full_str, "ra\n", 3) == 0)
		rr_ab(stack_a, stack_b, 'a');
	else if (ft_strncmp(full_str, "rb\n", 3) == 0)
		rr_ab(stack_a, stack_b, 'b');
	else if (ft_strncmp(full_str, "rr\n", 3) == 0)
		rr_ab(stack_a, stack_b, 'X');
	else if (ft_strncmp(full_str, "rra\n", 4) == 0)
		rrr_ab(stack_a, stack_b, 'a');
	else if (ft_strncmp(full_str, "rrb\n", 4) == 0)
		rrr_ab(stack_a, stack_b, 'b');
	else if (ft_strncmp(full_str, "rrr\n", 4) == 0)
		rrr_ab(stack_a, stack_b, 'X');
	else
		ft_error(1);
}
