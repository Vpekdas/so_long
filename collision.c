/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:47:50 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/08 14:38:02 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	collide_with_map(t_box a, t_game *game)
{
	int		x;
	int		y;
	t_box	box;

	x = 0;
	while (x < game->map_width)
	{
		y = 0;
		while (y < game->map_height)
		{
			box = map_box_scale(x, y);
			if (game->map[y][x] == '1' && collide(a, box))
				return (true);
			y++;
		}
		x++;
	}
	return (false);
}

void	move_player(t_game *game, float vx, float vy)
{
	const float	precision = 0.5;
	const bool	greater_than_zero_x = vx > 0;
	const bool	greater_than_zero_y = vy > 0;
	bool		collide_x;
	bool		collide_y;

	collide_x = collide_with_map(player_box_x_off(game, vx), game);
	while (((greater_than_zero_x && vx > 0) || (!greater_than_zero_x && vx <= 0)) && collide_x == true)
	{
		if (greater_than_zero_x)
			vx -= precision;
		else if (!greater_than_zero_x)
			vx += precision;
	}
	if ((greater_than_zero_x && vx < 0) || (!greater_than_zero_x && vx > 0))
		vx = 0;
	game->player.pos_x += vx;
	collide_y = collide_with_map(player_box_y_off(game, vy), game);
	while (((greater_than_zero_y && vy > 0) || (!greater_than_zero_y && vy <= 0)) && collide_y == true)
	{
		if (greater_than_zero_y)
			vy -= precision;
		else if (!greater_than_zero_y)
			vy += precision;
	}
	if ((greater_than_zero_y && vy < 0) || (!greater_than_zero_y && vy > 0))
	{
		vy = 0;
		game->player.velocity_y = 0;
	}
	game->player.pos_y += vy;
}
