/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_stoke.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrhaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:18:45 by vrhaena           #+#    #+#             */
/*   Updated: 2020/02/25 18:06:17 by vrhaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		wrdcounter(char *str, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i])
			words++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (words);
}

int		get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	height = 0;
	if ((fd = open(file_name, O_RDWR)) < 0)
	{
		ft_putstr("it's not a file");
		return (0);
	}
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

	fd = open(file_name, O_RDONLY);
	get_next_line(fd, &line);
	width = wrdcounter(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	fill_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

	i = 0;
	nums = ft_strsplit(line, ' ');
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	ft_strdel(nums);
}

void	read_file(char *file_name, t_data *data)
{
	int		fd;
	char	*line;
	int		i;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	if (!(data->z_matrix = (int**)malloc(sizeof(int*) * (data->height + 1))))
		exit(12);
	i = 0;
	while (i <= data->height)
	{
		if (!(data->z_matrix[i++] = (int*)malloc(sizeof(int) * (data->width + 1))))
			exit(12);
	}
	fd = open(file_name, O_RDONLY);
		ft_putstr("it's not a file");
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	data->z_matrix[i] = NULL;
	close(fd);
}
