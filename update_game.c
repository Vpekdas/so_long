/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:20:59 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/15 13:31:59 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	update(t_game *game)
{
	t_box		player_box;

	game->player.velocity_x = 0;
	detect_key(game);
	player_box = player_box_x_y_off_below(game);
	if (!collide_with_map(player_box, game))
		game->player.velocity_y += 18 * 0.016;
	player_box = player_box_y_off(game, game->player.velocity_y);
	collide_with_collectible(player_box, game);
	collide_with_exit_door(player_box, game);
	move_player(game, game->player.velocity_x, game->player.velocity_y);
	clear_sprite(game->screen, 0x13120e);
	draw_background(game);
	print_map(game->map, game);
	update_anim_player(game);
	update_anim_collectible(game->map, game);
	draw_background_sprite(game, game->sprite.foreground, game->fg_scroll);
	mlx_put_image_to_window(game->mlx, game->win, game->screen, 0, 0);
	draw_vignette(game);
	return (0);
}
