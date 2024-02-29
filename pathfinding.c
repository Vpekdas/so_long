/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:58:04 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/29 14:44:52 by vopekdas         ###   ########.fr       */
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
bool	is_map_finishable(t_game *game)
{
	t_node	*current;

	current = game->collectible_list;
	pathfinding(game->pathfinding.pos_x, game->pathfinding.pos_y, game->map_copy.map, 0, game, 0);
	if (game->accessible_collectibles != game->collectibles_numbers && game->accessible_door == 0)
		return (false);
	game->accessible_collectibles = 0;
	game->accessible_door = 0;
	while (current)
	{
		free_copy_map(game);
		game->map_copy.map = copy_map(game);
		pathfinding(current->pos_x, current->pos_y, game->map_copy.map, 0, game, 0);
		if (game->accessible_door == 0)
			return (false);
		game->accessible_collectibles = 0;
		game->accessible_door = 0;
		current = current->next;
	}
	return (true);
}
