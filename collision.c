/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:47:50 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/08 15:07:51 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdbool.h>

bool	collide(t_box player, t_box object)
{
	return (player.pos_x < object.pos_x + object.width
		&& player.pos_x + player.width > object.pos_x
		&& player.pos_y < object.pos_y + object.height
		&& player.pos_y + player.height > object.pos_y);
}

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
			if (game->map[y][x] == '1' && collide(a, box) == true)
				return (true);
			y++;
		}
		x++;
	}
	return (false);
}

void	move_player(t_game *game, float velocity_x, float velocity_y)
{
	const float	precision = 0.5;
	const bool	is_velocity_x_positive = velocity_x > 0;
	const bool	is_velocity_y_positive = velocity_y > 0;
	bool		collide_x;
	bool		collide_y;

	collide_x = collide_with_map(player_box_x_off(game, velocity_x), game);
	while (((is_velocity_x_positive && velocity_x > 0) || (!is_velocity_x_positive && velocity_x < 0)) && collide_x)
	{
		if (is_velocity_x_positive)
			velocity_x -= precision;
		else if (!is_velocity_x_positive)
			velocity_x += precision;
	}
	if ((is_velocity_x_positive && velocity_x < 0) || (!is_velocity_x_positive && velocity_x > 0))
		velocity_x = 0;
	game->player.pos_x += velocity_x;
	collide_y = collide_with_map(player_box_y_off(game, velocity_y), game);
	while (((is_velocity_y_positive && velocity_y > 0) || (!is_velocity_y_positive && velocity_y < 0)) && collide_y)
	{
		if (is_velocity_y_positive)
			velocity_y -= precision;
		else if (!is_velocity_y_positive)
			velocity_y += precision;
	}
	if ((is_velocity_y_positive && velocity_y < 0) || (!is_velocity_y_positive && velocity_y > 0))
	{
		velocity_y = 0;
		game->player.velocity_y = 0;
	}
	game->player.pos_y += velocity_y;
}
