/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:31:21 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/16 15:58:01 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_background(t_game *game)
{
	game->water_scroll = game->play.x * 0.25;
	game->bg2_scroll = game->play.x * 0.25;
	game->bg1_scroll = game->play.x * 0.5;
	game->fg_scroll = game->play.x * 3;
}

void	draw_background(t_game *game)
{
	draw_sprite_background(game, game->sprites[WATER], game->water_scroll);
	draw_sprite_background(game, game->sprites[BACKGROUND2], game->bg2_scroll);
	draw_sprite_background(game, game->sprites[BACKGROUND], game->bg1_scroll);
}
