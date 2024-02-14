/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:36:53 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/14 19:21:04 by vopekdas         ###   ########.fr       */
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

void	draw_sprite_player(t_game *game, t_img *img, t_draw_info draw_info)
{
	const int		offx = -game->player.pos_x + WINDOWS_WIDTH / 2 - 82 * 1 / 2;
	const int		offy = -game->player.pos_y + WINDOWS_HEIGHT / 2 - 58 * SCALE / 2;
	int				i;
	int				j;
	unsigned int	color;

	i = 0;
	while (i < img->width * SCALE)
	{
		j = -1;
		while (++j < img->height * SCALE)
		{
			if (j + draw_info.y + offy < 0 || j + draw_info.y + offy >= game->screen->height
				|| i + draw_info.x + offx < 0 || i + draw_info.x + offx >= game->screen->width)
				continue ;
			if (!draw_info.flipped)
				color = ((int *)img->data)[(int)(j / SCALE) * img->width + (int)(i / SCALE)];
			else
			 	color = ((int *)img->data)[(int)(j / SCALE) * img->width + (int)((img->width * SCALE - (i + 1)) / SCALE)];
			if (color == 0xFF000000)
				continue ;
			((int *)game->screen->data)[(draw_info.y + j + offy) * game->screen->width + (draw_info.x + i + offx)] = color;
		}
		i++;
	}
}

void	draw_sprite(t_game *game, t_img *img, int x, int y)
{
	const int		offx = -game->player.pos_x + WINDOWS_WIDTH / 2 - 64 * SCALE / 2;
	const int		offy = -game->player.pos_y + WINDOWS_HEIGHT / 2 - 64 * SCALE / 2;
	int				i;
	int				j;
	unsigned int	color;

	i = 0;
	while (i < img->width * SCALE)
	{
		j = -1;
		while (++j < img->height * SCALE)
		{
			if (j + y + offy < 0 || j + y + offy >= game->screen->height || i + x + offx < 0 || i + x + offx >= game->screen->width)
				continue ;
			color = ((int *)img->data)[(int)(j / SCALE) * img->width + (int)(i / SCALE)];
			if (color == 0xFF000000)
				continue ;
			((int *)game->screen->data)[(y + j + offy) * game->screen->width + (x + i + offx)] = color;
		}
		i++;
	}
}

typedef struct
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	t;
}	t_trgb;

void	draw_vignette(t_game *game)
{
	int				i;
	int				j;
	int si;
	int sj;
	float ri;
	float rj;
	t_trgb			color;

	i = -1;
	while (++i < WINDOWS_WIDTH)
	{
		si = i;
		j = -1;
		while (++j < WINDOWS_HEIGHT)
		{
			sj = j;
			ri = (float)si / (float)WINDOWS_WIDTH;
			rj = (float)sj / (float)WINDOWS_HEIGHT;
			color = (((t_trgb *)game->screen->data)[sj * game->screen->width + si]);
			color.r = (int)(color.r * 4 * ri * (1-ri));
			color.g  = (int)(color.g * 4 * ri * (1-ri));
			color.b = (int)(color.b * 4 * ri * (1-ri));
			color.r = (int)(color.r * 4 * rj * (1-rj));
			color.g  = (int)(color.g * 4 * rj * (1-rj));
			color.b = (int)(color.b * 4 * rj * (1-rj));
			((int *)game->screen->data)[sj * game->screen->width + si] = *((int *)&color);
		}	
	}
}
