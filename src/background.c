/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:31:21 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/06 15:42:33 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_background(t_game *game)
{
	draw_background_sprite(game, game->sprites[WATER], game->water_scroll);
	draw_background_sprite(game, game->sprites[BACKGROUND2], game->bg2_scroll);
	draw_background_sprite(game, game->sprites[BACKGROUND], game->bg1_scroll);
}
