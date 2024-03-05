/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_tiles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:38:12 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/05 13:18:25 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static const char	*g_sprite_paths[NUM_SPRITES] = {
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
	"textures/Tiles/back/rocksfront.xpm",
	"textures/Tiles/back/rocksback.xpm",
	"textures/Tiles/back/water.xpm",
	"textures/Tiles/back/foreground.xpm",
	"textures/Chest/chest.xpm",
	"textures/Chest/chest_open.xpm",
	"textures/Bomb/1.xpm"
};

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
	init_player_idle(g);
	init_player_run(g);
	init_player_jump(g);
	init_player_fall(g);
	init_player_hit(g);
	init_collectible(g);
	init_enemy_idle(g);
	init_enemy_attack(g);
	init_bubble(g);
	init_trail(g);
}
