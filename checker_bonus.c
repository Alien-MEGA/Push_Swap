/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:23:40 by reben-ha          #+#    #+#             */
/*   Updated: 2023/01/24 20:12:55 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int argc, char **argv)
{
	char	*full_str;
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	if (argc < 2)
		return (0);
	i = 0;
	ft_input_manage(argc, argv, &stack_a, i);
	ft_indexing(stack_a);
	ft_check_error(stack_a);
	full_str = get_next_line(0);
	while (full_str)
	{
		ft_apply_rules(&stack_a, &stack_b, full_str);
		free(full_str);
		full_str = get_next_line(0);
	}
	ft_indexing(stack_a);
	if (ft_check_sort(&stack_a) == 1 && stack_b == NULL)
		ft_error(2);
	else
		ft_error(3);
}
