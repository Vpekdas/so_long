/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:45:12 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/03 17:23:53 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "Libft/libft.h"
# include "ft_printf/include/ft_printf.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <math.h>
# include <sys/select.h>
# include <sys/time.h>

# define SCALE 2
# define SPEED 4
# define FRAME_INTERVAL 16

typedef struct game
{
	void		*mlx;
	void		*win;
	t_img		*screen;
	t_img		*wall;
	t_img		*player;
	int			x;
	int			y;
	suseconds_t	last_frame;
	int			key_a;
	int			key_w;
	int			key_s;
	int			key_d;
	int			mouse_l;
}				t_game;

void	ft_clear_sprite(t_img *img, unsigned int color);
void	ft_draw_sprite(t_game *game, t_img *img, int x, int y);

#endif