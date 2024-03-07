/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:47:50 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/07 13:06:05 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	collide(t_box player, t_box object)
{
	return (player.pos_x < object.pos_x + object.width
		&& player.pos_x + player.width > object.pos_x
		&& player.pos_y < object.pos_y + object.height
		&& player.pos_y + player.height > object.pos_y);
}

t_box	map_box_scale(int x, int y)
{
	t_box	box;

	box.pos_x = x * 32 * SCALE;
	box.pos_y = y * 32 * SCALE;
	box.width = 32;
	box.height = 32;
	return (box);
}

bool	collide_with_map(t_box player, t_game *game)
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
			if (game->map[y][x] == '1' && collide(player, entity_box) == true)
				return (true);
			y++;
		}
		x++;
	}
	return (false);
}

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
