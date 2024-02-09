/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:18:56 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/09 17:46:20 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_box	player_box_x_off(t_game *game, float velocity_x)
{
	t_box	box;

	box.pos_x = game->player.pos_x + game->player.offset_x + velocity_x;
	box.pos_y = game->player.pos_y + game->player.offset_y;
	box.width = game->player.width;
	box.height = game->player.height;
	return (box);
}

t_box	player_box_y_off(t_game *game, float velocity_y)
{
	t_box	box;

	box.pos_x = game->player.pos_x + game->player.offset_x;
	box.pos_y = game->player.pos_y + game->player.offset_y + velocity_y;
	box.width = game->player.width;
	box.height = game->player.height;
	return (box);
}
t_box	player_box_x_y_off(t_game	*game, float velocity_x, float velocity_y)
{
	t_box	box;

	box.pos_x = game->player.pos_x + game->player.offset_x + velocity_x;
	box.pos_y = game->player.pos_y + game->player.offset_y + velocity_y;
	box.width = game->player.width;
	box.height = game->player.height;
	return (box);
}

t_box	map_box_scale(int x, int y)
{
	t_box	box;

	box.pos_x = x * 32 * SCALE;
	box.pos_y = y * 32 * SCALE;
	box.width = 32 * SCALE;
	box.height = 32 * SCALE;
	return (box);
}

