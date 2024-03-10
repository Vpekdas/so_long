/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:45:12 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/10 18:04:59 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "../Libft/libft.h"
# include "../ft_printf/include/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <math.h>
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>

# ifndef BONUS
#  define BONUS 0
# endif

# define BLK "\x1b[0;30m"
# define RED "\x1b[0;31m"
# define GRN "\x1b[0;32m"
# define YEL "\x1b[0;33m"
# define BLU "\x1b[0;34m"
# define MAG "\x1b[0;35m"
# define CYN "\x1b[0;36m"
# define WHT "\x1b[0;37m"
# define RST "\x1b[0m"
# define BBLK "\x1b[1;30m"
# define BRED "\x1b[1;31m"
# define BGRN "\x1b[1;32m"
# define BYEL "\x1b[1;33m"
# define BBLU "\x1b[1;34m"
# define BMAG "\x1b[1;35m"
# define BCYN "\x1b[1;36m"
# define BWHT "\x1b[1;37m"

# define SPRITE_SIZE 32
# define FRAME_INTER 4
# define PROPS_FRAME_INTER 6
# define SCALE 2
# define SPEED 8
# define WIN_W 1920
# define WIN_H 480

// ---------------------------------------------------------------------------//
//	+	+	+	+	+	+	+	// STRUCTURES //	+	+	+	+	+	+	+ //
// ---------------------------------------------------------------------------//

//############################################################################//
								// PLAYER / ENEMY / BOMB //
//############################################################################//
// #PLAYER#
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
// #ENEMY#
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
// #BOMB#
typedef struct bomb
{
	int		speed;
	int		pos_x;
	int		pos_y;
	int		explo_x;
	int		explo_y;
	int		offset_y;
	int		height;
	int		width;
	int		bomb_number;
	bool	direction;
	bool	is_exploding;
}				t_bomb;

//############################################################################//
					// SPRITE / ANIM / DRAW / COLOR / VIGNETTE //
//############################################################################//
// #SPRITE#
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
// #ANIM#
typedef struct s_anim
{
	t_img		**img;
	suseconds_t	current_frame;
	suseconds_t	last_frame;
	int			anim_index;
	int			frame;
	int			frame_count;
}				t_anim;
// #COLOR#
typedef struct s_trgb
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	t;
}	t_trgb;
// #DRAW#
typedef struct s_draw_info
{
	int		x;
	int		y;
	bool	flip;
	t_trgb	color;
}			t_draw_info;
// #VIGNETTE#
typedef struct s_vignette
{
	int		si;
	int		sj;
	float	ri;
	float	rj;
}			t_vignette;

//############################################################################//
								// HITBOX //
//############################################################################//
// #BOX#
typedef struct s_box
{
	int	pos_x;
	int	pos_y;
	int	width;
	int	height;
}		t_box;

//############################################################################//
								// LINKED LIST //
//############################################################################//
// #COLLECTIBLE#
typedef struct s_node
{
	int				pos_x;
	int				pos_y;
	struct s_node	*next;
}				t_node;
// #BUBBLE#
typedef struct s_node_bubble
{
	int						pos_x;
	int						pos_y;
	float					velocity_y;
	struct s_node_bubble	*next;
}				t_node_bubble;

//############################################################################//
								// MAP CHARACTER//
//############################################################################//
// CHARACTER
typedef struct s_character_map
{
	int	collectible_nb;
	int	exit_nb;
	int	player_nb;
	int	enemy_nb;
}				t_character_map;

//############################################################################//
								// PATHFINDING //
//############################################################################//
// #MAP COPY#
typedef struct s_map_copy
{
	char	**map;
	int		map_width;
	int		map_height;
}				t_map_copy;
// #POS#
typedef struct s_pathfinding
{
	int	pos_x;
	int	pos_y;
}				t_pathfinding;

//############################################################################//
								// RANDOM GENERATOR //
//############################################################################//
// XORSHIFT
typedef struct s_xorshift32_state
{
	uint32_t	a;
}		t_xorshift32_state;

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//
									// GAME //
typedef struct s_game
{
	void				*mlx;
	void				*win;
	char				*map_path;
	char				**map;
	float				move_count;
	int					step_count;
	int					key_a;
	int					key_w;
	int					key_s;
	int					key_d;
	int					key_space;
	int					key_esc;
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
	int					frame_count;
	bool				is_trail_drawn;
	t_img				*screen;
	t_img				**sprites;
	t_anim				player_idle;
	t_anim				player_run;
	t_anim				player_jump;
	t_anim				player_fall;
	t_anim				player_hit;
	t_anim				enemy_idle;
	t_anim				enemy_attack;
	t_anim				bomb_on;
	t_anim				explotion;
	t_anim				collectible;
	t_anim				bubble;
	t_anim				trail;
	t_draw_info			draw_info;
	t_draw_info			draw_info_enemy;
	t_draw_info			draw_info_bomb;
	t_node				*collectible_list;
	t_node_bubble		*bubble_list;
	t_pathfinding		**collectible_pos;
	t_pathfinding		pathfinding;
	t_player			play;
	t_enemy				enemy;
	t_bomb				bomb;
	t_vignette			vignette;
	t_map_copy			map_copy;
	t_character_map		character_map;
	t_xorshift32_state	*state;
}						t_game;
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//

// ---------------------------------------------------------------------------//
//	+	+	+	+	+	+	+	// FUNCTIONS //	+	+	+	+	+	+	+	+ //
// ---------------------------------------------------------------------------//

////////////////////////////////////////////////////////////////////////////////
								// DRAW //
////////////////////////////////////////////////////////////////////////////////
// SPRITE
void			draw_sprite(t_game *game, t_img *img, int x, int y);
void			draw_sprite_enemy(t_game *game, t_img *img, t_draw_info draw);
void			draw_sprite_player(t_game *game, t_img *img, t_draw_info draw);
void			draw_sprite_background(t_game *game, t_img *img, int scroll);
void			draw_chest(t_game *game, int x, int y);
void			draw_tile(t_game *g, char **m, int x, int y);
void			draw_map(char **map, t_game *game);
// ANIM
void			draw_anim_collectible(t_game *game, t_anim *anim, int x, int y);
void			draw_anim_bubble(t_game *game, t_anim *anim, int x, int y);
void			draw_anim_enemy(t_game *game, t_anim *anim);
void			draw_anim_player(t_game *game, t_anim *anim);
void			draw_anim_trail(t_game *game, t_anim *anim);
void			draw_anim_explotion(t_game *game, t_anim *anim, int x, int y);
// BACKGROUND
void			draw_background(t_game *game);
// FLIP
t_trgb			draw_not_flip(t_img *img, int i, int j);
t_trgb			draw_flip(t_img *img, int i, int j);
unsigned int	draw_not_flip_player(t_img *img, int i, int j);
unsigned int	draw_flip_player(t_img *img, int i, int j);
// VIGNETTE
void			draw_vignette(t_game *game);
void			draw_left_to_right(t_trgb *color, float ri);
void			draw_top_to_bot(t_trgb *color, float rj);
// UTILS
bool			check_over_scale(t_game *game, t_draw_info draw, int i, int j);
unsigned int	blend_colors(unsigned int a, unsigned int b, float ratio);
int				blended_color_enemy(t_game *g, t_draw_info draw, int i, int j);
bool			is_wall(t_game *game, char **map, int x, int y);

////////////////////////////////////////////////////////////////////////////////
								// HITBOX //
////////////////////////////////////////////////////////////////////////////////
// PLAYER
t_box			player_box_x_off(t_game *game, float velocity_x);
t_box			player_box_y_off(t_game *game, float velocity_y);
t_box			player_box_x_y(t_game *game);
t_box			player_box_x_y_off(t_game *g, float vx, float vy);
t_box			player_box_x_y_off_below(t_game	*game);
// ENEMY
t_box			enemy_box_y_off(t_game *game, float velocity_y);
// BOMB
t_box			bomb_box(t_game *game);
// MAP
t_box			map_box_scale(int x, int y);

////////////////////////////////////////////////////////////////////////////////
								// UPDATE //
////////////////////////////////////////////////////////////////////////////////
// GAME
int				update(t_game *game);
void			update_explotion_state(t_game *game);
// ANIM
void			update_animation(t_game *game);
void			update_anim_player(t_game *game);
void			update_anim_enemy(t_game *game);
void			update_anim_collectible(char **map, t_game *game);
void			update_anim_bubble(t_game *game);
void			update_particle_and_background(t_game *game);
void			update_anim_trail(t_game *game);
void			update_anim_explotion(t_game *game);
// FRAME
void			update_frame_bubble(t_game *game, t_anim *anim);
void			update_frame_collectible(t_game *game, t_anim *anim);
// MOVE
// // PLAYER
void			move_player(t_game *game, float velocity_x, float velocity_y);
void			adjust_velocity_x(t_game *game, float vx);
void			adjust_velocity_y(t_game *game, float vy);
void			update_move(t_game *game);
// // ENEMY
void			adjust_enemy_pos(t_game *game);
void			move_enemy(t_game *game);
// BOMB
void			update_bomb(t_game *game);
void			shoot_bomb(t_game *game);
// KEY
int				key_pressed(int keycode, t_game *game);
int				key_released(int keycode, t_game *game);
void			detect_key(t_game *game);
void			detect_key_two(t_game *game);
// COLLIDE
bool			collide(t_box player, t_box object);
bool			collide_with_map(t_box player, t_game *game);
void			collide_with_collectible(t_box player, t_game *game);
void			collide_with_exit_chest(t_box player, t_game *game);
void			update_collide(t_game *game, t_box player_box);
// HUD
void			display_hud(t_game *g);
void			display_step_count(t_game *g);
void			display_health(t_game *g);
void			display_remaining_collectibles(t_game *g);
// CLOSE
int				close_game(t_game *game);
// DODGE
int				calcul_distance(t_enemy enemy, t_bomb bomb);

////////////////////////////////////////////////////////////////////////////////
								// LINKED LIST //
////////////////////////////////////////////////////////////////////////////////
// COLLECTIBLE
t_node			*create_node_collectible(int x, int y);
t_node			*create_list_collectible(t_game *game);
void			add_node_back(t_node **lst, t_node *node);
// BUBBLE
t_node_bubble	*create_node_bubble(int x, int y, float velocity_y);
t_node_bubble	*create_list_bubble(t_game *game);
void			add_node_back_bubble(t_node_bubble **lst, t_node_bubble *node);

////////////////////////////////////////////////////////////////////////////////
								// INITIALIZE SPRITE //
////////////////////////////////////////////////////////////////////////////////
// OVERALL
t_img			*load_sprite(void *img, char *filename);
void			init_sprite(t_game *g);
// PLAYER
void			init_player_idle(t_game *g);
void			init_player_idle_two(t_game *g);
void			init_player_run(t_game *g);
void			init_player_jump(t_game *g);
void			init_player_fall(t_game *g);
void			init_player_hit(t_game *g);
void			init_explotion(t_game *g);
// ENEMY
void			init_enemy_idle(t_game *g);
void			init_enemy_attack(t_game *g);
// PARTICLE
void			init_bubble(t_game *g);
void			init_trail(t_game *g);
// TILES
void			init_tiles(t_game *game);
// COLLECTIBLE
void			init_collectible(t_game *g);

////////////////////////////////////////////////////////////////////////////////
								// INITIALIZE SETTINGS //
////////////////////////////////////////////////////////////////////////////////
// PLAYER / MAP
int				init_player_and_map(t_game *game);
int				count_map_height(char *path);
void			find_player_position(t_game *game, char **map);
// ENEMY
void			find_enemy_position(t_game *game, char **map);
void			init_enemy(t_game *game);
// COLLECTIBLE
int				find_collectible_numbers(t_game *game, char **map);
// MLX
int				init_mlx_settings(t_game *game, char **av);
// MAP
char			**parse_map(t_game *game, char *path);
char			*gnl(char **line, int fd);
char			**copy_map(t_game *game);
// RAND
uint32_t		xorshift32(t_xorshift32_state *state);

////////////////////////////////////////////////////////////////////////////////
								// CHECKING //
////////////////////////////////////////////////////////////////////////////////
// RECTANGULAR
bool			check_first_line(t_game *game);
bool			check_last_line(t_game *game);
bool			check_first_column(t_game *game);
bool			check_last_column(t_game *game);
bool			is_map_rectangular(t_game *game);
// SURROUNDED
bool			is_map_surrounded_walls(t_game *game);
// FORMAT
bool			is_valid_character(char character);
bool			is_map_ber(char *str);
bool			check_fd(char *path, int *fd);
// OVERALL
bool			check_map_character(t_game *game);
bool			check_character_number(t_game *game);
bool			check_map_character_overall(t_game *game);
// SPRITES
bool			check_init_successfull(t_anim *anim);
bool			check_all_sprite_load(t_game *game);
// MESSAGE
bool			print_error(char *str);

////////////////////////////////////////////////////////////////////////////////
								// PATHFINDING //
////////////////////////////////////////////////////////////////////////////////
// PATHFINDING
void			jmp(int x, int y, int jump, t_game *game);
void			fall(int x, int y, int jump, t_game *game);
void			pathfinding(int x, int y, int jump, t_game *game);
// CHECKING
bool			is_map_finishable(t_game *game);

////////////////////////////////////////////////////////////////////////////////
								// FREE //
////////////////////////////////////////////////////////////////////////////////
// SPRITE
void			free_anim_sprite(t_anim *anim, t_game *game);
void			free_all_sprites(t_game *game);
// MAP
void			free_map(t_game *game);
void			free_copy_map(t_game *game);
// LINKED LIST
void			free_list_bubble(t_node_bubble *list);
void			free_list_collectible(t_node *collectible);
// ERROR
int				free_if_error_map(t_game *game);
int				free_if_error_sprites(t_game *game);
int				free_if_error_init_map_player(t_game *game);
// FINE
void			free_if_no_error(t_game *game);

#endif