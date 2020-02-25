/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjada <mjada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:52:27 by mjada             #+#    #+#             */
/*   Updated: 2020/02/25 13:00:52 by vrhaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

static int		strline(char **str, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*str)[len] != '\n' && (*str)[len])
		len++;
	if ((*str)[len] == '\n')
	{
		*line = ft_strsub(*str, 0, len);
		tmp = ft_strdup(*str + len + 1);
		free(*str);
		*str = tmp;
		if ((*str)[0] == '\0')
			ft_strdel(str);
	}
	else
	{
		*line = ft_strdup(*str);
		ft_strdel(str);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*stc[MAX_FD];
	char		bs[BUFF_SIZE + 1];
	char		*tmp;
	int			r;

	if (fd < 0 || !line)
		return (-1);
	while ((r = read(fd, bs, BUFF_SIZE)) > 0)
	{
		bs[r] = '\0';
		if (stc[fd] == NULL)
			stc[fd] = ft_strdup(bs);
		else
		{
			tmp = ft_strjoin(stc[fd], bs);
			free(stc[fd]);
			stc[fd] = tmp;
		}
		if (ft_strchr(stc[fd], '\n'))
			break ;
	}
	if (r < 0 || stc[fd] == NULL)
		return (r < 0 ? -1 : 0);
	return (strline(&stc[fd], line));
}
