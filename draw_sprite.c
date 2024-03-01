/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:36:53 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/01 18:43:38 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_sprite(t_game *game, t_img *img, int x, int y)
{
	const int		offx = -game->player.pos_x + WIN_W / 2 - 64 * SCALE / 2;
	const int		offy = -game->player.pos_y + WIN_H / 2 - 64 * SCALE / 2;
	int				i;
	int				j;
	unsigned int	color;

	i = 0;
	while (i < img->width * SCALE)
	{
		j = -1;
		while (++j < img->height * SCALE)
		{
			if (j + y + offy < 0 || j + y + offy >= game->screen->height
				|| i + x + offx < 0 || i + x + offx >= game->screen->width)
				continue ;
			color = ((int *)img->data)[(int)
				(j / SCALE) *img->width + (int)(i / SCALE)];
			if (color == 0xFF000000)
				continue ;
			((int *)game->screen->data)[(y + j + offy)
				* game->screen->width + (x + i + offx)] = color;
		}
		i++;
	}
}
void	draw_background_sprite(t_game *game, t_img *img, int scroll)
{
	int				i;
	int				j;
	unsigned int	color;

	i = 0;
	while (i < WIN_W)
	{
		j = -1;
		while (++j < img->height * 3)
		{
			if (j < 0 || j >= game->screen->height || i + scroll + 4000 < 0
				|| i >= game->screen->width)
				continue ;
			color = ((int *)img->data)[(int)(j / 3) *img->width
				+ (int)(((i + scroll + 4000) % (img->width * 3)) / 3)];
			if (color == 0xFF000000)
				continue ;
			((int *)game->screen->data)[j * game->screen->width + i] = color;
		}
		i++;
	}
}

void	draw_sprite_enemy(t_game *game, t_img *img, t_draw_info draw_info)
{
	const int		offx = -game->player.pos_x + WIN_W / 2 - 70;
	const int		offy = -game->player.pos_y + WIN_H / 2 - 90;
	int				i;
	int				j;
	t_trgb			color;

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
				color = ((t_trgb *)img->data)[(int)(j / SCALE) * img->width + (int)(i / SCALE)];
			else
			 	color = ((t_trgb *)img->data)[(int)(j / SCALE) * img->width + (int)((img->width * SCALE - (i + 1)) / SCALE)];
			if (color.t == 0xFF)
				continue ;
			color.t = 0xFF;
			int pixel = ((int *)game->screen->data)[(draw_info.y + j + offy) * game->screen->width + (draw_info.x + i + offx)];
			((int *)game->screen->data)[(draw_info.y + j + offy) * game->screen->width + (draw_info.x + i + offx)] =
				blend_colors(pixel, *((unsigned int *) &color), 0.5);
		}
		i++;
	}
}
void	draw_chest(t_game *game, int x, int y)
{
	if (game->collectibles_numbers != 0)
		draw_sprite(game, game->sprites[DOOR], x * 32 * SCALE, y * 32 * SCALE);
	else if (game->collectibles_numbers == 0)
		draw_sprite(game, game->sprites[DOOR_OPEN], x * 32 * SCALE, y * 32 * SCALE);
}
