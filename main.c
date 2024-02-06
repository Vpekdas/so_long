/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:41:00 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/06 16:14:01 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf/include/ft_printf.h"
#include "minilibx-linux/mlx.h"
#include "so_long.h"
#include <stdbool.h>

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

void	ft_move_player(t_game *game, int vx, int vy)
{
	while (vx != 0 && ft_collide_with_map((t_box){game->x + game->ox + vx, game->y + game->oy, game->w, game->h}, game))
	{
		if (vx > 0)
			vx--;
		else if (vx < 0)
			vx++;
	}
	game->x += vx;
	while (vy != 0 && ft_collide_with_map((t_box){game->x + game->ox, game->y + game->oy + vy, game->w, game->h}, game))
	{
		if (vy > 0)
			vy--;
		else if (vy < 0)
			vy++;
	}
	game->y += vy;
}

int	ft_update(t_game *game)
{
	suseconds_t	now;
	bool		collision;
	int			vx;
	int			vy;

	now = ft_getms();
	if (now - game->last_frame < FRAME_INTERVAL)
		return (0);
	game->last_frame = now;
	vx = 0;
	vy = 0;
	if (game->key_w)
		vy -= 8;
	if (game->key_s)
		vy += SPEED;
	if (game->key_a)
		vx -= SPEED;
	if (game->key_d)
		vx += SPEED;
	vy += 4;
	ft_move_player(game, vx, vy);
	ft_clear_sprite(game->screen, 0x00ffffff); // ((int*)game->mid->data)[0]
	ft_print_map(game->map, game);
	ft_draw_sprite(game, game->player, game->x, game->y);
	mlx_put_image_to_window(game->mlx, game->win, game->screen, 0, 0);
	return (0);
}

int	main(void)
{
	t_game	game;
	int height = 100;
	int width = 100;

	ft_bzero(&game, sizeof(t_game));
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 1280, 720, "so_long");
	game.screen = mlx_new_image(game.mlx, 1280, 720);
	game.player = mlx_xpm_file_to_image(game.mlx, "Idle_1.xpm", &width, &height);
	game.top_left = mlx_xpm_file_to_image(game.mlx, "textures/Background Cave/final_xpm/top_left.xpm", &width, &height);
	game.top = mlx_xpm_file_to_image(game.mlx, "textures/Background Cave/final_xpm/top.xpm", &width, &height);
	game.top_right = mlx_xpm_file_to_image(game.mlx, "textures/Background Cave/final_xpm/top_right.xpm", &width, &height);
	game.left = mlx_xpm_file_to_image(game.mlx, "textures/Background Cave/final_xpm/left.xpm", &width, &height);
	game.mid = mlx_xpm_file_to_image(game.mlx, "textures/Background Cave/final_xpm/mid.xpm", &width, &height);
	game.right = mlx_xpm_file_to_image(game.mlx, "textures/Background Cave/final_xpm/right.xpm", &width, &height);
	game.bot_left = mlx_xpm_file_to_image(game.mlx, "textures/Background Cave/final_xpm/bot_left.xpm", &width, &height);
	game.bot = mlx_xpm_file_to_image(game.mlx, "textures/Background Cave/final_xpm/bot.xpm", &width, &height);
	game.bot_right = mlx_xpm_file_to_image(game.mlx, "textures/Background Cave/final_xpm/bot_right.xpm", &width, &height);
	game.map = ft_parse_map(&game, "maps/map.ber");
	game.tl = mlx_xpm_file_to_image(game.mlx, "textures/Background Cave/top_left/tl.xpm", &width, &height);
	game.mid_tl = mlx_xpm_file_to_image(game.mlx, "textures/Background Cave/top_left/mid_tl.xpm", &width, &height);
	game.bot_tl = mlx_xpm_file_to_image(game.mlx, "textures/Background Cave/top_left/bot_tl.xpm", &width, &height);

	game.x = 128;
	game.y = 128;
	game.w = 24 * SCALE;
	game.h = 60 * SCALE;
	game.ox = 32 * SCALE;
	game.oy = 0;

	mlx_loop_hook(game.mlx, ft_update, &game);
	mlx_hook(game.win, KeyPress, KeyPressMask, ft_key_pressed, &game);
	mlx_hook(game.win, KeyRelease, KeyReleaseMask, ft_key_released, &game);
	mlx_hook(game.win, DestroyNotify, ButtonPressMask, ft_close, &game);
	mlx_loop(game.mlx);
	mlx_destroy_window(game.mlx, game.win);
}
// TODO: parse and print the map