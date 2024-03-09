/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_chest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:22:02 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/09 16:53:45 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	collide_with_exit_chest(t_box player, t_game *game)
{
	int		x;
	int		y;
	t_box	entity_box;

	y = 0;
	while (y < game->map_width)
	{
		x = 0;
		while (x < game->map_height)
		{
			entity_box = map_box_scale(y, x);
			if (game->map[x][y] && game->map[x][y] == 'E'
				&& collide(player, entity_box) == true)
			{
				if (game->collectibles_numbers == 0)
				{
					mlx_loop_end(game->mlx);
				}
			}
			x++;
		}
		y++;
	}
}
