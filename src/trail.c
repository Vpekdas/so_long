/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trail.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:09:25 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/08 16:25:04 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_anim_trail(t_game *game, t_anim *anim)
{
	if (game->frame_count % FRAME_INTER == 0)
	{
		anim->anim_index++;
		anim->frame++;
		if (anim->frame >= anim->frame_count)
		{
			anim->anim_index = 0;
			anim->frame = 0;
		}
	}
	draw_sprite_player(game, anim->img[anim->anim_index], game->draw_info);
}

void	update_anim_trail(t_game *game)
{
	t_box	player;

	player = player_box_x_y_off_below(game);
	game->draw_info.x += SPRITE_SIZE;
	game->draw_info.y += 48;
	if (collide_with_map(player, game) && !game->is_trail_drawn)
	{
		draw_anim_trail(game, &game->trail);
		game->is_trail_drawn = true;
	}
}
