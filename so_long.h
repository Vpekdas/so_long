/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:45:12 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/19 16:22:01 by vopekdas         ###   ########.fr       */
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
# define WINDOWS_WIDTH 1920
# define WINDOWS_HEIGHT 480

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
	t_img	*bomb;
	t_img	*door;
	t_img	*background;
	t_img	*background2;
	t_img	*water;
	t_img	*foreground;
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

typedef struct s_anim
{
	t_img		**img;
	suseconds_t	current_frame;
	suseconds_t	last_frame;
	int			anim_index;
	int			frame;
	int			frame_count;
}				t_anim;

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
	int		health;
	bool	invulnerable;
	suseconds_t	last_frame;
}			t_player;

typedef struct s_enemy
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
	int		health;
	bool	invulnerable;
	suseconds_t	last_frame;
}				t_enemy;

typedef struct bomb
{
	int		speed;
	int		pos_x;
	int		pos_y;
	int		height;
	int		width;
	int		bomb_number;
	bool	direction;
}				t_bomb;

typedef struct s_box
{
	int	pos_x;
	int	pos_y;
	int	width;
	int	height;
}		t_box;

typedef struct s_draw_info
{
	int		x;
	int		y;
	bool	flipped;
}			t_draw_info;

typedef struct s_trgb
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	t;
}	t_trgb;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_img			*screen;
	t_sprite		sprite;
	t_player		player;
	t_enemy			enemy;
	t_bomb			bomb;
	t_img			door;
	t_anim			anim;
	t_anim			anim_player_run;
	t_anim			anim_player_jump;
	t_anim			anim_player_fall;
	t_anim			anim_player_hit;
	t_anim			anim_enemy_idle;
	t_anim			anim_enemy_attack;
	t_anim			anim_bomb_on;
	t_anim			collectible;
	t_draw_info		draw_info;
	t_draw_info		draw_info_enemy;
	t_draw_info		draw_info_bomb;
	int				key_a;
	int				key_w;
	int				key_s;
	int				key_d;
	int				key_space;
	char			**map;
	int				map_width;
	int				map_height;
	int				collectibles_numbers;
	int				bg1_scroll;
	int				bg2_scroll;
	int				water_scroll;
	int				fg_scroll;
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
void		draw_tile(t_game *g, char **m, int x, int y);
t_box		player_box_x_y_off(t_game	*game, float velocity_x, float velocity_y);
t_box	player_box_x_y_off_below(t_game	*game);
void		collide_with_collectible(t_box player, t_game *game);
int		find_collectible_numbers(t_game *game, char **map);
void	collide_with_exit_chest(t_box player, t_game *game);
void	draw_collectible(t_game *g, int x, int y);
void	draw_door(t_game *g, int x, int y);
void	draw_background(t_game *game);
t_box	player_box_x_y(t_game *game);
t_box	player_box_stop_scrolling_left(t_game	*game);
t_box	player_box_stop_scrolling_right(t_game	*game);
void	draw_background_sprite(t_game *game, t_img *img, int scroll);
void	draw_vignette(t_game *game);
void	draw_anim_player(t_game *game, t_anim *anim);
void	draw_sprite_player(t_game *game, t_img *img, t_draw_info draw_info);
void	update_anim_player(t_game *game);
void	update_anim_collectible(char **map, t_game *game);
void	shoot_bomb(t_game *game);
void	update_bomb(t_game *game);
t_box	bomb_box(t_game *game);
void	draw_chest(t_game *game, int x, int y);
void	find_player_position(t_game *game, char **map);
void	find_enemy_position(t_game *game, char **map);
void	update_anim_enemy(t_game *game);
void	move_enemy(t_game *game);
t_box	enemy_box_y_off(t_game *game, float velocity_y);
#endif