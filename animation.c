/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:20:02 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/13 18:39:31 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx_int.h"
#include "so_long.h"

suseconds_t	getms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	update_anim_player(t_game *game, suseconds_t now, t_img **img, int anim_nb)
{
	int			anim_cooldown;

	anim_cooldown = 350;
	if (now - game->last_frame >= anim_cooldown)
	{
		game->anim_player.anim_index++;
		game->anim_player.frame++;
		game->last_frame = now;
		if (game->anim_player.frame >= anim_nb)
		{
			game->anim_player.anim_index = 0;
			game->anim_player.frame = 0;
		}
	}
	draw_sprite(game, img[game->anim_player.anim_index], game->player.pos_x, game->player.pos_y);
}