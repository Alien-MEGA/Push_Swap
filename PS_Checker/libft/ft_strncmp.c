/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:20:23 by reben-ha          #+#    #+#             */
/*   Updated: 2023/01/16 20:38:12 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../push_swap.h"
#include <stdio.h>

int	ft_strncmp(const char *str1, const char *str2, size_t size)
{
	size_t			i;
	unsigned char	*s1x;
	unsigned char	*s2x;

	s1x = (unsigned char *)str1;
	s2x = (unsigned char *)str2;
	i = 0;
	while (i < size && (s1x[i] != '\0' || s2x[i] != '\0'))
	{
		if (s1x[i] != s2x[i])
			return (s1x[i] - s2x[i]);
		i++;
	}
	return (0);
}
