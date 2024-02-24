/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:13:09 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/24 15:37:53 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_anim_player(t_game *game, t_anim *anim)
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
	t_box	player;
	t_box	enemy;

	game->draw_info.x = game->player.pos_x;
	game->draw_info.y = game->player.pos_y;
	player = player_box_x_y_off_below(game);
	enemy = enemy_box_y_off(game, game->enemy.velocity_y);
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
	else if (game->key_w && !collide_with_map(player, game))
		draw_anim_player(game, &game->anim_player_jump);
	else if (game->key_s && !collide_with_map(player, game))
		draw_anim_player(game, &game->anim_player_fall);
	else if (collide(enemy, player))
		draw_anim_player(game, &game->anim_player_hit);
	else
		draw_anim_player(game, &game->anim);
}

void	adjust_velocity_x(t_game *game, float vx)
{
	const float	precision = 0.5;
	const bool	vx_positive = vx > 0;
	bool		collide_x;

	collide_x = collide_with_map(player_box_x_off(game, vx), game);
	while (((vx_positive && vx > 0) || (!vx_positive && vx < 0)) && collide_x)
	{
		if (vx_positive)
			vx -= precision;
		else if (!vx_positive)
			vx += precision;
	}
	if ((vx_positive && vx < 0) || (!vx_positive && vx > 0))
		vx = 0;
	game->player.pos_x += vx;
}

void	adjust_velocity_y(t_game *game, float vy)
{
	const bool	vy_positive = vy > 0;
	bool		collide_y;
	bool		should_collide;
	const float	precision = 0.5;

	collide_y = collide_with_map(player_box_y_off(game, vy), game);
	should_collide = collide_y;
	while (collide_y && fabs(vy) > precision)
	{
		collide_y = collide_with_map(player_box_y_off(game, vy), game);
		vy -= precision * (vy_positive * 2 - 1);
	}
	if (should_collide)
	{
		if (fabs(vy) <= precision)
			vy = 0;
		game->player.velocity_y = 0;
	}
	game->player.pos_y += vy;
}

void	move_player(t_game *game, float velocity_x, float velocity_y)
{
	t_box	player;
	t_box	enemy;

	adjust_velocity_x(game, velocity_x);
	adjust_velocity_y(game, velocity_y);
	player = player_box_x_off(game, game->player.velocity_x);
	if (getms() - game->player.last_frame > 1500)
		game->player.invulnerable = false;
	enemy = enemy_box_y_off(game, game->enemy.velocity_y);
	if (collide(player, enemy) && !game->player.invulnerable)
	{
		game->player.health--;
		game->player.invulnerable = true;
		game->player.last_frame = getms();
	}
	if (game->player.velocity_y >= 100)
		game->player.velocity_y = 100;
	game->water_scroll = game->player.pos_x * 0.25;
	game->bg2_scroll = game->player.pos_x * 0.25;
	game->bg1_scroll = game->player.pos_x * 0.5;
	game->fg_scroll = game->player.pos_x * 3;
}
void	find_player_position(t_game *game, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (map[y][x] == 'P')
			{
				game->player.pos_x = (x - 1) * 32 * SCALE;
				game->player.pos_y = y * 32 * SCALE;
				game->pathfinding.pos_x = x;
				game->pathfinding.pos_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
void	draw_sprite_player(t_game *game, t_img *img, t_draw_info draw_info)
{
	const int		offx = -game->player.pos_x + WINDOWS_WIDTH / 2 - !draw_info.flipped * 12 * SCALE;
	const int		offy = -game->player.pos_y + WINDOWS_HEIGHT / 2 - (116) * SCALE / 2;
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
