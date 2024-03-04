/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:08:55 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/04 17:31:21 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_over_scale(t_game *game, t_draw_info draw_info, int i, int j)
{
	const int		offx = -game->play.x + WIN_W / 2 - 70;
	const int		offy = -game->play.y + WIN_H / 2 - 90;

	return (j + draw_info.y + offy < 0
		|| j + draw_info.y + offy >= game->screen->height
		|| i + draw_info.x + offx < 0
		|| i + draw_info.x + offx >= game->screen->width);
}

t_trgb	draw_not_flip(t_img *img, int i, int j)
{
	return (((t_trgb *)img->data)[(int)(j / SCALE)
		*img->width + (int)(i / SCALE)]);
}

t_trgb	draw_flip(t_img *img, int i, int j)
{
	return (((t_trgb *)img->data)[(int)(j / SCALE)
		*img->width + (int)((img->width * SCALE - (i + 1)) / SCALE)]);
}

int	blended_color_enemy(t_game *game, t_draw_info draw_info, int i, int j)
{
	const int		offx = -game->play.x + WIN_W / 2 - 70;
	const int		offy = -game->play.y + WIN_H / 2 - 90;

	return (blend_colors(((int *)game->screen->data)[(draw_info.y + j + offy)
			*game->screen->width + (draw_info.x + i + offx)],
		*((unsigned int *) &game->draw_info.color), 0.5));
}
