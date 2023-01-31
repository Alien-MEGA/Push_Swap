/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_two_mand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:35:35 by reben-ha          #+#    #+#             */
/*   Updated: 2023/01/24 18:46:11 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_check_error_str(int i, char *full_str)
{
	i = -1;
	while (full_str[++i] != '\0')
		if (ft_isdigit(full_str[i]) == 0 && full_str[i] != 32
			&& !((full_str[i] == '+' || full_str[i] == '-')
				&& ft_isdigit(full_str[i + 1]) == 1))
			ft_error();
	i = -1;
	while (full_str[++i] != '\0')
		if (ft_isdigit(full_str[i]) == 1
			&& (full_str[i + 1] == '-' || full_str[i + 1] == '+'))
			ft_error();
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
				ft_error();
			j++;
		}
		i++;
	}
	i = -1;
	while (in(stack_a, ++i))
		if (in(stack_a, i)->data > INT_MAX || in(stack_a, i)->data < INT_MIN)
			ft_error();
}
