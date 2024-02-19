/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:52:02 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/19 19:17:49 by vopekdas         ###   ########.fr       */
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
				game->enemy.pos_x = x * 32 * SCALE - 20;
				game->enemy.pos_y = y * 32 * SCALE - 52;
			}
			x++;
		}
		y++;
	}
}

unsigned int    blend_colors(unsigned int a, unsigned int b, float ratio)
{
    const unsigned char    c1[] = {(a >> 16) & 0xFF, (a >> 8) & 0xFF, a & 0xFF};
    const unsigned char    c2[] = {(b >> 16) & 0xFF, (b >> 8) & 0xFF, b & 0xFF};

    return (((unsigned int)(c1[0] * (1 - ratio) + c2[0] * ratio) << 16)
        | ((unsigned int)(c1[1] * (1 - ratio) + c2[1] * ratio) << 8)
        | ((unsigned int)(c1[2] * (1 - ratio) + c2[2] * ratio)));
}

void	draw_sprite_enemy(t_game *game, t_img *img, t_draw_info draw_info)
{
	const int		offx = -game->player.pos_x + WINDOWS_WIDTH / 2 - 70;
	const int		offy = -game->player.pos_y + WINDOWS_HEIGHT / 2 - 90;
	int				i;
	int				j;
	t_trgb			color;

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
				color = ((t_trgb *)img->data)[(int)(j / SCALE) * img->width + (int)(i / SCALE)];
			else
			 	color = ((t_trgb *)img->data)[(int)(j / SCALE) * img->width + (int)((img->width * SCALE - (i + 1)) / SCALE)];
			if (color.t == 0xFF)
				continue ;
			color.t = 0xFF;
			int pixel = ((int *)game->screen->data)[(draw_info.y + j + offy) * game->screen->width + (draw_info.x + i + offx)];
			((int *)game->screen->data)[(draw_info.y + j + offy) * game->screen->width + (draw_info.x + i + offx)] =
				blend_colors(pixel, *((unsigned int *) &color), 0.5);
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
	draw_sprite_enemy(game, anim->img[anim->anim_index], game->draw_info_enemy);
}
t_box	enemy_box_y_off(t_game *game, float velocity_y)
{
	t_box	box;

	box.pos_x = game->enemy.pos_x + game->enemy.offset_x;
	box.pos_y = game->enemy.pos_y + game->enemy.offset_y + velocity_y;
	box.width = game->enemy.width;
	box.height = game->enemy.height - 30;
	return (box);
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
	if (game->enemy.health == 0)
	{
		game->enemy.pos_x = 1;
		game->enemy.pos_y = 1;
		return ;
	}
	if (calcul_distance(game->enemy, game->bomb) <= 400)
		game->enemy.pos_y -= 20;
	if (game->enemy.pos_x - 32 > game->player.pos_x)
		game->enemy.pos_x -= SPEED / 2;
	else if (game->enemy.pos_x + 32 < game->player.pos_x)
		game->enemy.pos_x += SPEED / 2;
	if (game->enemy.pos_y > game->player.pos_y)
		game->enemy.pos_y -= SPEED / 2;
	else if (game->enemy.pos_y < game->player.pos_y)
		game->enemy.pos_y += SPEED / 2;
	if (game->enemy.pos_y <= 0)
		game->enemy.pos_y = game->player.pos_y;
	if (getms() - game->enemy.last_frame > 1500)
		game->enemy.invulnerable = false;
	if (collide(enemy, bomb) && !game->enemy.invulnerable)
	{
		game->enemy.health--;
		game->enemy.invulnerable = true;
		game->enemy.last_frame = getms();
	}
}