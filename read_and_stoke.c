/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_stoke.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrhaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:18:45 by vrhaena           #+#    #+#             */
/*   Updated: 2020/02/24 15:33:14 by vrhaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	height = 0;
	fd = open(file_name, 0_RDONLY);
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int		get_width(char *file_name)
{
	int		fd;
	int		width;
	char	*line;

	width = 0;

