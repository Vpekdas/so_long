/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:10:20 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/27 17:40:18 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	detect_key(t_game *game)
{
	t_box	box;
	bool	jump;

	if (game->key_esc)
		close_game(game);
	jump = game->player.already_jumped;
	box = player_box_x_y(game);
	if (game->key_w && collide_with_map(box, game) && !jump)
	{
		game->player.velocity_y = -10;
		game->player.already_jumped = true;
	}
	else if (!game->key_w)
		game->player.already_jumped = false;
	if (game->key_s && !collide_with_map(box, game))
		game->player.velocity_y += SPEED;
	if (game->key_a)
		game->player.velocity_x -= SPEED;
	if (game->key_d)
		game->player.velocity_x += SPEED;
	if (game->key_space)
		shoot_bomb(game);
}
