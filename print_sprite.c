/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:36:53 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/07 14:45:25 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_clear_sprite(t_img *img, unsigned int color)
{
	int	i;

	i = 0;
	while (i < img->width * img->height)
	{
		((unsigned int *)img->data)[i] = color;
		i++;
	}
}

void	ft_draw_sprite(t_game *game, t_img *img, int x, int y)
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
			if (j + y < 0 || j + y >= game->screen->height || i + x < 0 || i + x >= game->screen->width)
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
			((int *)game->screen->data)[(y + j) * game->screen->width + (x + i)] = color;
			j++;
		}
		i++;
	}
}

void	ft_init_sprite(t_game *game)
{
	int	width;
	int	height;

	width = 100;
	height = 100;
	game->sprite.player = mlx_xpm_file_to_image(game->mlx, "Idle_1.xpm", &width, &height);
	game->sprite.top_left = mlx_xpm_file_to_image(game->mlx, "textures/Background Cave/final_xpm/top_left.xpm", &width, &height);
	game->sprite.top = mlx_xpm_file_to_image(game->mlx, "textures/Background Cave/final_xpm/top.xpm", &width, &height);
	game->sprite.top_right = mlx_xpm_file_to_image(game->mlx, "textures/Background Cave/final_xpm/top_right.xpm", &width, &height);
	game->sprite.left = mlx_xpm_file_to_image(game->mlx, "textures/Background Cave/final_xpm/left.xpm", &width, &height);
	game->sprite.mid = mlx_xpm_file_to_image(game->mlx, "textures/Background Cave/final_xpm/mid.xpm", &width, &height);
	game->sprite.right = mlx_xpm_file_to_image(game->mlx, "textures/Background Cave/final_xpm/right.xpm", &width, &height);
	game->sprite.bot_left = mlx_xpm_file_to_image(game->mlx, "textures/Background Cave/final_xpm/bot_left.xpm", &width, &height);
	game->sprite.bot = mlx_xpm_file_to_image(game->mlx, "textures/Background Cave/final_xpm/bot.xpm", &width, &height);
	game->sprite.bot_right = mlx_xpm_file_to_image(game->mlx, "textures/Background Cave/final_xpm/bot_right.xpm", &width, &height);
	game->sprite.tl = mlx_xpm_file_to_image(game->mlx, "textures/Background Cave/top_left/tl.xpm", &width, &height);
	game->sprite.mid_tl = mlx_xpm_file_to_image(game->mlx, "textures/Background Cave/top_left/mid_tl.xpm", &width, &height);
	game->sprite.bot_tl = mlx_xpm_file_to_image(game->mlx, "textures/Background Cave/top_left/bot_tl.xpm", &width, &height);
}
