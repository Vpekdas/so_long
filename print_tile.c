/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:27:38 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/14 19:31:01 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_wall(t_game *game, char **map, int x, int y)
{
	if (x < 0 || x >= game->map_width || y < 0 || y >= game->map_height)
		return (true);
	return (map[y][x] == '1');
}

void	draw_tile(t_game *g, char **m, int x, int y)
{
	if (y == 0 || x == 0 || x == g->map_width - 1)
		return ;
	if (is_wall(g, m, x - 1, y) && is_wall(g, m, x + 1, y)
		&& is_wall(g, m, x, y + 1))
		draw_sprite(g, g->sprite.top, x * 32 * SCALE, y * 32 * SCALE);
	else
	 	draw_sprite(g, g->sprite.top, x * 32 * SCALE, y * 32 * SCALE);
}
