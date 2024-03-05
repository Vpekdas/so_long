/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:45:12 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/05 16:03:24 by vopekdas         ###   ########.fr       */
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
# include <stdio.h>
// TODO: remove stdio
# include <stdint.h>

# ifndef BONUS
#  define BONUS 0
# endif

# define SCALE 2
# define SPEED 8
# define FRAME_INTERVAL 16
# define WIN_W 1920
# define WIN_H 480

typedef struct s_xorshift32_state
{
	uint32_t	a;
}		t_xorshift32_state;

typedef enum e_sprite
{
	TL,
	TOP,
	TOP_LEFT,
	TOP_RIGHT,
	LEFT,
	MID,
	RIGHT,
	BOT_LEFT,
	BOT,
	BOT_RIGHT,
	MID_TL,
	BOT_TL,
	BACKGROUND,
	BACKGROUND2,
	WATER,
	FOREGROUND,
	DOOR,
	DOOR_OPEN,
	BOMB,
	NUM_SPRITES
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
	int			x;
	int			y;
	int			width;
	int			height;
	int			offset_x;
	int			offset_y;
	float		velocity_x;
	float		velocity_y;
	bool		already_jumped;
	int			health;
	bool		invulnerable;
	suseconds_t	last_frame;
}			t_player;

typedef struct s_enemy
{
	int			pos_x;
	int			pos_y;
	int			width;
	int			height;
	int			offset_x;
	int			offset_y;
	float		velocity_x;
	float		velocity_y;
	bool		already_jumped;
	int			health;
	bool		invulnerable;
	suseconds_t	last_frame;
	int			number;
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

typedef struct s_trgb
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	t;
}	t_trgb;

typedef struct s_vignette
{
	int		si;
	int		sj;
	float	ri;
	float	rj;
}			t_vignette;

typedef struct s_draw_info
{
	int		x;
	int		y;
	bool	flip;
	t_trgb	color;
}			t_draw_info;

typedef struct s_pathfinding
{
	int	pos_x;
	int	pos_y;
}				t_pathfinding;

typedef struct s_node
{
	int				pos_x;
	int				pos_y;
	struct s_node	*next;
}				t_node;

typedef struct s_character_map
{
	int	collectible_nb;
	int	exit_nb;
	int	player_nb;
	int	enemy_nb;
}				t_character_map;

typedef struct s_map_copy
{
	char	**map;
	int		map_width;
	int		map_height;
}				t_map_copy;

typedef struct s_node_bubble
{
	int						pos_x;
	int						pos_y;
	float					velocity_y;
	struct s_node_bubble	*next;
}				t_node_bubble;

typedef struct s_game
{
	void				*mlx;
	void				*win;
	t_img				*screen;
	t_img				**sprites;
	char				*map_path;
	t_xorshift32_state	*state;
	t_vignette			vignette;
	t_player			play;
	t_enemy				enemy;
	t_bomb				bomb;
	int					move_count;
	t_node_bubble		*bubble_list;
	t_node				*collectible_list;
	t_anim				player_idle;
	t_anim				player_run;
	t_anim				player_jump;
	t_anim				player_fall;
	t_anim				player_hit;
	t_anim				enemy_idle;
	t_anim				enemy_attack;
	t_anim				bomb_on;
	t_anim				collectible;
	t_anim				bubble;
	t_anim				trail;
	bool				is_trail_drawn;
	t_draw_info			draw_info;
	t_draw_info			draw_info_enemy;
	t_draw_info			draw_info_bomb;
	t_pathfinding		**collectible_pos;
	t_pathfinding		pathfinding;
	t_character_map		character_map;
	t_map_copy			map_copy;
	int					key_a;
	int					key_w;
	int					key_s;
	int					key_d;
	int					key_space;
	int					key_esc;
	char				**map;
	int					map_width;
	int					map_height;
	int					collectibles_numbers;
	int					bg1_scroll;
	int					bg2_scroll;
	int					water_scroll;
	int					fg_scroll;
	int					accessible_collectibles;
	int					accessible_door;
	int					max_jump;
}						t_game;

t_box			player_box_x_off(t_game *game, float vx);
t_box			player_box_y_off(t_game *game, float vy);
t_box			map_box_scale(int x, int y);
bool			collide(t_box player, t_box object);
bool			collide_with_map(t_box a, t_game *game);
void			move_player(t_game *game, float vx, float vy);
suseconds_t		getms(void);
int				key_pressed(int keycode, t_game *game);
int				key_released(int keycode, t_game *game);
void			detect_key(t_game *game);
int				close_game(t_game *game);
int				init_player_and_map(t_game *game);
char			*gnl(char **line, int fd);
char			**parse_map(t_game *game, char *path);
int				print_map(char **map, t_game *game);
void			clear_sprite(t_img *img, unsigned int color);
void			draw_sprite(t_game *game, t_img *img, int x, int y);
void			init_sprite(t_game *g);
bool			isg(t_game *game, char **map, int x, int y);
int				update(t_game *game);
bool			isg(t_game *game, char **map, int x, int y);
void			draw_tile(t_game *g, char **m, int x, int y);
t_box			player_box_x_y_off(t_game *game, float vx, float vy);
t_box			layer_box_x_y_off_below(t_game	*game);
void			collide_with_collectible(t_box player, t_game *game);
int				find_collectible_numbers(t_game *game, char **map);
void			collide_with_exit_chest(t_box player, t_game *game);
void			draw_collectible(t_game *g, int x, int y);
void			draw_door(t_game *g, int x, int y);
void			draw_background(t_game *game);
t_box			player_box_x_y(t_game *game);
t_box			player_box_stop_scrolling_left(t_game	*game);
t_box			player_box_stop_scrolling_right(t_game	*game);
void			draw_background_sprite(t_game *game, t_img *img, int scroll);
void			draw_vignette(t_game *game);
void			draw_anim_player(t_game *game, t_anim *anim);
void			draw_sprite_player(t_game *g, t_img *img, t_draw_info draw);
void			update_anim_player(t_game *game);
void			update_anim_collectible(char **map, t_game *game);
void			shoot_bomb(t_game *game);
void			update_bomb(t_game *game);
t_box			bomb_box(t_game *game);
void			draw_chest(t_game *game, int x, int y);
void			find_player_position(t_game *game, char **map);
void			find_enemy_position(t_game *game, char **map);
void			update_anim_enemy(t_game *game);
void			move_enemy(t_game *game);
t_box			enemy_box_y_off(t_game *game, float velocity_y);
int				count_map_height(char *path);
void			pathfinding(int x, int y, int max_jump, t_game *game);
bool			is_map_rectangular(t_game *game);
bool			is_map_surrounder_walls(t_game *game);
void			free_all_sprites(t_game *game);
int				close_game(t_game *game);
void			free_map(t_game *game);
bool			check_map_character_overall(t_game *game);
void			free_copy_map(t_game *game);
void			update_anim_bubble(t_game *game);
t_node			*create_list_collectible(t_game *game);
t_node			*create_node(int x, int y);
void			add_node_back(t_node **lst, t_node *new);
t_node_bubble	*create_list_bubble(t_game *game);
void			free_list_bubble(t_node_bubble *list);
void			update_anim_trail(t_game *game);
char			**copy_map(t_game *game);
bool			is_map_finishable(t_game *game);
void			free_list_collectible(t_node *collectible);
bool			check_all_sprite_load(t_game *game);
bool			print_error(char *str);
uint32_t		xorshift32(struct s_xorshift32_state *state);
void			add_node_back_bubble(t_node_bubble **lst, t_node_bubble *new);
t_node_bubble	*create_node_bubble(int x, int y, float velocity_y);
void			draw_anim_bubble(t_game *game, t_anim *anim, int x, int y);
void			draw_anim_enemy(t_game *game, t_anim *anim);
unsigned int	blend_colors(unsigned int a, unsigned int b, float ratio);
void			draw_sprite_enemy(t_game *g, t_img *img, t_draw_info draw);
void			draw_anim_collectible(t_game *game, t_anim *anim, int x, int y);
int				calcul_distance(t_enemy enemy, t_bomb bomb);
bool			check_over_scale(t_game *g, t_draw_info draw, int i, int j);
t_trgb			draw_not_flip(t_img *img, int i, int j);
t_trgb			draw_flip(t_img *img, int i, int j);
int				blended_color_enemy(t_game *g, t_draw_info draw, int i, int j);
t_img			*load_sprite(void *img, char *filename);
bool			check_init_successfull(t_anim *anim);
bool			check_all_sprite_load(t_game *game);
void			init_collectible(t_game *g);
void			init_enemy_idle_two(t_game *g);
void			init_enemy_idle(t_game *g);
void			init_enemy_attack(t_game *g);
void			init_bubble(t_game *g);
void			init_trail(t_game *g);
void			init_player_idle_two(t_game *g);
void			init_player_idle(t_game *g);
void			init_player_run(t_game *g);
void			init_player_jump(t_game *g);
void			init_player_fall(t_game *g);
void			init_player_hit(t_game *g);
int				free_if_error_map(t_game *game);
int				free_if_error_sprites(t_game *game);
void			free_if_no_error(t_game *game);
bool			check_first_line(t_game *game);
bool			check_last_line(t_game *game);
bool			check_first_column(t_game *game);
bool			check_last_column(t_game *game);
bool			print_error(char *str);
bool			is_valid_character(char character);
unsigned int	draw_not_flip_player(t_img *img, int i, int j);
unsigned int	draw_flip_player(t_img *img, int i, int j);
void			find_player_position(t_game *game, char **map);
void			display_hud(t_game *g);
int				free_if_error_init_map_player(t_game *game);
bool			is_map_ber(char *str);
t_box			player_box_x_y_off_below(t_game	*game);
#endif