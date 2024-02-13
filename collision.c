/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:47:50 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/13 15:28:33 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	collide(t_box player, t_box object)
{
	return (player.pos_x < object.pos_x + object.width
		&& player.pos_x + player.width > object.pos_x
		&& player.pos_y < object.pos_y + object.height
		&& player.pos_y + player.height > object.pos_y);
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

void	adjust_velocity_x(t_game *game, float vx)
{
	const float	precision = 0.5;
	const bool	vx_positive = vx > 0;
	bool		collide_x;

	collide_x = collide_with_map(player_box_x_off(game, vx), game);
	while (((vx_positive && vx > 0) || (!vx_positive && vx < 0)) && collide_x)
	{
		if (vx_positive)
			vx -= precision;
		else if (!vx_positive)
			vx += precision;
	}
	if ((vx_positive && vx < 0) || (!vx_positive && vx > 0))
		vx = 0;
	game->player.pos_x += vx;
}

void	adjust_velocity_y(t_game *game, float vy)
{
	const bool	vy_positive = vy > 0;
	bool		collide_y;
	const float	precision = 0.5;

	collide_y = collide_with_map(player_box_y_off(game, vy), game);
	while (((vy_positive && vy > 0) || (!vy_positive && vy < 0)) && collide_y)
	{
		if (vy_positive)
			vy -= precision;
		else if (!vy_positive)
			vy += precision;
	}
	if ((vy_positive && vy < 0) || (!vy_positive && vy >= 0))
	{
		vy = 0;
		game->player.velocity_y = 0;
	}
	game->player.pos_y += vy;
}
void	move_player(t_game *game, float velocity_x, float velocity_y)
{
	adjust_velocity_x(game, velocity_x);
	adjust_velocity_y(game, velocity_y);
	game->water_scroll = game->player.pos_x * 0.25;
	game->bg2_scroll = game->player.pos_x * 0.25;
	game->bg1_scroll = game->player.pos_x * 0.5;
	game->fg_scroll = game->player.pos_x * 3;
}