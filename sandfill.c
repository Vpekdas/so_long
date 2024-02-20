/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandfill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:58:04 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/20 18:49:40 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sand_fill(int x, int y, char **map, int max_jump, t_game game)
{
	if (x < 0 || y < 0 || (map[x][y] != '0' && map[x][y] != 'D' && map[x][y] != 'P' && map[x][y] != 'C'))
		return ;
	map[x][y] = 'X';
	sand_fill(x - 1, y, map, max_jump, game);
	sand_fill(x + 1, y, map, max_jump, game);
	sand_fill(x, y + 1, map, max_jump, game);
	sand_fill(x, y - 1, map, --max_jump, game);
}