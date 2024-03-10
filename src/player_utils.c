/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:45:32 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/10 16:53:39 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	find_player_position(t_game *game, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (map[y][x] && map[y][x] == 'P')
			{
				game->play.x = (x - 1) * SPRITE_SIZE * SCALE;
				game->play.y = y * SPRITE_SIZE * SCALE;
				game->pathfinding.pos_x = x;
				game->pathfinding.pos_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
