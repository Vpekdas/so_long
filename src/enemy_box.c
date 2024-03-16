/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_box.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:40:39 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/15 17:53:49 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_box	enemy_box_y_off(t_enemy_list *enemy)
{
	t_box	box;

	box.pos_x = enemy->pos_x + enemy->off_x;
	box.pos_y = enemy->pos_y + enemy->off_y + enemy->vy;
	box.width = enemy->width;
	box.height = enemy->height;
	return (box);
}
