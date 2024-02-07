/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:20:59 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/07 17:42:26 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_update(t_game *game)
{
	suseconds_t	now;

	now = ft_getms();
	if (now - game->last_frame < FRAME_INTERVAL)
		return (0);
	game->last_frame = now;
	game->player.vx = 0;
	ft_detect_key(game);
	game->player.vy += 18 * 0.016;
	ft_move_player(game, game->player.vx, game->player.vy);
	ft_clear_sprite(game->screen, 0x00ffffff); // ((int*)game->mid->data)[0]
	ft_print_map(game->map, game);
	ft_draw_sprite(game, game->spr.player, game->player.x, game->player.y);
	mlx_put_image_to_window(game->mlx, game->win, game->screen, 0, 0);
	return (0);
}
