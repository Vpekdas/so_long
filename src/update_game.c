/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:20:59 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/06 18:01:34 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
void	update_collide(t_game *game, t_box player_box)
{
	collide_with_collectible(player_box, game);
	collide_with_exit_chest(player_box, game);
}

void	update_move(t_game *game)
{
	move_player(game, game->play.velocity_x, game->play.velocity_y);
	move_enemy(game);
}

void	update_animation(t_game *game)
{
	update_anim_player(game);
	update_anim_enemy(game);
	update_anim_collectible(game->map, game);
	update_bomb(game);
}

void	update_particle_and_background(t_game *game)
{
	draw_background_sprite(game, game->sprites[FOREGROUND], game->fg_scroll);
	update_anim_bubble(game);
	update_anim_trail(game);
	draw_vignette(game);
}

int	update(t_game *game)
{
	t_box		player_box;

	if (game->play.health == 0)
		close_game(game);
	game->play.velocity_x = 0;
	detect_key(game);
	player_box = player_box_x_y_off_below(game);
	if (!collide_with_map(player_box, game))
		game->play.velocity_y += 18 * 0.016;
	player_box = player_box_y_off(game, game->play.velocity_y);
	update_collide(game, player_box);
	update_move(game);
	draw_background(game);
	print_map(game->map, game);
	update_animation(game);
	update_particle_and_background(game);
	mlx_put_image_to_window(game->mlx, game->win, game->screen, 0, 0);
	display_hud(game);
	return (0);
}
