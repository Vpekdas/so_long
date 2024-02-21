/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:58:04 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/21 19:55:31 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pathfinding(int x, int y, char **map, int jump, t_game *game, int depth)
{
	if (x < 0 || x >= game->map_width || y < 0 || y >= game->map_height)
		return ;
	int max_jump = 2;
	if ('a' <= map[y][x] && map[y][x] <= 'z')
		return ;
	if (map[y][x] == '.' || map[y][x] == '1')
		return ;
	if (map[y][x] == 'C')
		game->accessible_collectibles++;
	if (depth > 25)
		depth = 0;
	// map[y][x] = 'a' + depth;
	map[y][x] = '.';

	if (jump <= 0)
	{
		if (map[y + 1][x] == '1')
		{
			pathfinding(x, y - 1, map, max_jump, game, depth+1);
			pathfinding(x + 1, y - 1, map, max_jump, game, depth+1);
			pathfinding(x - 1, y - 1, map, max_jump, game, depth+1);
			pathfinding(x + 1, y, map, 0, game, depth+1);
			pathfinding(x - 1, y, map, 0, game, depth+1);
		}
		pathfinding(x, y + 1, map, 0, game, depth+1);
		pathfinding(x + 1, y + 1, map, 0, game, depth+1);
		pathfinding(x - 1, y + 1, map, 0, game, depth+1);
		pathfinding(x + 2, y + 1, map, 0, game, depth+1);
		pathfinding(x - 2, y + 1, map, 0, game, depth+1);
	}
	else
	{
		pathfinding(x, y - 1, map, jump - 1, game, depth+1);
		pathfinding(x + 1, y - 1, map, jump - 1, game, depth+1);
		pathfinding(x - 1, y - 1, map, jump - 1, game, depth+1);
		pathfinding(x + 1, y, map, jump - 1, game, depth+1);
		pathfinding(x - 1, y, map, jump - 1, game, depth+1);
		if (map[y - 1][x] == '1')
		{
			pathfinding(x, y + 1, map, 0, game, depth+1);
			pathfinding(x + 1, y + 1, map, 0, game, depth+1);
			pathfinding(x - 1, y + 1, map, 0, game, depth+1);
		}
	}
}

void	ntm(int x, int y, char **map, int jump, t_game *game, int depth)
{
	if (x < 0 || x >= game->map_width || y < 0 || y >= game->map_height)
		return ;
	int max_jump = 2;
	if ('a' <= map[y][x] && map[y][x] <= 'z')
		return ;
	if (map[y][x] == '.' || map[y][x] == '1')
		return ;
	if (map[y][x] == 'C')
		game->accessible_collectibles++;
	if (depth > 25)
		depth = 0;
	// map[y][x] = 'a' + depth;
	map[y][x] = '.';

	if (jump <= 0)
	{
		if (map[y + 1][x] == '1')
		{
			pathfinding(x, y - 1, map, max_jump, game, depth+1);
			pathfinding(x + 1, y - 1, map, max_jump, game, depth+1);
			pathfinding(x - 1, y - 1, map, max_jump, game, depth+1);
			pathfinding(x + 1, y, map, 0, game, depth+1);
			pathfinding(x - 1, y, map, 0, game, depth+1);
		}
		pathfinding(x, y + 1, map, 0, game, depth+1);
		pathfinding(x + 1, y + 1, map, 0, game, depth+1);
		pathfinding(x - 1, y + 1, map, 0, game, depth+1);
		pathfinding(x + 2, y + 1, map, 0, game, depth+1);
		pathfinding(x - 2, y + 1, map, 0, game, depth+1);
	}
	else
	{
		pathfinding(x, y - 1, map, jump - 1, game, depth+1);
		pathfinding(x + 1, y - 1, map, jump - 1, game, depth+1);
		pathfinding(x - 1, y - 1, map, jump - 1, game, depth+1);
		pathfinding(x + 1, y, map, jump - 1, game, depth+1);
		pathfinding(x - 1, y, map, jump - 1, game, depth+1);
		if (map[y - 1][x] == '1')
		{
			pathfinding(x, y + 1, map, 0, game, depth+1);
			pathfinding(x + 1, y + 1, map, 0, game, depth+1);
			pathfinding(x - 1, y + 1, map, 0, game, depth+1);
		}
	}
}