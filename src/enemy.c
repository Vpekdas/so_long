/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:52:02 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/16 16:13:19 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_anim_enemy(t_game *game, t_anim *anim, t_draw_info draw_info)
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
	draw_sprite_enemy(game, anim->img[anim->anim_index], draw_info);
}

void	adjust_enemy_pos(t_game *game, t_enemy_list *enemy)
{
	if (game->frame_count < 200)
		return ;
	if (enemy->pos_x > game->play.x)
		enemy->pos_x -= SPEED / 2;
	else if (enemy->pos_x < game->play.x)
		enemy->pos_x += SPEED / 2;
	if (enemy->pos_y + 48 > game->play.y)
		enemy->pos_y -= SPEED / 2;
	else if (enemy->pos_y < game->play.y)
		enemy->pos_y += SPEED / 2;
	if (enemy->pos_y < 0)
		enemy->pos_y = game->play.y;
}

void	update_collide_enemy(t_game *game, t_enemy_list	*index)
{
	index->health--;
	index->invulnerable = true;
	index->last_frame = game->frame_count;
}

void	move_enemy(t_game *game, t_enemy_list *enemy)
{
	t_box			enemy_box;
	t_enemy_list	*index;

	index = enemy;
	if (game->spawn_enemy)
	{
		while (index)
		{
			enemy_box = enemy_box_y_off(index);
			if (index->health == 0 || !index->alive)
			{
				index->pos_x = -1000;
				index->pos_y = 1000;
			}
			adjust_enemy_pos(game, index);
			if (game->frame_count - index->last_frame >= 60)
				index->invulnerable = false;
			if (calcul_distance(*index, game->bomb) <= 200
				&& game->bomb.bomb_number == 1)
				index->pos_y = 1;
			if (collide(enemy_box, bomb_box(game)) && !index->invulnerable)
				update_collide_enemy(game, index);
			index = index->next;
		}
	}
}

void	update_anim_enemy(t_game *g)
{
	t_box			player;
	t_box			enemy;
	t_enemy_list	*index;

	if (g->spawn_enemy == true)
	{
		index = g->enemy_list;
		while (index)
		{
			if (index->health == 0)
				index->pos_x = -1000;
			player = player_box_y_off(g, g->play.velocity_y);
			enemy = enemy_box_y_off(index);
			index->draw_info.x = index->pos_x;
			index->draw_info.y = index->pos_y;
			if (g->play.x < index->pos_x)
				index->draw_info.flip = true;
			else
				index->draw_info.flip = false;
			if (collide(player, enemy))
				return (draw_anim_enemy(g, &g->enemy_attack, index->draw_info));
			draw_anim_enemy(g, &g->enemy_idle, index->draw_info);
			index = index->next;
		}
	}
}
