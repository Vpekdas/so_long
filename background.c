/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:31:21 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/13 13:30:59 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_background_sprite(t_game *game, t_img *img, int scroll)
{
	int				i;
	int				j;
	unsigned int	color;

	i = 0;
	while (i < WINDOWS_WIDTH)
	{
		j = -1;
		while (++j < img->height * 3)
		{
			if (j < 0 || j >= game->screen->height || i + scroll + 4000 < 0 || i >= game->screen->width)
				continue ;
			color = ((int *)img->data)[(int)(j / 3) * img->width + (int)(((i + scroll + 4000) % (img->width * 3)) / 3)];
			if (color == 0xFF000000)
				continue ;
			((int *)game->screen->data)[j * game->screen->width + i] = color;
		}
		i++;
	}
}

void	draw_background(t_game *game)
{
	draw_background_sprite(game, game->sprite.water, game->water_scroll);
	draw_background_sprite(game, game->sprite.background2, game->bg2_scroll);
	draw_background_sprite(game, game->sprite.background, game->bg1_scroll);
}