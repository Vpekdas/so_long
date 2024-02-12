/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:19:50 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/12 16:32:43 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collide_with_collectible(t_box player, t_game *game)
{
	int		x;
	int		y;
	t_box	entity_box;

	y = 0;
	while (y < game->map_height - 1)
	{
		x = 0;
		while (x < game->map_width - 1)
		{
			entity_box = map_box_scale(x, y);
			if (game->map[y][x] == 'C' && collide(player, entity_box) == true)
			{
				game->map[y][x] = '0';
				game->collectibles_numbers--;
			}
			x++;
		}
		y++;
	}
}
int	find_collectible_numbers(t_game *game, char **map)
{
	int	x;
	int	y;
	int	collectibles_numbers;

	y = 0;
	collectibles_numbers = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (map[y][x] == 'C')
				collectibles_numbers++;
			x++;
		}
		y++;
	}
	return (collectibles_numbers);
}
void	draw_collectible(t_game *g, int x, int y)
{
	draw_sprite(g, g->sprite.collectible, x * 32 * SCALE, y * 32 * SCALE );
}
