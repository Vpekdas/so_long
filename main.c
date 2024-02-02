/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:41:00 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/02 18:22:47 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
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
	if (game->key_w)
		game->y -= SPEED;
	if (game->key_s)
		game->y += SPEED;
	if (game->key_a)
		game->x -= SPEED;
	if (game->key_d)
		game->x += SPEED;
	ft_clear_sprite(game->screen, 0x0);
	ft_draw_sprite(game, game->player, game->x, game->y);
	ft_draw_sprite(game, game->hat, game->x, game->y - 16 * SCALE);
	mlx_put_image_to_window(game->mlx, game->win, game->screen, 0, 0);
	return (0);
}

int	main(void)
{
	t_game	game;
	int height = 100;
	int width = 100;

	ft_bzero(&game, sizeof(t_game));
	game.x = 640;
	game.y = 360;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 1280, 720, "so_long");
	game.screen = mlx_new_image(game.mlx, 1280, 720);
	game.player = mlx_xpm_file_to_image(game.mlx, "characters/red_pirate.xpm", &width, &height);
	game.hat = mlx_xpm_file_to_image(game.mlx, "accessories/pirate_hat.xpm", &width, &height);

	mlx_do_key_autorepeatoff(game.mlx);
	mlx_loop_hook(game.mlx, ft_update, &game);
	mlx_hook(game.win, KeyPress, KeyPressMask, ft_key_pressed, &game);
	mlx_hook(game.win, KeyRelease, KeyReleaseMask, ft_key_released, &game);
	mlx_hook(game.win, DestroyNotify, ButtonPressMask, ft_close, &game);
	mlx_loop(game.mlx);
	mlx_do_key_autorepeaton(game.mlx);
	mlx_destroy_window(game.mlx, game.win);
}
