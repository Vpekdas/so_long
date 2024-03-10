/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explotion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:50:28 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/10 16:45:52 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_anim_explotion(t_game *game, t_anim *anim, int x, int y)
{
	if (game->frame_count % PROPS_FRAME_INTER == 0)
	{
		anim->anim_index++;
		anim->frame++;
		if (anim->frame >= anim->frame_count)
		{
			anim->anim_index = 0;
			anim->frame = 0;
			game->bomb.is_exploding = false;
		}
	}
	if (game->bomb.is_exploding)
		draw_sprite(game, anim->img[anim->anim_index], x, y);
}

void	update_anim_explotion(t_game *game)
{
	const int	x = game->bomb.explo_x - 46;	
	const int	y = game->bomb.explo_y - 64;

	if (game->bomb.is_exploding)
		draw_anim_explotion(game, &game->explotion, x, y);
}
