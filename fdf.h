/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrhaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:21:25 by vrhaena           #+#    #+#             */
/*   Updated: 2020/02/24 16:57:35 by vrhaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF
# define FDF

# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include "libft.h"

typedef struct		s_dot
{
	int				x;
	int				y;
	int				z_value;
	void			*mlx_ptr;
	void			*win_ptr;
	struct s_dot	*next;
}					t_dot;

#endif
