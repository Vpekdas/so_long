/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:45:12 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/07 17:38:06 by vopekdas         ###   ########.fr       */
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
#include <stdio.h>

# define SCALE 2
# define SPEED 8
# define FRAME_INTERVAL 16

typedef struct sprite
{
	t_img	*player;
	t_img	*top_left;
	t_img	*top;
	t_img	*top_right;
	t_img	*left;
	t_img	*mid;
	t_img	*right;
	t_img	*bot_left;
	t_img	*bot;
	t_img	*bot_right;
	t_img	*tl;
	t_img	*mid_tl;
	t_img	*bot_tl;
}			t_sprite;

typedef struct player
{
	int		x;
	int		y;
	int		w;
	int		h;
	int		ox;
	int		oy;
	float	vx;
	float	vy;
	bool	already_jumped;
}				t_player;

typedef struct s_box
{
	int	x;
	int	y;
	int	w;
	int	h;
}	t_box;

typedef struct game
{
	void		*mlx;
	void		*win;
	t_sprite	spr;
	t_player	player;
	suseconds_t	last_frame;
	int			key_a;
	int			key_w;
	int			key_s;
	int			key_d;
	int			mouse_l;
	t_img		*screen;
	char		**map;
	int			map_width;
	int			map_height;
}				t_game;

bool		ft_collide(t_box a, t_box b);
bool		ft_collide_with_map(t_box a, t_game *game);
int			ft_key_pressed(int keycode, t_game *game);
int			ft_key_released(int keycode, t_game *game);
suseconds_t	ft_getms(void);
int			ft_close(t_game *game);
void		ft_move_player(t_game *game, float vx, float vy);
int			ft_update(t_game *game);
char		*ft_gnl(char **line, int fd);
char		**ft_parse_map(t_game *game, char *path);
int			ft_print_map(char **map, t_game *game);
void		ft_clear_sprite(t_img *img, unsigned int color);
void		ft_draw_sprite(t_game *game, t_img *img, int x, int y);
bool		isg(t_game *game, char **map, int x, int y);
void		ft_print_tile(t_game *g, char **m, int x, int y);
void		ft_init_sprite(t_game *game);
void		ft_detect_key(t_game *game);
#endif