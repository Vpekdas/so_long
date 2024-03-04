/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vignette.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:30:36 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/04 18:03:14 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_left_to_right(t_trgb *color, float ri)
{
	color->r = (int)(color->r * 4 * ri * (1 - ri));
	color->g = (int)(color->g * 4 * ri * (1 - ri));
	color->b = (int)(color->b * 4 * ri * (1 - ri));
}

void	draw_top_to_bot(t_trgb *color, float rj)
{
	color->r = (int)(color->r * 4 * rj * (1 - rj));
	color->g = (int)(color->g * 4 * rj * (1 - rj));
	color->b = (int)(color->b * 4 * rj * (1 - rj));
}

void	draw_vignette(t_game *game)
{
	int		i;
	int		j;
	t_trgb	color;

	i = -1;
	while (++i < WIN_W)
	{
		game->vignette.si = i;
		j = -1;
		while (++j < WIN_H)
		{
			game->vignette.sj = j;
			game->vignette.ri = game->vignette.si / (float)WIN_W;
			game->vignette.rj = game->vignette.sj / (float)WIN_H;
			color = (((t_trgb *)game->screen->data)[game->vignette.sj
					*game->screen->width + game->vignette.si]);
			draw_left_to_right(&color, game->vignette.ri);
			draw_top_to_bot(&color, game->vignette.rj);
			((int *)game->screen->data)[game->vignette.sj * game->screen->width
				+ game->vignette.si] = *((int *)&color);
		}	
	}
}
