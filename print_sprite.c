/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:36:53 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/08 16:59:36 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_sprite(t_img *img, unsigned int color)
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
			if (j + y < 0 || j + y >= game->screen->height
				|| i + x < 0 || i + x >= game->screen->width)
			{
				j++;
				continue ;
			}
			color = ((int *)img->data)[(int)(j / SCALE)
				*img->width + (int)(i / SCALE)];
			if (color == 0xFF000000)
			{
				j++;
				continue ;
			}
			((int *)game->screen->data)[(y + j)
				* game->screen->width + (x + i)] = color;
			j++;
		}
		i++;
	}
}

void	init_sprite(t_game *g)
{
	int			w;
	int			h;

	w = 100;
	h = 100;
	g->sprite.player = mlx_xpm_file_to_image(g->mlx, "Idle_1.xpm", &w, &h);
	g->sprite.tl = mlx_xpm_file_to_image(g->mlx, "textures/tl.xpm", &w, &h);
	g->sprite.top = mlx_xpm_file_to_image(g->mlx, "textures/top.xpm", &w, &h);
	g->sprite.top_right = mlx_xpm_file_to_image(g->mlx, "textures/top_right.xpm", &w, &h);
	g->sprite.left = mlx_xpm_file_to_image(g->mlx, "textures/left.xpm", &w, &h);
	g->sprite.mid = mlx_xpm_file_to_image(g->mlx, "textures/mid.xpm", &w, &h);
	g->sprite.right = mlx_xpm_file_to_image(g->mlx, "textures/right.xpm", &w, &h);
	g->sprite.bot_left = mlx_xpm_file_to_image(g->mlx, "textures/bot_left.xpm", &w, &h);
	g->sprite.bot = mlx_xpm_file_to_image(g->mlx, "textures/bot.xpm", &w, &h);
	g->sprite.bot_right = mlx_xpm_file_to_image(g->mlx, "textures/bot_right.xpm", &w, &h);
	g->sprite.tl = mlx_xpm_file_to_image(g->mlx, "textures/tl.xpm", &w, &h);
	g->sprite.mid_tl = mlx_xpm_file_to_image(g->mlx, "textures/mid_tl.xpm", &w, &h);
	g->sprite.bot_tl = mlx_xpm_file_to_image(g->mlx, "textures/bot_tl.xpm", &w, &h);
}
