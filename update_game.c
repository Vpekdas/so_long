/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:20:59 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/08 14:27:50 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	update(t_game *game)
{
	suseconds_t	now;

	now = getms();
	if (now - game->last_frame < FRAME_INTERVAL)
		return (0);
	game->last_frame = now;
	game->player.vx = 0;
	detect_key(game);
	if (!collide_with_map((t_box){game->player.x
			+ game->player.ox, game->player.y
			+ game->player.h - game->player.oy, game->player.w, 1}, game))
		game->player.vy += 18 * 0.016;
	move_player(game, game->player.vx, game->player.vy);
	clear_sprite(game->screen, 0x00ffffff); // ((int*)game->mid->data)[0]
	print_map(game->map, game);
	draw_sprite(game, game->spr.player, game->player.x, game->player.y);
	mlx_put_image_to_window(game->mlx, game->win, game->screen, 0, 0);
	return (0);
}
