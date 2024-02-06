/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:47:50 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/06 15:57:50 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

bool	ft_collide(t_box a, t_box b)
{
	return (a.x < b.x + b.w &&
		a.x + a.w > b.x &&
		a.y < b.y + b.h &&
		a.y + a.h > b.y);
}

bool	ft_collide_with_map(t_box a, t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_width)
	{
		y = 0;
		while (y < game->map_height)
		{
			if (game->map[y][x] == '1'
				&& ft_collide(a, (t_box){x * 32 * SCALE, y * 32 * SCALE, 32 * SCALE, 32 * SCALE}))
				return (true);
			y++;
		}
		x++;
	}
	return (false);
}