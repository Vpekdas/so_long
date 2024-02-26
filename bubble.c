/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:36:46 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/26 19:56:29 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	draw_anim_bubble(t_game *game, t_anim *anim, int x, int y)
{
	int	anim_cooldown;

	anim_cooldown = 100;
	if (getms() - anim->last_frame >= anim_cooldown)
	{
		anim->anim_index++;
		anim->frame++;
		anim->last_frame = getms();
		if (anim->frame >= anim->frame_count)
		{
			anim->anim_index = 0;
			anim->frame = 0;
		}
	}
	draw_sprite(game, anim->img[anim->anim_index], x * 32 * SCALE, y * 32 * SCALE);
}


void	update_anim_bubble(t_game *game)
{

	draw_anim_bubble(game, &game->anim_bubble, game->bubble.x, game->bubble.y - game->bubble.velocity_y + 10);
	game->bubble.velocity_y += 0.08;
}