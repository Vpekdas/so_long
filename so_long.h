/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:45:12 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/11 16:56:44 by vopekdas         ###   ########.fr       */
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

// enum
// {
// 	SP_PLAYER,
// 	SP_BOTLEFT,
// 	SP_BOTRIGHT,
// 	SP_BOT,
// 	SP_MAX,
// };

// t_img	*imgs[SP_MAX];
// imgs[SP_PLAYER] = mlx_load_xpm_to_image(...);
// imgs[SP_BOTLEFT] = mlx_load_xpm_to_image(...);


typedef struct s_sprite
{
	t_img	*player;
	t_img	*collectible;
	t_img	*door;
	t_img	*background;
	t_img	*bot_left;
	t_img	*bot_right;
	t_img	*bot_tl;
	t_img	*bot;
	t_img	*br_left;
	t_img	*br_mid;
	t_img	*br_right;
	t_img	*left;
	t_img	*mid_tl;
	t_img	*mid;
	t_img	*right;
	t_img	*tl;
	t_img	*top_left;
	t_img	*top_right;
	t_img	*top;
}			t_sprite;

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	int		width;
	int		height;
	int		offset_x;
	int		offset_y;
	float	velocity_x;
	float	velocity_y;
	bool	already_jumped;
}				t_player;

typedef struct s_box
{
	int	pos_x;
	int	pos_y;
	int	width;
	int	height;
}	t_box;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_img			*screen;
	t_sprite		sprite;
	t_player		player;
	suseconds_t		last_frame;
	int				key_a;
	int				key_w;
	int				key_s;
	int				key_d;
	char			**map;
	int				map_width;
	int				map_height;
	int				collectibles_numbers;
}					t_game;

t_box		player_box_x_off(t_game *game, float vx);
t_box		player_box_y_off(t_game *game, float vy);
t_box		map_box_scale(int x, int y);
bool		collide(t_box player, t_box object);
bool		collide_with_map(t_box a, t_game *game);
void		move_player(t_game *game, float vx, float vy);
suseconds_t	getms(void);
int			key_pressed(int keycode, t_game *game);
int			key_released(int keycode, t_game *game);
void		detect_key(t_game *game);
int			close_game(t_game *game);
void		init_player_and_map(t_game *game);
char		*gnl(char **line, int fd);
char		**parse_map(t_game *game, char *path);
int			print_map(char **map, t_game *game);
void		clear_sprite(t_img *img, unsigned int color);
void		draw_sprite(t_game *game, t_img *img, int x, int y);
void		init_sprite(t_game *g);
bool		isg(t_game *game, char **map, int x, int y);
int			update(t_game *game);
bool		isg(t_game *game, char **map, int x, int y);
void		print_tile(t_game *g, char **m, int x, int y);
t_box		player_box_x_y_off(t_game	*game, float velocity_x, float velocity_y);
t_box	player_box_x_y_off_below(t_game	*game);
void		collide_with_collectible(t_box player, t_game *game);
int	find_collectible_numbers(t_game *game, char **map);
void	collide_with_exit_door(t_box player, t_game *game);

#endif