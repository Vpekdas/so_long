/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:10:20 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/08 14:38:58 by vopekdas         ###   ########.fr       */
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

void	detect_key(t_game *game)
{
	if (game->key_w && collide_with_map((t_box){game->player.pos_x
			+ game->player.offset_x, game->player.pos_y
			+ game->player.height - game->player.offset_y, game->player.width, 1}, game) &&
		!game->player.already_jumped)
	{
		game->player.velocity_y -= 10;
		game->player.already_jumped = true;
	}
	else if (!game->key_w)
		game->player.already_jumped = false;
	if (game->key_s && !collide_with_map((t_box){game->player.pos_x
			+ game->player.offset_x,
			game->player.pos_y + game->player.height - game->player.offset_y,
			game->player.width, 1}, game))
		game->player.velocity_y += SPEED;
	if (game->key_a)
		game->player.velocity_x -= SPEED;
	if (game->key_d)
		game->player.velocity_x += SPEED;
}
