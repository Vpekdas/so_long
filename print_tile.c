/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:27:38 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/08 14:27:36 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	isg(t_game *game, char **map, int x, int y)
{
	if (x < 0 || x >= game->map_width || y < 0 || y >= game->map_height)
		return (true);
	return (map[y][x] == '1');
}

void	print_tile(t_game *g, char **m, int x, int y)
{
	if (y == 0 || x == 0 || x == g->map_width - 1)
		return ;
	if (isg(g, m, x - 1, y) && isg(g, m, x + 1, y) && y == g->map_height - 1)
		draw_sprite(g, g->spr.top, x * 32 * SCALE, y * 32 * SCALE);
	else if (isg(g, m, x - 1, y)
		&& isg(g, m, x, y - 1) && isg(g, m, x, y + 1) && x == 0)
		draw_sprite(g, g->spr.right, x * 32 * SCALE, y * 32 * SCALE);
	else if (isg(g, m, x + 1, y) && isg(g, m, x, y - 1)
		&& isg(g, m, x, y + 1) && x == g->map_width - 1)
		draw_sprite(g, g->spr.left, x * 32 * SCALE, y * 32 * SCALE);
	else if (isg(g, m, x, y - 1))
		draw_sprite(g, g->spr.top_left, x * 32 * SCALE, y * 32 * SCALE);
	else if (isg(g, m, x, y + 1))
		draw_sprite(g, g->spr.top_left, x * 32 * SCALE, y * 32 * SCALE);
	else if (isg(g, m, x - 1, y) && isg(g, m, x + 1, y))
		draw_sprite(g, g->spr.top_left, x * 32 * SCALE, y * 32 * SCALE);
	else if (isg(g, m, x - 1, y))
		draw_sprite(g, g->spr.top_left, x * 32 * SCALE, y * 32 * SCALE);
	else if (isg(g, m, x + 1, y))
		draw_sprite(g, g->spr.top_left, x * 32 * SCALE, y * 32 * SCALE);
}
