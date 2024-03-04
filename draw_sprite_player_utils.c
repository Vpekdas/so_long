/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite_player_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:40:20 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/04 17:45:06 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

unsigned int	draw_not_flip_player(t_img *img, int i, int j)
{
	return (((int *)img->data)[(int)(j / SCALE)
			*img->width + (int)(i / SCALE)]);
}

unsigned int	draw_flip_player(t_img *img, int i, int j)
{
	return (((int *)img->data)[(int)(j / SCALE)
		*img->width + (int)((img->width * SCALE - (i + 1)) / SCALE)]);
}
