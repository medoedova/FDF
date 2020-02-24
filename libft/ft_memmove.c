/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjada <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 21:19:55 by mjada             #+#    #+#             */
/*   Updated: 2019/09/27 19:37:59 by mjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int				i;
	unsigned char	*d;
	const char		*s;

	i = 0;
	d = (unsigned char *)dst;
	s = (const char *)src;
	if (!dst && !src)
		return (NULL);
	if (dst > src && dst && src)
	{
		while (len > 0)
		{
			d[len - 1] = (char)s[len - 1];
			len--;
		}
	}
	else
		while (i < (int)len)
		{
			d[i] = s[i];
			i++;
		}
	return (dst);
}
