/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:20:06 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/05 13:35:55 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "so_long.h"

void	display_hud(t_game *g)
{
	char	*count_move;
	char	*player_health;
	char	*enemy_health;

	count_move = ft_itoa(g->move_count);
	player_health = ft_itoa(g->play.health);
	mlx_string_put(g->mlx, g->win, 30, 10, 0xFFFFFF, "count_move :");
	mlx_string_put(g->mlx, g->win, 150, 10, 0xFFFFFF, count_move);
	mlx_string_put(g->mlx, g->win, 30, 30, 0xFFFFFF, "player health :");
	mlx_string_put(g->mlx, g->win, 150, 30, 0xFFFFFF, player_health);
	if (g->enemy.number == 1)
	{
		enemy_health = ft_itoa(g->enemy.health);
		mlx_string_put(g->mlx, g->win, 30, 50, 0xFFFFFF, "enemy health :");
		mlx_string_put(g->mlx, g->win, 150, 50, 0xFFFFFF, enemy_health);
		free(enemy_health);
	}
	free(count_move);
	free(player_health);
}