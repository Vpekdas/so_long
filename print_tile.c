/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:27:38 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/05 16:28:29 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdbool.h>

bool	isg(t_game *game, char **map, int x, int y)
{
	if (x < 0 || x >= game->map_width || y < 0 || y >= game->map_height)
		return (true);
	return (map[y][x] == '1');
}

void	print_four(t_game *game, t_img *a, t_img *b, t_img *c, t_img *d, int x, int y)
{
	const int	size = 32 * SCALE;
	const int	size2 = 64 * SCALE;

	ft_draw_sprite(game, a, x * size2, y * size2);
	ft_draw_sprite(game, b, x * size2 + size, y * size2);
	ft_draw_sprite(game, c, x * size2, y * size2 + size);
	ft_draw_sprite(game, d, x * size2 + size, y * size2 + size);
}

void	ft_print_tile(t_game *g, char **m, int x, int y)
{
	if (isg(g, m, x - 1, y) && isg(g, m, x + 1, y) && isg(g, m, x, y - 1) && isg(g, m, x, y + 1))
		print_four(g, g->mid, g->mid, g->mid, g->mid, x, y);
	else if (isg(g, m, x - 1, y) && isg(g, m, x + 1, y) && isg(g, m, x, y + 1))
		print_four(g, g->top, g->top, g->mid, g->mid, x, y);
	else if (isg(g, m, x - 1, y) && isg(g, m, x + 1, y) && isg(g, m, x, y - 1))
		print_four(g, g->mid, g->mid, g->bot, g->bot, x, y);
	else if (isg(g, m, x, y - 1) && isg(g, m, x, y + 1) && isg(g, m, x - 1, y))
		print_four(g, g->mid, g->right, g->mid, g->right, x, y);
	else if (isg(g, m, x - 1, y) && isg(g, m, x + 1, y))
		print_four(g, g->top, g->top, g->bot, g->bot, x, y);
	else if (isg(g, m, x, y - 1) && isg(g, m, x, y - 1))
		print_four(g, g->left, g->right, g->left, g->right, x, y);
}

/*

1111111111111
1000000000001
1000000000001
1000000000001
1111111111111

*/
