/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:41:00 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/07 15:34:39 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

suseconds_t	ft_getms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	ft_close(t_game *game)
{
	mlx_loop_end(game->mlx);
	return (0);
}

int	ft_update(t_game *game)
{
	suseconds_t	now;

	now = ft_getms();
	if (now - game->last_frame < FRAME_INTERVAL)
		return (0);
	game->last_frame = now;
	game->vx = 0;
	if (game->key_w)
		game->vy -= 4;
	if (game->key_s)
		game->vy += SPEED;
	if (game->key_a)
		game->vx -= SPEED;
	if (game->key_d)
		game->vx += SPEED;
	game->vy += 8 * 0.016;
	ft_move_player(game, game->vx, game->vy);
	ft_clear_sprite(game->screen, 0x00ffffff); // ((int*)game->mid->data)[0]
	ft_print_map(game->map, game);
	ft_draw_sprite(game, game->sprite.player, game->x, game->y);
	mlx_put_image_to_window(game->mlx, game->win, game->screen, 0, 0);
	return (0);
}

int	main(void)
{
	t_game		game;

	ft_bzero(&game, sizeof(t_game));

	game.x = 128;
	game.y = 128;
	game.w = 24 * SCALE;
	game.h = 60 * SCALE;
	game.ox = 32 * SCALE;
	game.oy = 0;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 1280, 720, "so_long");
	game.screen = mlx_new_image(game.mlx, 1280, 720);
	game.map = ft_parse_map(&game, "maps/map.ber");

	ft_init_sprite(&game);
	mlx_loop_hook(game.mlx, ft_update, &game);
	mlx_hook(game.win, KeyPress, KeyPressMask, ft_key_pressed, &game);
	mlx_hook(game.win, KeyRelease, KeyReleaseMask, ft_key_released, &game);
	mlx_hook(game.win, DestroyNotify, ButtonPressMask, ft_close, &game);
	mlx_loop(game.mlx);
	mlx_destroy_window(game.mlx, game.win);
}
