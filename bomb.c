/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bomb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:03:12 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/17 16:13:54 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	shoot_bomb(t_game *game)
{
	if (game->bomb.bomb_number == 0)
	{
		game->bomb.bomb_number = 1;
		game->bomb.pos_x = game->player.pos_x;
		game->bomb.pos_y = game->player.pos_y;
		if (game->draw_info.flipped)
			game->bomb.direction = 0;
		else
			game->bomb.direction = 1;
	}
}

void	update_bomb(t_game *game)
{
	t_box	box;

	box = bomb_box(game);
	if (game->bomb.bomb_number == 1)
	{
		if (game->bomb.direction)
			game->bomb.pos_x += game->bomb.speed;
		else
			game->bomb.pos_x -= game->bomb.speed;
		if (collide_with_map(box, game))
		{
			game->bomb.bomb_number = 0;
			return ;
		}
		draw_sprite(game, game->sprite.bomb, game->bomb.pos_x, game->bomb.pos_y);
	}
}