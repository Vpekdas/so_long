/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:19:36 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/15 13:55:37 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player_and_map(t_game *game)
{
	game->player.pos_x = 1500;
	game->player.pos_y = 70;
	game->player.width = 24 * SCALE;
	game->player.height = 60 * SCALE;
	game->player.offset_x = 32 * SCALE;
	game->player.offset_y = 0;
	game->map = parse_map(game, "maps/map.ber");
	game->collectibles_numbers = find_collectible_numbers(game, game->map);

}

t_img	*load_sprite(void *img, char *filename)
{
	int	width;
	int	height;

	return (mlx_xpm_file_to_image(img, filename, &width, &height));
}

void	init_anim_sprite_player(t_game *game)
{
	game->anim.img = malloc(sizeof(t_img *) * 26);
	game->anim.img[0] = load_sprite(game->mlx, "textures/Pirate/Player/Idle/1.xpm");
	game->anim.img[1] = load_sprite(game->mlx, "textures/Pirate/Player/Idle/2.xpm");
	game->anim.img[2] = load_sprite(game->mlx, "textures/Pirate/Player/Idle/3.xpm");
	game->anim.img[3] = load_sprite(game->mlx, "textures/Pirate/Player/Idle/4.xpm");
	game->anim.img[4] = load_sprite(game->mlx, "textures/Pirate/Player/Idle/5.xpm");
	game->anim.img[5] = load_sprite(game->mlx, "textures/Pirate/Player/Idle/6.xpm");
	game->anim.img[6] = load_sprite(game->mlx, "textures/Pirate/Player/Idle/7.xpm");
	game->anim.img[7] = load_sprite(game->mlx, "textures/Pirate/Player/Idle/8.xpm");
	game->anim.img[8] = load_sprite(game->mlx, "textures/Pirate/Player/Idle/9.xpm");
	game->anim.img[9] = load_sprite(game->mlx, "textures/Pirate/Player/Idle/10.xpm");
	game->anim.img[10] = load_sprite(game->mlx, "textures/Pirate/Player/Idle/11.xpm");
	game->anim.img[11] = load_sprite(game->mlx, "textures/Pirate/Player/Idle/12.xpm");
	game->anim.img[12] = load_sprite(game->mlx, "textures/Pirate/Player/Idle/13.xpm");
	game->anim.img[13] = load_sprite(game->mlx, "textures/Pirate/Player/Idle/14.xpm");
	game->anim.img[14] = load_sprite(game->mlx, "textures/Pirate/Player/Idle/15.xpm");
	game->anim.img[15] = load_sprite(game->mlx, "textures/Pirate/Player/Idle/16.xpm");
	game->anim.img[16] = load_sprite(game->mlx, "textures/Pirate/Player/Idle/17.xpm");
	game->anim.img[17] = load_sprite(game->mlx, "textures/Pirate/Player/Idle/18.xpm");
	game->anim.img[18] = load_sprite(game->mlx, "textures/Pirate/Player/Idle/19.xpm");
	game->anim.img[19] = load_sprite(game->mlx, "textures/Pirate/Player/Idle/20.xpm");
	game->anim.img[20] = load_sprite(game->mlx, "textures/Pirate/Player/Idle/21.xpm");
	game->anim.img[21] = load_sprite(game->mlx, "textures/Pirate/Player/Idle/22.xpm");
	game->anim.img[22] = load_sprite(game->mlx, "textures/Pirate/Player/Idle/23.xpm");
	game->anim.img[23] = load_sprite(game->mlx, "textures/Pirate/Player/Idle/24.xpm");
	game->anim.img[24] = load_sprite(game->mlx, "textures/Pirate/Player/Idle/25.xpm");
	game->anim.img[25] = load_sprite(game->mlx, "textures/Pirate/Player/Idle/26.xpm");
	game->anim.frame_count = 26;
}

void	init_anim_sprite_player_run(t_game *game)
{
	game->anim_player_run.img = malloc(sizeof(t_img *) * 14);
	game->anim_player_run.img[0] = load_sprite(game->mlx, "textures/Pirate/Player/Run/1.xpm");
	game->anim_player_run.img[1] = load_sprite(game->mlx, "textures/Pirate/Player/Run/2.xpm");
	game->anim_player_run.img[2] = load_sprite(game->mlx, "textures/Pirate/Player/Run/3.xpm");
	game->anim_player_run.img[3] = load_sprite(game->mlx, "textures/Pirate/Player/Run/4.xpm");
	game->anim_player_run.img[4] = load_sprite(game->mlx, "textures/Pirate/Player/Run/5.xpm");
	game->anim_player_run.img[5] = load_sprite(game->mlx, "textures/Pirate/Player/Run/6.xpm");
	game->anim_player_run.img[6] = load_sprite(game->mlx, "textures/Pirate/Player/Run/7.xpm");
	game->anim_player_run.img[7] = load_sprite(game->mlx, "textures/Pirate/Player/Run/8.xpm");
	game->anim_player_run.img[8] = load_sprite(game->mlx, "textures/Pirate/Player/Run/9.xpm");
	game->anim_player_run.img[9] = load_sprite(game->mlx, "textures/Pirate/Player/Run/10.xpm");
	game->anim_player_run.img[10] = load_sprite(game->mlx, "textures/Pirate/Player/Run/11.xpm");
	game->anim_player_run.img[11] = load_sprite(game->mlx, "textures/Pirate/Player/Run/12.xpm");
	game->anim_player_run.img[12] = load_sprite(game->mlx, "textures/Pirate/Player/Run/13.xpm");
	game->anim_player_run.img[13] = load_sprite(game->mlx, "textures/Pirate/Player/Run/14.xpm");
	game->anim_player_run.frame_count = 14;
}

void	init_anim_sprite_player_jump(t_game *game)
{
	game->anim_player_jump.img = malloc(sizeof(t_img *) * 4);
	game->anim_player_jump.img[0] = load_sprite(game->mlx, "textures/Pirate/Player/Jump/1.xpm");
	game->anim_player_jump.img[1] = load_sprite(game->mlx, "textures/Pirate/Player/Jump/2.xpm");
	game->anim_player_jump.img[2] = load_sprite(game->mlx, "textures/Pirate/Player/Jump/3.xpm");
	game->anim_player_jump.img[3] = load_sprite(game->mlx, "textures/Pirate/Player/Jump/4.xpm");
}

void	init_anim_sprite_player_fall(t_game *game)
{
	game->anim_player_fall.img = malloc(sizeof(t_img *) * 2);
	game->anim_player_fall.img[0] = load_sprite(game->mlx, "textures/Pirate/Player/Fall/1.xpm");
	game->anim_player_fall.img[1] = load_sprite(game->mlx, "textures/Pirate/Player/Fall/2.xpm");
}

void	init_anim_sprite_collectible(t_game *game)
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
	init_anim_sprite_player(g);
	init_anim_sprite_player_run(g);
	init_anim_sprite_player_jump(g);
	init_anim_sprite_player_fall(g);
	g->sprite.bomb = load_sprite(g->mlx, "texture/bomb/1.xpm");
	init_anim_sprite_collectible(g);
}