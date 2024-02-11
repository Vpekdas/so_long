/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:19:50 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/11 16:01:39 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collide_with_collectible(t_box player, t_game *game)
{
	int		x;
	int		y;
	t_box	entity_box;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
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
