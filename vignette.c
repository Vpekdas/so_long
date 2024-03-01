/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vignette.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:30:36 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/01 18:30:52 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_vignette(t_game *game)
{
	int		i;
	int		j;
	int 	si;
	int 	sj;
	float 	ri;
	float 	rj;
	t_trgb	color;

	i = -1;
	while (++i < WIN_W)
	{
		si = i;
		j = -1;
		while (++j < WIN_H)
		{
			sj = j;
			ri = (float)si / (float)WIN_W;
			rj = (float)sj / (float)WIN_H;
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
