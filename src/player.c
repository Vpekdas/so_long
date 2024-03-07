/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:13:09 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/07 18:13:13 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_anim_player(t_game *game, t_anim *anim)
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

void	update_anim_player(t_game *game)
{
	t_box	player;
	t_box	enemy;

	game->draw_info.x = game->play.x;
	game->draw_info.y = game->play.y;
	player = player_box_x_y_off_below(game);
	enemy = enemy_box_y_off(game, game->enemy.velocity_y);
	if (game->key_d)
	{
		game->draw_info.flip = false;
		draw_anim_player(game, &game->player_run);
	}
	else if (game->key_a)
	{
		game->draw_info.flip = true;
		draw_anim_player(game, &game->player_run);
	}
	else if (game->key_w && !collide_with_map(player, game))
		draw_anim_player(game, &game->player_jump);
	else if (game->key_s && !collide_with_map(player, game))
		draw_anim_player(game, &game->player_fall);
	else if (collide(enemy, player))
		draw_anim_player(game, &game->player_hit);
	else
		draw_anim_player(game, &game->player_idle);
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
	game->play.velocity_x = vx;
	game->play.x += vx;
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
		game->play.velocity_y = 0;
	}
	game->play.y += vy;
}

void	move_player(t_game *game, float velocity_x, float velocity_y)
{
	t_box	player;
	t_box	enemy;

	adjust_velocity_x(game, velocity_x);
	adjust_velocity_y(game, velocity_y);
	game->move_count += fabs(game->play.velocity_x);
	player = player_box_x_off(game, game->play.velocity_x);
	if (game->frame_count - game->play.last_frame >= 60)
		game->play.invulnerable = false;
	enemy = enemy_box_y_off(game, game->enemy.velocity_y);
	if (collide(player, enemy) && !game->play.invulnerable)
	{
		game->play.health--;
		game->play.invulnerable = true;
		game->play.last_frame = game->frame_count;
	}
	if (game->play.velocity_y >= 100)
		game->play.velocity_y = 100;
	game->water_scroll = game->play.x * 0.25;
	game->bg2_scroll = game->play.x * 0.25;
	game->bg1_scroll = game->play.x * 0.5;
	game->fg_scroll = game->play.x * 3;
}
