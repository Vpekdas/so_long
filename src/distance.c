/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:50:49 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/06 16:18:42 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
int	calcul_distance(t_enemy enemy, t_bomb bomb)
{
	return (sqrt((enemy.pos_x - bomb.pos_x) * (enemy.pos_x - bomb.pos_x)
			+ (enemy.pos_y - bomb.pos_y) * (enemy.pos_y - bomb.pos_y)));
}
