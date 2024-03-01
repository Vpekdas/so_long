/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:52:02 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/01 18:42:33 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_enemy_position(t_game *game, char **map)
{
	int	x;
	int	y;

	if (!map || !*map)
		return ;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'G')
			{
				game->enemy.pos_x = x * 32 * SCALE;
				game->enemy.pos_y = y * 32 * SCALE;
				game->enemy.number = 1;
			}
			x++;
		}
		y++;
	}
}

void	draw_anim_enemy(t_game *game, t_anim *anim)
{
	int			anim_cooldown;

	if (!anim)
		return ;
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
	draw_sprite_enemy(game, anim->img[anim->anim_index], game->draw_info_enemy);
}

int	calcul_distance(t_enemy enemy, t_bomb bomb)
{
	return (sqrt((enemy.pos_x - bomb.pos_x) * (enemy.pos_x - bomb.pos_x)
			+ (enemy.pos_y - bomb.pos_y) * (enemy.pos_y - bomb.pos_y)));
}

void	move_enemy(t_game *game)
{
	t_box	enemy;
	t_box	bomb;
	t_box	player;

	enemy = enemy_box_y_off(game, game->enemy.velocity_y);
	player = player_box_y_off(game, game->player.velocity_y);
	bomb = bomb_box(game);
	if (game->enemy.health == 0 || game->enemy.number == 0)
	{
		game->enemy.pos_x = -1000;
		game->enemy.pos_y = 1000;
		return ;
	}
	if (game->enemy.pos_x > game->player.pos_x)
		game->enemy.pos_x -= SPEED / 2;
	else if (game->enemy.pos_x < game->player.pos_x)
		game->enemy.pos_x += SPEED / 2;
	if (game->enemy.pos_y + 48 > game->player.pos_y)
		game->enemy.pos_y -= SPEED / 2;
	else if (game->enemy.pos_y < game->player.pos_y)
		game->enemy.pos_y += SPEED / 2;
	if (game->enemy.pos_y < 0)
		game->enemy.pos_y = game->player.pos_y;
	if (getms() - game->enemy.last_frame > 1500)
		game->enemy.invulnerable = false;
	if (calcul_distance(game->enemy, game->bomb) <= 200 && game->bomb.bomb_number == 1)
		game->enemy.pos_y = 1;
	if (collide(enemy, bomb) && !game->enemy.invulnerable)
	{
		game->enemy.health--;
		game->enemy.invulnerable = true;
		game->enemy.last_frame = getms();
	}
}

void	update_anim_enemy(t_game *game)
{
	t_box	player;
	t_box	enemy;

	if (game->enemy.health > 0)
	{
		player = player_box_y_off(game, game->player.velocity_y);
		enemy = enemy_box_y_off(game, game->enemy.velocity_y);
		game->draw_info_enemy.x = game->enemy.pos_x;
		game->draw_info_enemy.y = game->enemy.pos_y;
		if (game->player.pos_x < game->enemy.pos_x)
			game->draw_info_enemy.flipped = true;
		else
			game->draw_info_enemy.flipped = false;
		if (collide(player, enemy))
			draw_anim_enemy(game, &game->anim_enemy_attack);
		else
			draw_anim_enemy(game, &game->anim_enemy_idle);
	}
}