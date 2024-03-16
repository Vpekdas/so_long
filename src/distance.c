/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:50:49 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/15 18:37:49 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	calcul_distance(t_enemy_list enemy, t_bomb bomb)
{
	return (sqrt((enemy.pos_x - bomb.pos_x) * (enemy.pos_x - bomb.pos_x)
			+ (enemy.pos_y - bomb.pos_y) * (enemy.pos_y - bomb.pos_y)));
}
