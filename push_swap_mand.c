/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_mand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:23:40 by reben-ha          #+#    #+#             */
/*   Updated: 2023/01/24 20:05:28 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	i = 0;
	if (argc < 2)
		return (0);
	ft_input_manage(argc, argv, &stack_a, i);
	ft_indexing(stack_a);
	ft_check_error(stack_a);
	if (ft_check_sort(&stack_a) == 1)
		exit(EXIT_SUCCESS);
	if (ft_lstsize(stack_a) <= 5)
		ft_five_numbers(&stack_a, &stack_b);
	else
	{
		ft_find_lis(&stack_a);
		ft_part_find_lis(&stack_a);
		ft_apply_lis(&stack_a, &stack_b);
		ft_apply_instra(&stack_a, &stack_b);
	}
	ft_lstclear(&stack_a);
	return (0);
}
