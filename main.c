/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrhaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:56:19 by vrhaena           #+#    #+#             */
/*   Updated: 2020/02/24 22:04:18 by mjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//int	deal_key(int key, t_data *data)
//{
//	ft_printf("%d\n", key);
//
//	if (key == 126)
//		data->shift_y -= 10;
//	if (key == 125)
//		data->shift_y += 10;
//	if (key == 123)
//		 data->shift_x -= 10;
//	if (key == 124)
//		data->shift_x += 10;
//	mlx_clear_window(data->mlx_ptr, data->win_ptr);
//	draw(data);
//	return (0);
//}

int		main(int argc, char **argv)
{
	t_data *new;
	
	if (argc != 2)
	{
		ft_putstr("usage: ./fdf <file_name>");
	}
	new = (t_data*)malloc(sizeof(t_data));
	read_file(argv[1], new);
	new->mlx_ptr = mlx_init();
	new->win_ptr = mlx_new_window(new->mlx_ptr, 1000, 1000, "FDF");
	new->zoom = 20;
	draw(new);
//	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(new->mlx_ptr);
}
