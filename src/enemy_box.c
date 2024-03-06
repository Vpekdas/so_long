/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_box.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:40:39 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/06 16:18:42 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
t_box	enemy_box_y_off(t_game *game, float velocity_y)
{
	t_box	box;

	box.pos_x = game->enemy.pos_x + game->enemy.offset_x;
	box.pos_y = game->enemy.pos_y + game->enemy.offset_y + velocity_y;
	box.width = game->enemy.width;
	box.height = game->enemy.height - 30;
	return (box);
}
