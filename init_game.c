/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:19:36 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/17 16:39:47 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player_and_map(t_game *game)
{
	game->player.width = 28 * SCALE;
	game->player.height = 58 * SCALE;
	game->player.offset_x = 32 * SCALE;
	game->player.offset_y = 0;
	game->bomb.speed = 15;
	game->map = parse_map(game, "maps/map.ber");
	find_player_position(game, game->map);
	game->collectibles_numbers = find_collectible_numbers(game, game->map);

}
