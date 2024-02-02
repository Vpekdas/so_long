/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:41:00 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/02 17:07:19 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include "so_long.h"
#include <X11/X.h>
#include <math.h>
#include <sys/select.h>
#include <sys/time.h>

#define SCALE 4
#define SPEED 4
#define FRAME_INTERVAL 16

typedef struct	game {
	void	*mlx;
	void	*win;
	t_img	*img;
	t_img	*hat;
	t_img	*pirate;
	int		player_x;
	int		player_y;
	suseconds_t	last_frame;

	int		key_a;
	int		key_w;
	int		key_s;
	int		key_d;
}				t_game;

void	clear_img(t_img *img, unsigned int color)
{
	int	i;

	i = 0;
	while (i < img->width * img->height)
	{
		((unsigned int *)img->data)[i] = color;
		i++;
	}
}

void	draw_sprite(t_game *game, t_img *img, int x, int y)
{
	int				i;
	int				j;
	unsigned int	color;

	i = 0;
	while (i < img->width * SCALE)
	{
		j = 0;
		while (j < img->height * SCALE)
		{
			if (j + y < 0 || j + y >= game->img->height || i + x < 0 || i + x >= game->img->width)
			{
				j++;
				continue;
			}
			color = ((int *)img->data)[(int)(j / SCALE) * img->width + (int)(i / SCALE)];
			if (color == 0xFF000000)
			{
				j++;
				continue;
			}
			((int *)game->img->data)[(y + j) * game->img->width + (x + i)] = color;
			j++;
		}
		i++;
	}
}

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

suseconds_t	getms()
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	ft_update(t_game *game)
{
	suseconds_t	now;

	now = getms();
	if (now - game->last_frame < FRAME_INTERVAL)
		return (0);
	game->last_frame = now;
	if (game->key_w)
		game->player_y -= SPEED;
	if (game->key_s)
		game->player_y += SPEED;
	if (game->key_a)
		game->player_x -= SPEED;
	if (game->key_d)
		game->player_x += SPEED;
	clear_img(game->img, 0x0);
	draw_sprite(game, game->pirate, game->player_x, game->player_y);
	draw_sprite(game, game->hat, game->player_x, game->player_y - 16 * SCALE);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}

int	main(void)
{
	t_game	game;
	int height = 100;
	int width = 100;

	ft_bzero(&game, sizeof(t_game));
	game.player_x = 640;
	game.player_y = 360;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 1280, 720, "so_long");
	game.img = mlx_new_image(game.mlx, 1280, 720);
	game.pirate = mlx_xpm_file_to_image(game.mlx, "characters/red_pirate.xpm", &width, &height);
	game.hat = mlx_xpm_file_to_image(game.mlx, "accessories/pirate_hat.xpm", &width, &height);
	game.last_frame = 0;

	mlx_do_key_autorepeatoff(game.mlx);
	mlx_loop_hook(game.mlx, ft_update, &game);
	mlx_hook(game.win, KeyPress, KeyPressMask, ft_key_pressed, &game);
	mlx_hook(game.win, KeyRelease, KeyReleaseMask, ft_key_released, &game);
	mlx_loop(game.mlx);
	mlx_do_key_autorepeaton(game.mlx);
	mlx_destroy_window(game.mlx, game.win);
}
