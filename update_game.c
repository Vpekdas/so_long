/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:20:59 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/21 19:10:40 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	update(t_game *game)
{
	t_box		player_box;

	if (game->player.health == 0)
		mlx_loop_end(game->mlx);
	game->player.velocity_x = 0;
	game->enemy.velocity_x = 0;
	detect_key(game);
	player_box = player_box_x_y_off_below(game);
	if (!collide_with_map(player_box, game))
		game->player.velocity_y += 18 * 0.016;
	player_box = player_box_y_off(game, game->player.velocity_y);
	collide_with_collectible(player_box, game);
	collide_with_exit_chest(player_box, game);
	move_player(game, game->player.velocity_x, game->player.velocity_y);
	move_enemy(game);
	clear_sprite(game->screen, 0x13120e);
	draw_background(game);
	print_map(game->map, game);
	update_anim_player(game);
	update_anim_enemy(game);
	update_anim_collectible(game->map, game);
	update_bomb(game);
	draw_background_sprite(game, game->sprite.foreground, game->fg_scroll);
	mlx_put_image_to_window(game->mlx, game->win, game->screen, 0, 0);
	draw_vignette(game);
	printf("health == %d\n", game->enemy.health);
	return (0);
}

/*

	cat hello.txt | grep test | shuf

	    PIPE
	  /      \
	PIPE      \
   /    \      \
 CAT   GREP   SHUF

*/

struct pipe
{
	void *left;
	void *right;
	char op;
};

struct command
{
	char *program;
	char **argv;
};