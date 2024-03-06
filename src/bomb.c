/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bomb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:03:12 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/06 18:01:34 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_box	bomb_box(t_game *game)
{
	t_box	box;

	box = (t_box){0};
	box.pos_x = game->bomb.pos_x + game->bomb.speed;
	box.pos_y = game->bomb.pos_y;
	box.width = game->bomb.width;
	box.height = game->bomb.height;
	return (box);
}

void	shoot_bomb(t_game *game)
{
	if (game->bomb.bomb_number == 0)
	{
		game->bomb.bomb_number = 1;
		game->bomb.pos_x = game->play.x;
		game->bomb.pos_y = game->play.y;
		if (game->draw_info.flip)
			game->bomb.direction = 0;
		else
			game->bomb.direction = 1;
	}
}

void	update_bomb(t_game *game)
{
	t_box	box;
	t_box	enemy;
	int		x;
	int		y;

	x = game->bomb.pos_x;
	y = game->bomb.pos_y - 48;
	box = bomb_box(game);
	enemy = enemy_box_y_off(game, game->enemy.velocity_y);
	if (game->bomb.bomb_number == 1)
	{
		if (game->bomb.direction)
			game->bomb.pos_x += game->bomb.speed;
		else
			game->bomb.pos_x -= game->bomb.speed;
		if (collide_with_map(box, game) || collide(enemy, box)
			|| game->bomb.pos_x < 0
			|| game->bomb.pos_x > game->map_width * SCALE * 32)
		{
			game->bomb.bomb_number = 0;
			return ;
		}
		draw_sprite(game, game->sprites[BOMB], x, y);
	}
}
