/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:27:38 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/05 16:06:02 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_wall(t_game *game, char **map, int x, int y)
{
	if (x < 0 || x >= game->map_width || y < 0 || y >= game->map_height)
		return (false);
	return (map[y][x] == '1');
}

void	draw_tile(t_game *g, char **m, int x, int y)
{
	if (y == 0 || x == 0 || x == g->map_width - 1)
		return ;
	if (is_wall(g, m, x - 1, y) && is_wall(g, m, x + 1, y)
		&& is_wall(g, m, x, y + 1) && is_wall(g, m, x, y - 1))
		draw_sprite(g, g->sprites[MID], x * 32 * SCALE, y * 32 * SCALE);
	else if (is_wall(g, m, x - 1, y) && is_wall(g, m, x + 1, y)
		&& is_wall(g, m, x, y + 1))
		draw_sprite(g, g->sprites[TOP], x * 32 * SCALE, y * 32 * SCALE);
	else if (is_wall(g, m, x - 1, y) && is_wall(g, m, x, y - 1)
		&& is_wall(g, m, x, y + 1))
		draw_sprite(g, g->sprites[RIGHT], x * 32 * SCALE, y * 32 * SCALE);
	else if (is_wall(g, m, x, y - 1) && is_wall(g, m, x, y + 1))
		draw_sprite(g, g->sprites[LEFT], x * 32 * SCALE, y * 32 * SCALE);
	else if (is_wall(g, m, x + 1, y) && is_wall(g, m, x, y + 1))
		draw_sprite(g, g->sprites[TOP_LEFT], x * 32 * SCALE, y * 32 * SCALE);
	else if (is_wall(g, m, x - 1, y) && is_wall(g, m, x, y + 1))
		draw_sprite(g, g->sprites[TOP_RIGHT], x * 32 * SCALE, y * 32 * SCALE);
	else if (is_wall(g, m, x, y + 1))
		draw_sprite(g, g->sprites[TL], x * 32 * SCALE, y * 32 * SCALE);
	else
		draw_sprite(g, g->sprites[TOP], x * 32 * SCALE, y * 32 * SCALE);
}
