/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjada <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 03:17:41 by mjada             #+#    #+#             */
/*   Updated: 2019/09/27 19:55:42 by mjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long int	res;
	int			sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' ||
			*str == '\r' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str <= '9' && *str >= '0')
	{
		res = 10 * res + sign * (*str - '0');
		if (sign == 1 && res < 0)
			return (-1);
		if (sign == -1 && res > 0)
			return (0);
		str++;
	}
	return (res);
}
