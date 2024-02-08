/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:18:56 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/08 14:21:35 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_box	player_box_x_off(t_game *game, float vx)
{
	t_box	hitbox;

	hitbox.x = game->player.x + game->player.ox + vx;
	hitbox.y = game->player.y + game->player.oy;
	hitbox.weight = game->player.w;
	hitbox.height = game->player.h;
	return (hitbox);
}

t_box	player_box_y_off(t_game *game, float vy)
{
	t_box	hitbox;

	hitbox.x = game->player.x + game->player.ox;
	hitbox.y = game->player.y + game->player.oy + vy;
	hitbox.weight = game->player.w;
	hitbox.height = game->player.h;
	return (hitbox);
}

t_box	map_box_scale(int x, int y)
{
	t_box	box;

	box.x = x * 32 * SCALE;
	box.y = y * 32 * SCALE;
	box.height = 32 * SCALE;
	box.weight = 32 * SCALE;
	return (box);
}

bool	collide(t_box player, t_box object)
{
	return (player.x < object.x + object.weight
		&& player.x + player.weight > object.x
		&& player.y < object.y + object.height
		&& player.y + player.height > object.y);
}
