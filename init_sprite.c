/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:38:12 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/01 17:19:47 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

const char	*g_sprite_paths[NUM_SPRITES] = {
	"textures/Tiles/tl.xpm",
	"textures/Tiles/top.xpm",
	"textures/Tiles/top_right.xpm",
	"textures/Tiles/left.xpm",
	"textures/Tiles/mid.xpm",
	"textures/Tiles/right.xpm",
	"textures/Tiles/bot_left.xpm",
	"textures/Tiles/bot.xpm",
	"textures/Tiles/bot_right.xpm",
	"textures/Tiles/mid_tl.xpm",
	"textures/Tiles/bot_tl.xpm",
	"textures/Tiles/png/rocksfront.xpm",
	"textures/Tiles/png/rocksback.xpm",
	"textures/Tiles/png/water.xpm",
	"textures/Tiles/png/foreground.xpm",
	"textures/Chest/chest.xpm",
	"textures/Chest/chest_open.xpm",
	"textures/Bomb/1.xpm"
};

t_img	*load_sprite(void *img, char *filename)
{
	int	width;
	int	height;

	if (!img || !filename)
		return (NULL);
	return (mlx_xpm_file_to_image(img, filename, &width, &height));
}

bool	check_init_successfull(t_anim *anim)
{
	int	i;

	i = 0;
	while (i < anim->frame_count)
	{
		if (!anim->img[i])
			return (false);
		else
			i++;
	}
	return (true);
}

bool	check_all_sprite_load(t_game *game)
{
	if (check_init_successfull(&game->anim_player_idle) == false)
		return (print_error("Error\nAnim player idle failed to load"));
	if (check_init_successfull(&game->anim_player_run) == false)
		return (print_error("Error\nAnim player run failed to load"));
	if (check_init_successfull(&game->anim_player_jump) == false)
		return (print_error("Error\nAnim player jump failed to load"));
	if (check_init_successfull(&game->anim_player_fall) == false)
		return (print_error("Error\nAnim player fall failed to load"));
	if (check_init_successfull(&game->anim_player_hit) == false)
		return (print_error("Error\nAnim player hit failed to load"));
	if (check_init_successfull(&game->collectible) == false)
		return (print_error("Error\nCollectible failed to load"));
	if (check_init_successfull(&game->anim_enemy_idle) == false)
		return (print_error("Error\nAnim enemy idle failed to load"));
	if (check_init_successfull(&game->anim_enemy_attack) == false)
		return (print_error("Error\nAnim enemy attack failed to load"));
	if (check_init_successfull(&game->anim_bubble) == false)
		return (print_error("Error\nAnim bubble failed to load"));
	if (check_init_successfull(&game->anim_trail) == false)
		return (print_error("Error\nAnim trail failed to load"));
	return (true);
}

void	init_anim_player_idle(t_game *game)
{
	game->anim_player_idle.frame_count = 26;
	game->anim_player_idle.img = malloc(sizeof(t_img *) * 26);
	if (!game->anim_player_idle.img)
		return ;
	game->anim_player_idle.img[0] = load_sprite(game->mlx, "textures/Player/Idle/1.xpm");
	game->anim_player_idle.img[1] = load_sprite(game->mlx, "textures/Player/Idle/2.xpm");
	game->anim_player_idle.img[2] = load_sprite(game->mlx, "textures/Player/Idle/3.xpm");
	game->anim_player_idle.img[3] = load_sprite(game->mlx, "textures/Player/Idle/4.xpm");
	game->anim_player_idle.img[4] = load_sprite(game->mlx, "textures/Player/Idle/5.xpm");
	game->anim_player_idle.img[5] = load_sprite(game->mlx, "textures/Player/Idle/6.xpm");
	game->anim_player_idle.img[6] = load_sprite(game->mlx, "textures/Player/Idle/7.xpm");
	game->anim_player_idle.img[7] = load_sprite(game->mlx, "textures/Player/Idle/8.xpm");
	game->anim_player_idle.img[8] = load_sprite(game->mlx, "textures/Player/Idle/9.xpm");
	game->anim_player_idle.img[9] = load_sprite(game->mlx, "textures/Player/Idle/10.xpm");
	game->anim_player_idle.img[10] = load_sprite(game->mlx, "textures/Player/Idle/11.xpm");
	game->anim_player_idle.img[11] = load_sprite(game->mlx, "textures/Player/Idle/12.xpm");
	game->anim_player_idle.img[12] = load_sprite(game->mlx, "textures/Player/Idle/13.xpm");
	game->anim_player_idle.img[13] = load_sprite(game->mlx, "textures/Player/Idle/14.xpm");
	game->anim_player_idle.img[14] = load_sprite(game->mlx, "textures/Player/Idle/15.xpm");
	game->anim_player_idle.img[15] = load_sprite(game->mlx, "textures/Player/Idle/16.xpm");
	game->anim_player_idle.img[16] = load_sprite(game->mlx, "textures/Player/Idle/17.xpm");
	game->anim_player_idle.img[17] = load_sprite(game->mlx, "textures/Player/Idle/18.xpm");
	game->anim_player_idle.img[18] = load_sprite(game->mlx, "textures/Player/Idle/19.xpm");
	game->anim_player_idle.img[19] = load_sprite(game->mlx, "textures/Player/Idle/20.xpm");
	game->anim_player_idle.img[20] = load_sprite(game->mlx, "textures/Player/Idle/21.xpm");
	game->anim_player_idle.img[21] = load_sprite(game->mlx, "textures/Player/Idle/22.xpm");
	game->anim_player_idle.img[22] = load_sprite(game->mlx, "textures/Player/Idle/23.xpm");
	game->anim_player_idle.img[23] = load_sprite(game->mlx, "textures/Player/Idle/24.xpm");
	game->anim_player_idle.img[24] = load_sprite(game->mlx, "textures/Player/Idle/25.xpm");
	game->anim_player_idle.img[25] = load_sprite(game->mlx, "textures/Player/Idle/26.xpm");
}

void	init_anim_player_run(t_game *game)
{
	game->anim_player_run.frame_count = 14;
	game->anim_player_run.img = malloc(sizeof(t_img *) * 14);
	if (!game->anim_player_run.img)
		return ;
	game->anim_player_run.img[0] = load_sprite(game->mlx, "textures/Player/Run/1.xpm");
	game->anim_player_run.img[1] = load_sprite(game->mlx, "textures/Player/Run/2.xpm");
	game->anim_player_run.img[2] = load_sprite(game->mlx, "textures/Player/Run/3.xpm");
	game->anim_player_run.img[3] = load_sprite(game->mlx, "textures/Player/Run/4.xpm");
	game->anim_player_run.img[4] = load_sprite(game->mlx, "textures/Player/Run/5.xpm");
	game->anim_player_run.img[5] = load_sprite(game->mlx, "textures/Player/Run/6.xpm");
	game->anim_player_run.img[6] = load_sprite(game->mlx, "textures/Player/Run/7.xpm");
	game->anim_player_run.img[7] = load_sprite(game->mlx, "textures/Player/Run/8.xpm");
	game->anim_player_run.img[8] = load_sprite(game->mlx, "textures/Player/Run/9.xpm");
	game->anim_player_run.img[9] = load_sprite(game->mlx, "textures/Player/Run/10.xpm");
	game->anim_player_run.img[10] = load_sprite(game->mlx, "textures/Player/Run/11.xpm");
	game->anim_player_run.img[11] = load_sprite(game->mlx, "textures/Player/Run/12.xpm");
	game->anim_player_run.img[12] = load_sprite(game->mlx, "textures/Player/Run/13.xpm");
	game->anim_player_run.img[13] = load_sprite(game->mlx, "textures/Player/Run/14.xpm");
}

void	init_anim_player_jump(t_game *game)
{
	game->anim_player_jump.frame_count = 4;
	game->anim_player_jump.img = malloc(sizeof(t_img *) * 4);
	if (!game->anim_player_jump.img)
		return ;
	game->anim_player_jump.img[0] = load_sprite(game->mlx, "textures/Player/Jump/1.xpm");
	game->anim_player_jump.img[1] = load_sprite(game->mlx, "textures/Player/Jump/2.xpm");
	game->anim_player_jump.img[2] = load_sprite(game->mlx, "textures/Player/Jump/3.xpm");
	game->anim_player_jump.img[3] = load_sprite(game->mlx, "textures/Player/Jump/4.xpm");
}

void	init_anim_player_fall(t_game *game)
{
	game->anim_player_fall.frame_count = 2;
	game->anim_player_fall.img = malloc(sizeof(t_img *) * 2);
	if (!game->anim_player_fall.img)
		return ;
	game->anim_player_fall.img[0] = load_sprite(game->mlx, "textures/Player/Fall/1.xpm");
	game->anim_player_fall.img[1] = load_sprite(game->mlx, "textures/Player/Fall/2.xpm");
}

void	init_anim_collectible(t_game *game)
{
	game->collectible.frame_count = 14;
	game->collectible.img = malloc(sizeof(t_img *) * 14);
	if (!game->collectible.img)
		return ;
	game->collectible.img[0] = load_sprite(game->mlx, "textures/Collectibles/1.xpm");
	game->collectible.img[1] = load_sprite(game->mlx, "textures/Collectibles/2.xpm");
	game->collectible.img[2] = load_sprite(game->mlx, "textures/Collectibles/3.xpm");
	game->collectible.img[3] = load_sprite(game->mlx, "textures/Collectibles/4.xpm");
	game->collectible.img[4] = load_sprite(game->mlx, "textures/Collectibles/5.xpm");
	game->collectible.img[5] = load_sprite(game->mlx, "textures/Collectibles/6.xpm");
	game->collectible.img[6] = load_sprite(game->mlx, "textures/Collectibles/7.xpm");
	game->collectible.img[7] = load_sprite(game->mlx, "textures/Collectibles/8.xpm");
	game->collectible.img[8] = load_sprite(game->mlx, "textures/Collectibles/9.xpm");
	game->collectible.img[9] = load_sprite(game->mlx, "textures/Collectibles/10.xpm");
	game->collectible.img[10] = load_sprite(game->mlx, "textures/Collectibles/11.xpm");
	game->collectible.img[11] = load_sprite(game->mlx, "textures/Collectibles/12.xpm");
	game->collectible.img[12] = load_sprite(game->mlx, "textures/Collectibles/13.xpm");
	game->collectible.img[13] = load_sprite(game->mlx, "textures/Collectibles/14.xpm");
}

void	init_anim_player_hit(t_game *game)
{
	game->anim_player_hit.frame_count = 8;
	game->anim_player_hit.img = malloc(sizeof(t_img *) * 8);
	if(!game->anim_player_hit.img)
		return ;
	game->anim_player_hit.img[0] = load_sprite(game->mlx, "textures/Player/Hit/1.xpm");
	game->anim_player_hit.img[1] = load_sprite(game->mlx, "textures/Player/Hit/2.xpm");
	game->anim_player_hit.img[2] = load_sprite(game->mlx, "textures/Player/Hit/3.xpm");
	game->anim_player_hit.img[3] = load_sprite(game->mlx, "textures/Player/Hit/4.xpm");
	game->anim_player_hit.img[4] = load_sprite(game->mlx, "textures/Player/Hit/5.xpm");
	game->anim_player_hit.img[5] = load_sprite(game->mlx, "textures/Player/Hit/6.xpm");
	game->anim_player_hit.img[6] = load_sprite(game->mlx, "textures/Player/Hit/7.xpm");
	game->anim_player_hit.img[7] = load_sprite(game->mlx, "textures/Player/Hit/8.xpm");
}

void	init_anim_enemy_idle(t_game *game)
{
	game->anim_enemy_idle.frame_count = 32;
	game->anim_enemy_idle.img = malloc(sizeof(t_img *) * 32);
	if (!game->anim_enemy_idle.img)
		return ;
	game->anim_enemy_idle.img[0] = load_sprite(game->mlx, "textures/Enemy/Idle/1.xpm");
	game->anim_enemy_idle.img[1] = load_sprite(game->mlx, "textures/Enemy/Idle/2.xpm");
	game->anim_enemy_idle.img[2] = load_sprite(game->mlx, "textures/Enemy/Idle/3.xpm");
	game->anim_enemy_idle.img[3] = load_sprite(game->mlx, "textures/Enemy/Idle/4.xpm");
	game->anim_enemy_idle.img[4] = load_sprite(game->mlx, "textures/Enemy/Idle/5.xpm");
	game->anim_enemy_idle.img[5] = load_sprite(game->mlx, "textures/Enemy/Idle/6.xpm");
	game->anim_enemy_idle.img[6] = load_sprite(game->mlx, "textures/Enemy/Idle/7.xpm");
	game->anim_enemy_idle.img[7] = load_sprite(game->mlx, "textures/Enemy/Idle/8.xpm");
	game->anim_enemy_idle.img[8] = load_sprite(game->mlx, "textures/Enemy/Idle/9.xpm");
	game->anim_enemy_idle.img[9] = load_sprite(game->mlx, "textures/Enemy/Idle/10.xpm");
	game->anim_enemy_idle.img[10] = load_sprite(game->mlx, "textures/Enemy/Idle/11.xpm");
	game->anim_enemy_idle.img[11] = load_sprite(game->mlx, "textures/Enemy/Idle/12.xpm");
	game->anim_enemy_idle.img[12] = load_sprite(game->mlx, "textures/Enemy/Idle/13.xpm");
	game->anim_enemy_idle.img[13] = load_sprite(game->mlx, "textures/Enemy/Idle/14.xpm");
	game->anim_enemy_idle.img[14] = load_sprite(game->mlx, "textures/Enemy/Idle/15.xpm");
	game->anim_enemy_idle.img[15] = load_sprite(game->mlx, "textures/Enemy/Idle/16.xpm");
	game->anim_enemy_idle.img[16] = load_sprite(game->mlx, "textures/Enemy/Idle/17.xpm");
	game->anim_enemy_idle.img[17] = load_sprite(game->mlx, "textures/Enemy/Idle/18.xpm");
	game->anim_enemy_idle.img[18] = load_sprite(game->mlx, "textures/Enemy/Idle/19.xpm");
	game->anim_enemy_idle.img[19] = load_sprite(game->mlx, "textures/Enemy/Idle/20.xpm");
	game->anim_enemy_idle.img[20] = load_sprite(game->mlx, "textures/Enemy/Idle/21.xpm");
	game->anim_enemy_idle.img[21] = load_sprite(game->mlx, "textures/Enemy/Idle/22.xpm");
	game->anim_enemy_idle.img[22] = load_sprite(game->mlx, "textures/Enemy/Idle/23.xpm");
	game->anim_enemy_idle.img[23] = load_sprite(game->mlx, "textures/Enemy/Idle/24.xpm");
	game->anim_enemy_idle.img[24] = load_sprite(game->mlx, "textures/Enemy/Idle/25.xpm");
	game->anim_enemy_idle.img[25] = load_sprite(game->mlx, "textures/Enemy/Idle/26.xpm");
	game->anim_enemy_idle.img[26] = load_sprite(game->mlx, "textures/Enemy/Idle/27.xpm");
	game->anim_enemy_idle.img[27] = load_sprite(game->mlx, "textures/Enemy/Idle/28.xpm");
	game->anim_enemy_idle.img[28] = load_sprite(game->mlx, "textures/Enemy/Idle/29.xpm");
	game->anim_enemy_idle.img[29] = load_sprite(game->mlx, "textures/Enemy/Idle/30.xpm");
	game->anim_enemy_idle.img[30] = load_sprite(game->mlx, "textures/Enemy/Idle/31.xpm");
	game->anim_enemy_idle.img[31] = load_sprite(game->mlx, "textures/Enemy/Idle/32.xpm");
}

void	init_anim_enemy_attack(t_game *game)
{
	game->anim_enemy_attack.frame_count = 7; 
	game->anim_enemy_attack.img = malloc(sizeof(t_img *) * 7);
	if (!game->anim_enemy_attack.img)
		return ;
	game->anim_enemy_attack.img[0] = load_sprite(game->mlx, "textures/Enemy/Attack/1.xpm");
	game->anim_enemy_attack.img[1] = load_sprite(game->mlx, "textures/Enemy/Attack/2.xpm");
	game->anim_enemy_attack.img[2] = load_sprite(game->mlx, "textures/Enemy/Attack/3.xpm");
	game->anim_enemy_attack.img[3] = load_sprite(game->mlx, "textures/Enemy/Attack/4.xpm");
	game->anim_enemy_attack.img[4] = load_sprite(game->mlx, "textures/Enemy/Attack/5.xpm");
	game->anim_enemy_attack.img[5] = load_sprite(game->mlx, "textures/Enemy/Attack/6.xpm");
	game->anim_enemy_attack.img[6] = load_sprite(game->mlx, "textures/Enemy/Attack/7.xpm");
}

void	init_anim_bubble(t_game *game)
{
	game->anim_bubble.frame_count = 7;
	game->anim_bubble.img = malloc(sizeof(t_img *) * 7);
	if (!game->anim_bubble.img)
		return ;
	game->anim_bubble.img[0] = load_sprite(game->mlx, "textures/Bubbles/1.xpm");
	game->anim_bubble.img[1] = load_sprite(game->mlx, "textures/Bubbles/2.xpm");
	game->anim_bubble.img[2] = load_sprite(game->mlx, "textures/Bubbles/3.xpm");
	game->anim_bubble.img[3] = load_sprite(game->mlx, "textures/Bubbles/4.xpm");
	game->anim_bubble.img[4] = load_sprite(game->mlx, "textures/Bubbles/5.xpm");
	game->anim_bubble.img[5] = load_sprite(game->mlx, "textures/Bubbles/6.xpm");
	game->anim_bubble.img[6] = load_sprite(game->mlx, "textures/Bubbles/7.xpm");
}

void	init_anim_trail(t_game *game)
{
	game->anim_trail.frame_count = 4;
	game->anim_trail.img = malloc(sizeof(t_img *) * 4);
	if (!game->anim_trail.img)
		return ;
	game->anim_trail.img[0] = load_sprite(game->mlx, "textures/Trail/1.xpm");
	game->anim_trail.img[1] = load_sprite(game->mlx, "textures/Trail/2.xpm");
	game->anim_trail.img[2] = load_sprite(game->mlx, "textures/Trail/3.xpm");
	game->anim_trail.img[3] = load_sprite(game->mlx, "textures/Trail/4.xpm");
}

void	init_tiles(t_game *game)
{
	int	i;

	i = 0;
	game->sprites = malloc(sizeof(t_img *) * NUM_SPRITES);
	if (!game->sprites)
		return ;
	while (i < NUM_SPRITES)
	{
		game->sprites[i] = load_sprite(game->mlx, (char *)g_sprite_paths[i]);
		i++;
	}
}

void	init_sprite(t_game *g)
{
	init_tiles(g);
	init_anim_player_idle(g);
	init_anim_player_run(g);
	init_anim_player_jump(g);
	init_anim_player_fall(g);
	init_anim_player_hit(g);
	init_anim_collectible(g);
	init_anim_enemy_idle(g);
	init_anim_enemy_attack(g);
	init_anim_bubble(g);
	init_anim_trail(g);
}
