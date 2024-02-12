/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:22:02 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/12 13:35:14 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collide_with_exit_door(t_box player, t_game *game)
{
	int		x;
	int		y;
	t_box	entity_box;

	x = 0;
	while (x < game->map_width)
	{
		y = 0;
		while (y < game->map_height)
		{
			entity_box = map_box_scale(x, y);
			if (game->map[y][x] == 'D' && collide(player, entity_box) == true)
			{
				if (game->collectibles_numbers == 0)
				{
					mlx_loop_end(game->mlx);
				}
			}
			y++;
		}
		x++;
	}
}

void	draw_door(t_game *g, int x, int y)
{
	draw_sprite(g, g->sprite.door, x * 32 * SCALE, y * 32 * SCALE);
}
