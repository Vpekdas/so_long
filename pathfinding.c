/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:58:04 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/21 15:23:33 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	pathfinding(int x, int y, char **map, int max_jump, t_game game)
{
	if (x < 0 || y < 0 || ((map[x][y]) != '0' && (map[x][y]) != 'P' && (map[x][y]) != 'C'
		&& (map[x][y]) != 'D'))
		return (false);
	map[x][y] = 'X';
	pathfinding(x, y + 1, map, max_jump, game);
	pathfinding(x - 1, y, map, max_jump, game);
	pathfinding(x + 1, y, map, max_jump, game);

	return (true);
}