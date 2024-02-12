/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:10:20 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/12 15:50:33 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_pressed(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		mlx_loop_end(game->mlx);
	if (keycode == 'w')
		game->key_w = 1;
	if (keycode == 's')
		game->key_s = 1;
	if (keycode == 'a')
		game->key_a = 1;
	if (keycode == 'd')
		game->key_d = 1;
	return (0);
}

int	key_released(int keycode, t_game *game)
{
	if (keycode == 'w')
		game->key_w = 0;
	if (keycode == 's')
		game->key_s = 0;
	if (keycode == 'a')
		game->key_a = 0;
	if (keycode == 'd')
		game->key_d = 0;
	return (0);
}

t_box	player_box_x_y(t_game *game)
{
	t_box	box;

	box.pos_x = game->player.pos_x + game->player.offset_x;
	box.pos_y = game->player.pos_y + game->player.height - game->player.offset_y;
	box.width = game->player.width;
	box.height = 1;
	return (box);
}

void	detect_key(t_game *game)
{
	t_box	box;
	bool	jump;

	jump = game->player.already_jumped;
	box = player_box_x_y(game);
	if (game->key_w && collide_with_map(box, game) && !jump)
	{
		game->player.velocity_y -= 10;
		game->player.already_jumped = true;
	}
	else if (!game->key_w)
		game->player.already_jumped = false;
	if (game->key_s && !collide_with_map(box, game))
		game->player.velocity_y += SPEED;
	if (game->key_a)
	{
		game->player.velocity_x -= SPEED;
		game->bg1_scroll -= 2;
		game->bg2_scroll -= 4;
		game->water_scroll -= 2;
	}
	if (game->key_d)
	{
		game->player.velocity_x += SPEED;
		game->bg1_scroll += 2;
		game->bg2_scroll += 4;
		game->water_scroll += 2;
	}
}
