/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:41:00 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/01 15:06:31 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include "so_long.h"
#include <math.h>

#define SCALE 4

typedef struct	game {
	void	*mlx;
	void	*win;
	t_img	*img;
}				t_game;

int	ft_color_window(int keycode, t_game *game)
{
	static int i = 0;
	static int j = 0;
	if (keycode == XK_Escape)
		mlx_loop_end(game->mlx);
	if (keycode == 'w')
		j--;
	else if (keycode == 's')
		j++;
	else if (keycode == 'a')
		i--;
	else if (keycode == 'd')
		i++;
	mlx_pixel_put(game->mlx, game->win, i, j, 0x00100000 * (j + i) + 0x00001000 * j + 0x00000010 * i);
	return (0);
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

void	update()
{
}

int	main(void)
{
	t_game	game;
	void	*img, *hat;
	int height = 100;
	int width = 100;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 1280, 720, "so_long");
	game.img = mlx_new_image(game.mlx, 1280, 720);
	img = mlx_xpm_file_to_image(game.mlx, "characters/red_pirate.xpm", &width, &height);
	hat = mlx_xpm_file_to_image(game.mlx, "accessories/pirate_hat.xpm", &width, &height);

	int player_x = 32, player_y = 32;

	draw_sprite(&game, img, player_x, player_y);
	draw_sprite(&game, hat, player_x, player_y - 16 * SCALE);
	mlx_put_image_to_window(game.mlx, game.win, game.img, 0, 0);
	mlx_hook(game.win, 2, 1L << 0, ft_color_window, &game);
	mlx_loop(game.mlx);
	mlx_destroy_window(game.mlx, game.win);
}
