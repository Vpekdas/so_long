/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:58:04 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/20 16:14:16 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	pathfinding_diagonal(int x, int y, t_game *game)
{
	if (game->map_copy.map[y + 1][x] != '1'
		&& game->map_copy.map[y][x + 1] != '1')
		pathfinding(x + 2, y + 1, 0, game);
	if (game->map_copy.map[y + 1][x] != '1'
			&& game->map_copy.map[y][x - 2] != '1')
		pathfinding(x - 2, y + 1, 0, game);
	pathfinding(x, y + 1, 0, game);
	if (game->map_copy.map[y + 1][x] != '1'
		&& game->map_copy.map[y][x + 1] != '1')
		pathfinding(x + 1, y + 1, 0, game);
	if (game->map_copy.map[y + 1][x] != '1'
			&& game->map_copy.map[y][x - 1] != '1')
		pathfinding(x - 1, y + 1, 0, game);
}

void	jmp(int x, int y, int jump, t_game *game)
{
	if (game->map_copy.map[y - 1][x] == '1')
	{
		pathfinding(x, y + 1, 0, game);
		pathfinding(x + 1, y + 1, 0, game);
		pathfinding(x - 1, y + 1, 0, game);
	}
	pathfinding(x, y - 1, jump - 1, game);
	if (game->map_copy.map[y - 1][x] != '1'
		&& game->map_copy.map[y][x + 1] != '1')
		pathfinding(x + 1, y - 1, jump - 1, game);
	pathfinding(x + 1, y, jump - 1, game);
	if (game->map_copy.map[y - 1][x] != '1'
		&& game->map_copy.map[y][x - 1] != '1')
		pathfinding(x - 1, y - 1, jump - 1, game);
	pathfinding(x - 1, y, jump - 1, game);
}

void	fall(int x, int y, int jump, t_game *game)
{
	if (game->map_copy.map[y + 1][x] == '1')
	{
		pathfinding(x, y - 1, jump - 1, game);
		if (game->map_copy.map[y - 1][x] != '1'
		&& game->map_copy.map[y][x + 1] != '1')
			pathfinding(x + 1, y - 1, jump - 1, game);
		if (game->map_copy.map[y - 1][x] != '1'
			&& game->map_copy.map[y][x - 1] != '1')
			pathfinding(x - 1, y - 1, jump - 1, game);
		pathfinding(x + 1, y, 0, game);
		pathfinding(x - 1, y, 0, game);
	}
	pathfinding_diagonal(x, y, game);
}

void	pathfinding(int x, int y, int jump, t_game *game)
{
	int	max_jump;

	max_jump = 3;
	if (x < 0 || x >= game->map_width || y < 0 || y >= game->map_height)
		return ;
	if (game->map_copy.map[y][x] == '.' || game->map_copy.map[y][x] == '1')
		return ;
	if (game->map_copy.map[y][x] == 'C')
		game->accessible_collectibles++;
	if (game->map_copy.map[y][x] == 'E')
		game->accessible_door++;
	game->map_copy.map[y][x] = '.';
	if (jump <= 0)
		fall(x, y, max_jump, game);
	else
		jmp(x, y, jump, game);
}

bool	is_map_finishable(t_game *game)
{
	t_node	*current;

	current = game->collectible_list;
	pathfinding(game->pathfinding.pos_x, game->pathfinding.pos_y, 0, game);
	if (game->accessible_collectibles != game->collectibles_numbers
		|| game->accessible_door == 0)
		return (false);
	reset_pathfinding_accessible(game);
	while (current)
	{
		free_copy_map(game);
		game->map_copy.map = copy_map(game);
		pathfinding(current->pos_x, current->pos_y, 0, game);
		if (game->accessible_door == 0)
			return (false);
		reset_pathfinding_accessible(game);
		current = current->next;
	}
	return (true);
}
