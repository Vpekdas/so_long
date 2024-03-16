/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bomb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:03:12 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/16 16:05:17 by vopekdas         ###   ########.fr       */
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

void	update_explotion_state(t_game *game)
{
	game->bomb.is_exploding = true;
	game->bomb.explo_x = game->bomb.pos_x;
	game->bomb.explo_y = game->bomb.pos_y;
	game->bomb.bomb_number = 0;
	game->bomb.pos_x = 0;
	game->bomb.pos_y = -100;
}

void	update_bomb(t_game *game)
{
	t_box			box;
	t_box			enemy;
	t_enemy_list	*index;

	box = bomb_box(game);
	index = game->enemy_list;
	if (game->bomb.bomb_number == 1)
	{
		if (game->bomb.direction)
			game->bomb.pos_x += game->bomb.speed;
		else
			game->bomb.pos_x -= game->bomb.speed;
		while (index)
		{
			enemy = enemy_box_y_off(index);
			if (collide(box, enemy) || collide_with_map(box, game)
				|| game->bomb.pos_x < 0
				|| game->bomb.pos_x > game->map_width * SCALE * SPRITE_SIZE)
				return (update_explotion_state(game));
			index = index->next;
		}
		draw_sprite(game, game->sprites[BOMB], game->bomb.pos_x,
			game->bomb.pos_y - game->bomb.offset_y);
	}
}
