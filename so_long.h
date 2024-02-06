/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:45:12 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/06 16:03:40 by vopekdas         ###   ########.fr       */
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
# include <stdbool.h>

# define SCALE 2
# define SPEED 4
# define FRAME_INTERVAL 16

typedef struct game
{
	void		*mlx;
	void		*win;
	suseconds_t	last_frame;
	int			key_a;
	int			key_w;
	int			key_s;
	int			key_d;
	int			mouse_l;
	t_img		*screen;
	t_img		*player;
	t_img		*top_left;
	t_img		*top;
	t_img		*top_right;
	t_img		*left;
	t_img		*mid;
	t_img		*right;
	t_img		*bot_left;
	t_img		*bot;
	t_img		*bot_right;
	t_img		*tl;
	t_img		*mid_tl;
	t_img		*bot_tl;
	char		**map;
	int			map_width;
	int			map_height;

	int			x;
	int			y;
	int			w;
	int			h;
	int			ox;
	int			oy;
}				t_game;

typedef struct s_box
{
	int	x;
	int	y;
	int	w;
	int	h;
}	t_box;

char	*ft_gnl(char **line, int fd);
char	**ft_parse_map(t_game *game, char *path);
int		ft_print_map(char **map, t_game *game);

void	ft_clear_sprite(t_img *img, unsigned int color);
void	ft_draw_sprite(t_game *game, t_img *img, int x, int y);
void	ft_print_tile(t_game *game, char **map, int x, int y);

bool	ft_collide(t_box a, t_box b);
bool	ft_collide_with_map(t_box a, t_game *game);

#endif