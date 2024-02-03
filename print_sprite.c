/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:36:53 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/03 17:52:58 by vopekdas         ###   ########.fr       */
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
