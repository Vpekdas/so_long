/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:19:36 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/09 18:25:58 by vopekdas         ###   ########.fr       */
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
	g->sprite.tl = load_sprite(g->mlx, "textures/tl.xpm");
	g->sprite.top = load_sprite(g->mlx, "textures/top.xpm");
	g->sprite.top_right = load_sprite(g->mlx, "textures/top_right.xpm");
	g->sprite.left = load_sprite(g->mlx, "textures/left.xpm");
	g->sprite.mid = load_sprite(g->mlx, "textures/mid.xpm");
	g->sprite.right = load_sprite(g->mlx, "textures/right.xpm");
	g->sprite.bot_left = load_sprite(g->mlx, "textures/bot_left.xpm");
	g->sprite.bot = load_sprite(g->mlx, "textures/bot.xpm");
	g->sprite.bot_right = load_sprite(g->mlx, "textures/bot_right.xpm");
	g->sprite.tl = load_sprite(g->mlx, "textures/tl.xpm");
	g->sprite.mid_tl = load_sprite(g->mlx, "textures/mid_tl.xpm");
	g->sprite.bot_tl = load_sprite(g->mlx, "textures/bot_tl.xpm");
	g->sprite.collectible = load_sprite(g->mlx, "textures/collectible.xpm");
}