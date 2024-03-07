/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:36:46 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/07 18:10:52 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	update_frame_bubble(t_game *game, t_anim *anim)
{
	if (game->frame_count % PROPS_FRAME_INTER == 0)
	{
		anim->anim_index++;
		anim->frame++;
		if (anim->frame >= anim->frame_count)
		{
			anim->anim_index = 0;
			anim->frame = 0;
		}
	}
}

void	update_anim_bubble(t_game *game)
{
	t_node_bubble	*current;
	int				pos_x;
	int				pos_y;

	current = game->bubble_list;
	update_frame_bubble(game, &game->bubble);
	while (current)
	{
		current->velocity_y += 0.08;
		if (current->pos_y - current->velocity_y - 5 <= 0)
		{
			current->pos_y = game->map_height + 10;
			current->velocity_y = 0.08;
		}
		pos_x = current->pos_x;
		pos_y = current->pos_y - current->velocity_y - 5;
		draw_anim_bubble(game, &game->bubble, pos_x, pos_y);
		current = current->next;
	}
}

void	draw_anim_bubble(t_game *game, t_anim *anim, int x, int y)
{
	int	x_scale;
	int	y_scale;

	x_scale = x * 32 * SCALE;
	y_scale = y * 32 * SCALE;
	draw_sprite(game, anim->img[anim->anim_index], x_scale, y_scale);
}
