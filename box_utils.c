/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:18:56 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/08 14:37:14 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_box	player_box_x_off(t_game *game, float velocity_x)
{
	t_box	hitbox;

	hitbox.x = game->player.pos_x + game->player.offset_x + velocity_x;
	hitbox.y = game->player.pos_y + game->player.offset_y;
	hitbox.weight = game->player.width;
	hitbox.height = game->player.height;
	return (hitbox);
}

t_box	player_box_y_off(t_game *game, float velocity_y)
{
	t_box	hitbox;

	hitbox.x = game->player.pos_x + game->player.offset_x;
	hitbox.y = game->player.pos_y + game->player.offset_y + velocity_y;
	hitbox.weight = game->player.width;
	hitbox.height = game->player.height;
	return (hitbox);
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
