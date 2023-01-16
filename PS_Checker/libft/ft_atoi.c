/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:42:01 by reben-ha          #+#    #+#             */
/*   Updated: 2023/01/16 20:38:08 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static long	result(const char *str, int i, int sg)
{
	long	nb;

	nb = 0;
	while (ft_isdigit(str[i]))
	{
		nb = nb * 10 + (((long)str[i]) - 48);
		i++;
	}
	return (nb * sg);
}

long	ft_atoi(const char *str)
{
	int	i;
	int	sg;

	sg = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sg = -1;
		i++;
	}
	return (result(str, i, sg));
}
