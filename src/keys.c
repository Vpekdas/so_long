/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:10:20 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/08 16:24:31 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_pressed(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		game->key_esc = 1;
	if (keycode == 'w' || keycode == XK_Up)
		game->key_w = 1;
	if (keycode == 's' || keycode == XK_Down)
		game->key_s = 1;
	if (keycode == 'a' || keycode == XK_Left)
		game->key_a = 1;
	if (keycode == 'd' || keycode == XK_Right)
		game->key_d = 1;
	if (keycode == XK_space)
		game->key_space = 1;
	return (0);
}

int	key_released(int keycode, t_game *game)
{
	if (keycode == 'w' || keycode == XK_Up)
		game->key_w = 0;
	if (keycode == 's' || keycode == XK_Down)
		game->key_s = 0;
	if (keycode == 'a' || keycode == XK_Left)
		game->key_a = 0;
	if (keycode == 'd' || keycode == XK_Right)
		game->key_d = 0;
	if (keycode == XK_space)
		game->key_space = 0;
	return (0);
}

void	detect_key_two(t_game *game)
{
	if (game->key_a)
	{
		game->play.velocity_x -= SPEED;
		game->is_trail_drawn = false;
		if (game->move_count >= SPRITE_SIZE * SCALE)
		{
			game->move_count = 0;
			game->step_count++;
		}
	}
	if (game->key_d)
	{
		game->play.velocity_x += SPEED;
		game->is_trail_drawn = false;
		if (game->move_count >= SPRITE_SIZE * SCALE)
		{
			game->move_count = 0;
			game->step_count++;
		}
	}
	if (game->key_space)
		shoot_bomb(game);
}

void	detect_key(t_game *game)
{
	t_box	box;
	bool	jump;

	if (game->key_esc)
		close_game(game);
	jump = game->play.already_jumped;
	box = player_box_x_y(game);
	if (game->key_w && collide_with_map(box, game) && !jump)
	{
		game->play.velocity_y = -10;
		game->play.already_jumped = true;
		game->is_trail_drawn = false;
		game->step_count++;
	}
	else if (!game->key_w)
		game->play.already_jumped = false;
	if (game->key_s && !collide_with_map(box, game))
	{
		game->play.velocity_y += 2;
		game->is_trail_drawn = false;
		game->step_count++;
	}
	detect_key_two(game);
}
