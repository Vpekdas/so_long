/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:19:36 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/11 15:56:00 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player_and_map(t_game *game)
{
	game->player.pos_x = 100;
	game->player.pos_y = 100;
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

void	init_sprite(t_game *g)
{
	g->sprite.player = load_sprite(g->mlx, "Idle_1.xpm");
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
	g->sprite.collectible = load_sprite(g->mlx, "textures/collectibles/collectible.xpm");
	g->sprite.door = load_sprite(g->mlx, "textures/door/treasure.xpm");
}