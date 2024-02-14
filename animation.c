/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:20:02 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/14 15:24:56 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/XKBlib.h>
#include <sys/select.h>

suseconds_t	getms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	draw_anim_player(t_game *game, t_anim_player *anim)
{
	int			anim_cooldown;

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
	draw_sprite_player(game, anim->img[anim->anim_index], game->draw_info);
}

void	update_anim_player(t_game *game)
{
	game->draw_info.x = game->player.pos_x;
	game->draw_info.y = game->player.pos_y;
	if (game->key_d)
	{
		game->draw_info.flipped = false;
		draw_anim_player(game, &game->anim_player_run);
	}
	else if (game->key_a)
	{
		game->draw_info.flipped = true;
		draw_anim_player(game, &game->anim_player_run);
	}
	else
		draw_anim_player(game, &game->anim);

}