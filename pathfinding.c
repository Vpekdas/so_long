/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:58:04 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/23 14:54:10 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pathfinding(int x, int y, char **map, int jump, t_game *game, int depth)
{
	int max_jump = 3;
	if (x < 0 || x >= game->map_width || y < 0 || y >= game->map_height)
		return ;
	if (map[y][x] == '.' || map[y][x] == '1')
		return ;
	if (map[y][x] == 'C')
		game->accessible_collectibles++;
	if (map[y][x] == 'E')
		game->accessible_door++;
	if (depth > 25)
		depth = 0;
	map[y][x] = '.';
	if (jump <= 0)
	{
		if (map[y + 1][x] == '1')
		{
			pathfinding(x, y - 1, map, max_jump, game, depth + 1);
			pathfinding(x + 1, y - 1, map, max_jump, game, depth + 1);
			pathfinding(x - 1, y - 1, map, max_jump, game, depth + 1);
			pathfinding(x + 1, y, map, 0, game, depth + 1);
			pathfinding(x - 1, y, map, 0, game, depth + 1);
		}
		pathfinding(x, y + 1, map, 0, game, depth + 1);
		pathfinding(x + 1, y + 1, map, 0, game, depth + 1);
		pathfinding(x - 1, y + 1, map, 0, game, depth + 1);
		pathfinding(x + 2, y + 1, map, 0, game, depth + 1);
		pathfinding(x - 2, y + 1, map, 0, game, depth + 1);
	}
	else
	{
		pathfinding(x, y - 1, map, jump - 1, game, depth + 1);
		pathfinding(x + 1, y - 1, map, jump - 1, game, depth + 1);
		pathfinding(x - 1, y - 1, map, jump - 1, game, depth + 1);
		pathfinding(x + 1, y, map, jump - 1, game, depth + 1);
		pathfinding(x - 1, y, map, jump - 1, game, depth + 1);
		if (map[y - 1][x] == '1')
		{
			pathfinding(x, y + 1, map, 0, game, depth + 1);
			pathfinding(x + 1, y + 1, map, 0, game, depth + 1);
			pathfinding(x - 1, y + 1, map, 0, game, depth + 1);
		}
	}
}
