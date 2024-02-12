/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:36:53 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/12 15:12:04 by vopekdas         ###   ########.fr       */
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
