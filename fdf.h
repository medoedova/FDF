/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrhaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:21:25 by vrhaena           #+#    #+#             */
/*   Updated: 2020/02/25 13:56:00 by vrhaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF
# define FDF

# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include "libft/libft.h"

# define MAX(a, b) (a > b) ? a : b
# define ABS(a) ((a < 0) ? -a : a)

typedef struct		s_data
{
	int				width;
	int				height;
	int				**z_matrix;
	int				zoom;
	int				color;
	void			*mlx_ptr;
	void			*win_ptr;
}					t_data;

void				read_file(char *file_name, t_data *data);
int					wrdcounter(char *str, char c);
int					get_width(char *file_name);
int					get_height(char *file_name);
void				fill_matrix(int *z_line, char *line);
void				draw_line(float x, float y, float x1, float y1, t_data *data);
void				draw(t_data *data);
void				isometric(float *x, float *y, int z);


#endif
