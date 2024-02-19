/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:38:12 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/19 16:20:26 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*load_sprite(void *img, char *filename)
{
	int	width;
	int	height;

	return (mlx_xpm_file_to_image(img, filename, &width, &height));
}
void	init_anim_player_idle(t_game *game)
{
	game->anim.img = malloc(sizeof(t_img *) * 26);
	game->anim.img[0] = load_sprite(game->mlx, "textures/Player/Idle/1.xpm");
	game->anim.img[1] = load_sprite(game->mlx, "textures/Player/Idle/2.xpm");
	game->anim.img[2] = load_sprite(game->mlx, "textures/Player/Idle/3.xpm");
	game->anim.img[3] = load_sprite(game->mlx, "textures/Player/Idle/4.xpm");
	game->anim.img[4] = load_sprite(game->mlx, "textures/Player/Idle/5.xpm");
	game->anim.img[5] = load_sprite(game->mlx, "textures/Player/Idle/6.xpm");
	game->anim.img[6] = load_sprite(game->mlx, "textures/Player/Idle/7.xpm");
	game->anim.img[7] = load_sprite(game->mlx, "textures/Player/Idle/8.xpm");
	game->anim.img[8] = load_sprite(game->mlx, "textures/Player/Idle/9.xpm");
	game->anim.img[9] = load_sprite(game->mlx, "textures/Player/Idle/10.xpm");
	game->anim.img[10] = load_sprite(game->mlx, "textures/Player/Idle/11.xpm");
	game->anim.img[11] = load_sprite(game->mlx, "textures/Player/Idle/12.xpm");
	game->anim.img[12] = load_sprite(game->mlx, "textures/Player/Idle/13.xpm");
	game->anim.img[13] = load_sprite(game->mlx, "textures/Player/Idle/14.xpm");
	game->anim.img[14] = load_sprite(game->mlx, "textures/Player/Idle/15.xpm");
	game->anim.img[15] = load_sprite(game->mlx, "textures/Player/Idle/16.xpm");
	game->anim.img[16] = load_sprite(game->mlx, "textures/Player/Idle/17.xpm");
	game->anim.img[17] = load_sprite(game->mlx, "textures/Player/Idle/18.xpm");
	game->anim.img[18] = load_sprite(game->mlx, "textures/Player/Idle/19.xpm");
	game->anim.img[19] = load_sprite(game->mlx, "textures/Player/Idle/20.xpm");
	game->anim.img[20] = load_sprite(game->mlx, "textures/Player/Idle/21.xpm");
	game->anim.img[21] = load_sprite(game->mlx, "textures/Player/Idle/22.xpm");
	game->anim.img[22] = load_sprite(game->mlx, "textures/Player/Idle/23.xpm");
	game->anim.img[23] = load_sprite(game->mlx, "textures/Player/Idle/24.xpm");
	game->anim.img[24] = load_sprite(game->mlx, "textures/Player/Idle/25.xpm");
	game->anim.img[25] = load_sprite(game->mlx, "textures/Player/Idle/26.xpm");
	game->anim.frame_count = 26;
}

void	init_anim_player_run(t_game *game)
{
	game->anim_player_run.img = malloc(sizeof(t_img *) * 14);
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
	game->anim_player_run.frame_count = 14;
}

void	init_anim_player_jump(t_game *game)
{
	game->anim_player_jump.img = malloc(sizeof(t_img *) * 4);
	game->anim_player_jump.img[0] = load_sprite(game->mlx, "textures/Player/Jump/1.xpm");
	game->anim_player_jump.img[1] = load_sprite(game->mlx, "textures/Player/Jump/2.xpm");
	game->anim_player_jump.img[2] = load_sprite(game->mlx, "textures/Player/Jump/3.xpm");
	game->anim_player_jump.img[3] = load_sprite(game->mlx, "textures/Player/Jump/4.xpm");
}

void	init_anim_player_fall(t_game *game)
{
	game->anim_player_fall.img = malloc(sizeof(t_img *) * 2);
	game->anim_player_fall.img[0] = load_sprite(game->mlx, "textures/Player/Fall/1.xpm");
	game->anim_player_fall.img[1] = load_sprite(game->mlx, "textures/Player/Fall/2.xpm");
}

void	init_anim_collectible(t_game *game)
{
	game->collectible.img = malloc(sizeof(t_img *) * 14);
	game->collectible.frame_count = 14;
	game->collectible.img[0] = load_sprite(game->mlx, "textures/collectibles/1.xpm");
	game->collectible.img[1] = load_sprite(game->mlx, "textures/collectibles/2.xpm");
	game->collectible.img[2] = load_sprite(game->mlx, "textures/collectibles/3.xpm");
	game->collectible.img[3] = load_sprite(game->mlx, "textures/collectibles/4.xpm");
	game->collectible.img[4] = load_sprite(game->mlx, "textures/collectibles/5.xpm");
	game->collectible.img[5] = load_sprite(game->mlx, "textures/collectibles/6.xpm");
	game->collectible.img[6] = load_sprite(game->mlx, "textures/collectibles/7.xpm");
	game->collectible.img[7] = load_sprite(game->mlx, "textures/collectibles/8.xpm");
	game->collectible.img[8] = load_sprite(game->mlx, "textures/collectibles/9.xpm");
	game->collectible.img[9] = load_sprite(game->mlx, "textures/collectibles/10.xpm");
	game->collectible.img[10] = load_sprite(game->mlx, "textures/collectibles/11.xpm");
	game->collectible.img[11] = load_sprite(game->mlx, "textures/collectibles/12.xpm");
	game->collectible.img[12] = load_sprite(game->mlx, "textures/collectibles/13.xpm");
	game->collectible.img[13] = load_sprite(game->mlx, "textures/collectibles/14.xpm");
}

void	init_anim_player_hit(t_game *game)
{
	game->anim_player_hit.img = malloc(sizeof(t_img *) * 8);
	game->anim_player_hit.frame_count = 8;
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
	game->anim_enemy_idle.img = malloc(sizeof(t_img *) * 32);
	game->anim_enemy_idle.frame_count = 32;
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
	game->anim_enemy_attack.img = malloc(sizeof(t_img *) * 7);
	game->anim_enemy_attack.frame_count = 7; 
	game->anim_enemy_attack.img[0] = load_sprite(game->mlx, "textures/Enemy/Attack/1.xpm");
	game->anim_enemy_attack.img[1] = load_sprite(game->mlx, "textures/Enemy/Attack/2.xpm");
	game->anim_enemy_attack.img[2] = load_sprite(game->mlx, "textures/Enemy/Attack/3.xpm");
	game->anim_enemy_attack.img[3] = load_sprite(game->mlx, "textures/Enemy/Attack/4.xpm");
	game->anim_enemy_attack.img[4] = load_sprite(game->mlx, "textures/Enemy/Attack/5.xpm");
	game->anim_enemy_attack.img[5] = load_sprite(game->mlx, "textures/Enemy/Attack/6.xpm");
	game->anim_enemy_attack.img[6] = load_sprite(game->mlx, "textures/Enemy/Attack/7.xpm");
}


void	init_sprite(t_game *g)
{
	g->sprite.tl = load_sprite(g->mlx, "textures/tiles/tl.xpm");
	g->sprite.top = load_sprite(g->mlx, "textures/tiles/top.xpm");
	g->sprite.top_right = load_sprite(g->mlx, "textures/tiles/top_right.xpm");
	g->sprite.left = load_sprite(g->mlx, "textures/tiles/left.xpm");
	g->sprite.mid = load_sprite(g->mlx, "textures/tiles/mid.xpm");
	g->sprite.right = load_sprite(g->mlx, "textures/tiles/right.xpm");
	g->sprite.bot_left = load_sprite(g->mlx, "textures/tiles/bot_left.xpm");
	g->sprite.bot = load_sprite(g->mlx, "textures/tiles/bot.xpm");
	g->sprite.bot_right = load_sprite(g->mlx, "textures/tiles/bot_right.xpm");
	g->sprite.tl = load_sprite(g->mlx, "textures/tiles/tl.xpm");
	g->sprite.mid_tl = load_sprite(g->mlx, "textures/tiles/mid_tl.xpm");
	g->sprite.bot_tl = load_sprite(g->mlx, "textures/tiles/bot_tl.xpm");
	g->sprite.door = load_sprite(g->mlx, "textures/door/treasure.xpm");
	g->sprite.background = load_sprite(g->mlx, "textures/tiles/png/rocksfront.xpm");
	g->sprite.background2 = load_sprite(g->mlx, "textures/tiles/png/rocksback.xpm");
	g->sprite.water = load_sprite(g->mlx, "textures/tiles/png/water.xpm");
	g->sprite.foreground = load_sprite(g->mlx, "textures/tiles/png/foreground.xpm");
	g->sprite.door = load_sprite(g->mlx, "textures/chest/chest.xpm");
	g->sprite.bomb = load_sprite(g->mlx, "textures/bomb/1.xpm");
	init_anim_player_idle(g);
	init_anim_player_run(g);
	init_anim_player_jump(g);
	init_anim_player_fall(g);
	init_anim_player_hit(g);
	init_anim_collectible(g);
	init_anim_enemy_idle(g);
	init_anim_enemy_attack(g);
}
