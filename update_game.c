/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:20:59 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/10 15:35:12 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	update(t_game *game)
{
	suseconds_t	now;
	t_box		player_box;

	player_box = player_box_x_off_minus_off_y(game);
	now = getms();
	if (now - game->last_frame < FRAME_INTERVAL)
		return (0);
	game->last_frame = now;
	game->player.velocity_x = 0;
	detect_key(game);
	if (!collide_with_map(player_box, game))
		game->player.velocity_y += 18 * 0.016;
	collide_with_collectible(player_box, game);
	move_player(game, game->player.velocity_x, game->player.velocity_y);
	clear_sprite(game->screen, 0x00ffffff);
	print_map(game->map, game);
	draw_sprite(game, game->sprite.player, game->player.pos_x, game->player.pos_y);
	mlx_put_image_to_window(game->mlx, game->win, game->screen, 0, 0);
	return (0);
}
