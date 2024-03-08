/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:19:50 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/08 16:23:15 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	find_collectible_numbers(t_game *game, char **map)
{
	int	x;
	int	y;
	int	collectibles_numbers;

	if (!map || !*map)
		return (-1);
	y = 0;
	collectibles_numbers = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (map[y][x] == 'C')
				collectibles_numbers++;
			x++;
		}
		y++;
	}
	return (collectibles_numbers);
}

void	update_frame_collectible(t_game *game, t_anim *anim)
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

void	update_anim_collectible(char **map, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	if (!map || !*map)
		return ;
	update_frame_collectible(game, &game->collectible);
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (map[y][x] == 'C')
				draw_anim_collectible(game, &game->collectible, x, y);
			x++;
		}
		y++;
	}
}

void	draw_anim_collectible(t_game *game, t_anim *anim, int x, int y)
{
	int	x_scale;
	int	y_scale;

	x_scale = x * SPRITE_SIZE * SCALE;
	y_scale = y * SPRITE_SIZE * SCALE;
	draw_sprite(game, anim->img[anim->anim_index], x_scale, y_scale);
}
