/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:52:02 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/17 17:12:00 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_enemy_position(t_game *game, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
			{
				game->enemy.pos_x = x * 32;
				game->enemy.pos_y = y * 32;
			}
			x++;
		}
		y++;
	}
}

void	draw_sprite_enemy(t_game *game, t_img *img, t_draw_info draw_info)
{
	const int		offx = -game->enemy.pos_x + WINDOWS_WIDTH / 2 - 72 * 1 / 2;
	const int		offy = -game->enemy.pos_y + WINDOWS_HEIGHT / 2 - 80 * SCALE / 2;
	int				i;
	int				j;
	unsigned int	color;

	i = 0;
	while (i < img->width * SCALE)
	{
		j = -1;
		while (++j < img->height * SCALE)
		{
			if (j + draw_info.y + offy < 0 || j + draw_info.y + offy >= game->screen->height
				|| i + draw_info.x + offx < 0 || i + draw_info.x + offx >= game->screen->width)
				continue ;
			if (!draw_info.flipped)
				color = ((int *)img->data)[(int)(j / SCALE) * img->width + (int)(i / SCALE)];
			else
			 	color = ((int *)img->data)[(int)(j / SCALE) * img->width + (int)((img->width * SCALE - (i + 1)) / SCALE)];
			if (color == 0xFF000000)
				continue ;
			((int *)game->screen->data)[(draw_info.y + j + offy) * game->screen->width + (draw_info.x + i + offx)] = color;
		}
		i++;
	}
}

void	draw_anim_enemy(t_game *game, t_anim *anim)
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
	draw_sprite_enemy(game, anim->img[anim->anim_index], game->draw_info);
}

void	update_anim_enemy(t_game *game)
{
	game->draw_info_enemy.x = game->enemy.pos_x;
	game->draw_info_enemy.y = game->enemy.pos_y;
	draw_anim_enemy(game, &game->anim_enemy_idle);
}