/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vignette.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:30:36 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/07 16:14:06 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_left_to_right(t_trgb *color, float ratio_i)
{
	color->r = (int)(color->r * 4 * ratio_i * (1 - ratio_i));
	color->g = (int)(color->g * 4 * ratio_i * (1 - ratio_i));
	color->b = (int)(color->b * 4 * ratio_i * (1 - ratio_i));
}

void	draw_top_to_bot(t_trgb *color, float ratio_j)
{
	color->r = (int)(color->r * 4 * ratio_j * (1 - ratio_j));
	color->g = (int)(color->g * 4 * ratio_j * (1 - ratio_j));
	color->b = (int)(color->b * 4 * ratio_j * (1 - ratio_j));
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
			// game->vignette.ri = game->vignette.si / (float)WIN_W;
			game->vignette.rj = game->vignette.sj / (float)WIN_H;
			color = (((t_trgb *)game->screen->data)[game->vignette.sj
					*game->screen->width + game->vignette.si]);
			// draw_left_to_right(&color, game->vignette.ri);
			draw_top_to_bot(&color, game->vignette.rj);
			((int *)game->screen->data)[game->vignette.sj * game->screen->width
				+ game->vignette.si] = *((int *)&color);
		}	
	}
}
