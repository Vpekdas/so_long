/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_box.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:18:56 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/06 16:18:42 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
t_box	player_box_x_off(t_game *game, float velocity_x)
{
	t_box	box;

	box = (t_box){0};
	box.pos_x = game->play.x + game->play.offset_x + velocity_x;
	box.pos_y = game->play.y + game->play.offset_y;
	box.width = game->play.width;
	box.height = game->play.height;
	return (box);
}

t_box	player_box_y_off(t_game *game, float velocity_y)
{
	t_box	box;

	box = (t_box){0};
	box.pos_x = game->play.x + game->play.offset_x;
	box.pos_y = game->play.y + game->play.offset_y + velocity_y;
	box.width = game->play.width;
	box.height = game->play.height;
	return (box);
}

t_box	player_box_x_y(t_game *game)
{
	t_box	box;

	box = (t_box){0};
	box.pos_x = game->play.x + game->play.offset_x;
	box.pos_y = game->play.y + game->play.height
		- game->play.offset_y;
	box.width = game->play.width;
	box.height = 1;
	return (box);
}

t_box	player_box_x_y_off(t_game	*game, float velocity_x, float velocity_y)
{
	t_box	box;

	box = (t_box){0};
	box.pos_x = game->play.x + game->play.offset_x + velocity_x;
	box.pos_y = game->play.y - game->play.offset_y + velocity_y;
	box.width = game->play.width;
	box.height = game->play.height;
	return (box);
}

t_box	player_box_x_y_off_below(t_game	*game)
{
	t_box	box;

	box = (t_box){0};
	box.pos_x = game->play.x + game->play.offset_x;
	box.pos_y = game->play.y + game->play.height
		- game->play.offset_y;
	box.width = game->play.width;
	box.height = 1;
	return (box);
}
