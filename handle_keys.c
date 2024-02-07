/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:10:20 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/07 17:18:27 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_pressed(int keycode, t_game *game)
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

int	ft_key_released(int keycode, t_game *game)
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

void	ft_detect_key(t_game *game)
{
	if (game->key_w && ft_collide_with_map((t_box){game->player.x
			+ game->player.ox, game->player.y
			+ game->player.h - game->player.oy, game->player.w, 1}, game) &&
		!game->player.already_jumped)
	{
		game->player.vy -= 25;
		game->player.already_jumped = true;
	}
	else if (!game->key_w)
		game->player.already_jumped = false;
	if (game->key_s && !ft_collide_with_map((t_box){game->player.x
			+ game->player.ox,
			game->player.y + game->player.h - game->player.oy,
			game->player.w, 1}, game))
		game->player.vy += SPEED;
	if (game->key_a)
		game->player.vx -= SPEED;
	if (game->key_d)
		game->player.vx += SPEED;
}
