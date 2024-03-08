/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:19:36 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/08 16:24:16 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_enemy(t_game *game)
{
	game->enemy.width = 28 * SCALE;
	game->enemy.height = 80 * SCALE;
	game->enemy.offset_x = SPRITE_SIZE * SCALE;
	game->enemy.offset_y = 0;
	game->enemy.health = 3;
}

int	init_player_and_map(t_game *game)
{
	game->play.width = 22 * SCALE;
	game->play.height = 29 * SCALE;
	game->play.offset_x = 37 * SCALE;
	game->play.offset_y = 0;
	game->play.health = 3;
	init_enemy(game);
	game->bomb.speed = 15;
	game->bomb.height = SPRITE_SIZE;
	game->bomb.width = SPRITE_SIZE;
	game->bomb.offset_y = 48;
	game->map = parse_map(game, game->map_path);
	if (!game->map)
		return (-1);
	find_player_position(game, game->map);
	find_enemy_position(game, game->map);
	game->collectibles_numbers = find_collectible_numbers(game, game->map);
	game->bubble_list = create_list_bubble(game);
	game->collectible_list = create_list_collectible(game);
	game->map_copy.map = copy_map(game);
	return (0);
}
