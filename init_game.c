/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:19:36 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/29 14:42:54 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_enemy(t_game *game)
{
	game->enemy.width = 28 * SCALE;
	game->enemy.height = 80 * SCALE;
	game->enemy.offset_x = 32 * SCALE;
	game->enemy.offset_y = 0;
	game->enemy.health = 3;
}

void	init_player_and_map(t_game *game)
{
	game->player.width = 22 * SCALE;
	game->player.height = 29 * SCALE;
	game->player.offset_x = 37 * SCALE;
	game->player.offset_y = 0;
	game->player.health = 3;
	init_enemy(game);
	game->bomb.speed = 15;
	game->bomb.height = 16;
	game->bomb.width = 16;
	game->map = parse_map(game, game->map_path);
	find_player_position(game, game->map);
	find_enemy_position(game, game->map);
	game->collectibles_numbers = find_collectible_numbers(game, game->map);
	game->bubble_list = create_list_bubble(game);
	game->collectible_list = create_list_collectible(game);
	game->map_copy.map = copy_map(game);
}

