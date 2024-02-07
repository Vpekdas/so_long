/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:47:50 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/07 16:39:29 by vopekdas         ###   ########.fr       */
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
			if (game->map[y][x] == '1' && ft_collide(a, (t_box){x * 32 * SCALE,
				y * 32 * SCALE, 32 * SCALE, 32 * SCALE}))
				return (true);
			y++;
		}
		x++;
	}
	return (false);
}

void	ft_move_player(t_game *game, float vx, float vy)
{
	const float	precision = 0.5;
	const bool	greater_than_zero_x = vx > 0;
	const bool	greater_than_zero_y = vy > 0;

	while (((greater_than_zero_x && vx > 0) || (!greater_than_zero_x && vx <= 0))
		&& ft_collide_with_map((t_box){game->x + game->ox + vx, game->y + game->oy, game->w, game->h}, game))
	{
		if (greater_than_zero_x)
			vx -= precision;
		else if (!greater_than_zero_x)
			vx += precision;
	}
	if ((greater_than_zero_x && vx < 0) || (!greater_than_zero_x && vx > 0))
		vx = 0;
	game->x += vx;
	while (((greater_than_zero_y && vy > 0) || (!greater_than_zero_y && vy <= 0))
		&& ft_collide_with_map((t_box){game->x + game->ox, game->y + game->oy + vy, game->w, game->h}, game))
	{
		// printf("2. vy = %f\n", vy);
		if (greater_than_zero_y)
			vy -= precision;
		else if (!greater_than_zero_y)
			vy += precision;
	}
	if ((greater_than_zero_y && vy < 0) || (!greater_than_zero_y && vy > 0))
	{
		game->vy = 0;
		vy = 0;
	}
	game->y += vy;
}
