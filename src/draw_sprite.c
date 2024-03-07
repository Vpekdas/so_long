/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:36:53 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/07 14:05:30 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_sprite(t_game *game, t_img *img, int x, int y)
{
	const int		offx = -game->play.x + WIN_W / 2 - 64 * SCALE / 2;
	const int		offy = -game->play.y + WIN_H / 2 - 64 * SCALE / 2;
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

void	draw_sprite_background(t_game *game, t_img *img, int scroll)
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
	const int		offx = -game->play.x + WIN_W / 2 - 70;
	const int		offy = -game->play.y + WIN_H / 2 - 90;
	int				i;
	int				j;

	i = 0;
	while (i++ < img->width * SCALE)
	{
		j = -1;
		while (++j < img->height * SCALE)
		{
			if (check_over_scale(game, draw_info, i, j))
				continue ;
			if (!draw_info.flip)
				game->draw_info.color = draw_not_flip(img, i, j);
			else
				game->draw_info.color = draw_flip(img, i, j);
			if (game->draw_info.color.t == 0xFF)
				continue ;
			((int *)game->screen->data)[(draw_info.y + j + offy)
				*game->screen->width + (draw_info.x + i + offx)]
				= blended_color_enemy(game, draw_info, i, j);
		}
	}
}

void	draw_sprite_player(t_game *game, t_img *img, t_draw_info draw_info)
{
	const int		offx = -game->play.x + WIN_W / 2 - !draw_info.flip * 12 * 2;
	const int		offy = -game->play.y + WIN_H / 2 - (120) * SCALE / 2;
	int				i;
	int				j;
	unsigned int	color;

	i = 0;
	while (i < img->width * SCALE)
	{
		j = -1;
		while (++j < img->height * SCALE)
		{
			if (check_over_scale(game, draw_info, i, j))
				continue ;
			if (!draw_info.flip)
				color = draw_not_flip_player(img, i, j);
			else
				color = draw_flip_player(img, i, j);
			if (color == 0xFF000000)
				continue ;
			((int *)game->screen->data)[(draw_info.y + j + offy)
				* game->screen->width + (draw_info.x + i + offx)] = color;
		}
		i++;
	}
}

void	draw_chest(t_game *game, int x, int y)
{
	int	x_scale;
	int	y_scale;

	x_scale = x * 32 * SCALE;
	y_scale = y * 32 * SCALE;
	if (game->collectibles_numbers != 0)
		draw_sprite(game, game->sprites[DOOR], x_scale, y_scale);
	else if (game->collectibles_numbers == 0)
		draw_sprite(game, game->sprites[DOOR_OPEN], x_scale, y_scale);
}
