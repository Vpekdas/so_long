/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:20:06 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/09 17:53:33 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	display_step_count(t_game *g)
{
	char	*step_count;

	step_count = ft_itoa(g->step_count);
	mlx_string_put(g->mlx, g->win, 30, 10, 0xFFFFFF, "Step count :");
	mlx_string_put(g->mlx, g->win, 150, 10, 0xFFFFFF, step_count);
	free(step_count);
	ft_printf("Step count : %d\n", g->step_count);
}

void	display_health(t_game *g)
{
	char	*player_health;
	char	*enemy_health;

	player_health = ft_itoa(g->play.health);
	mlx_string_put(g->mlx, g->win, 30, 30, 0xFFFFFF, "player health :");
	mlx_string_put(g->mlx, g->win, 150, 30, 0xFFFFFF, player_health);
	if (g->enemy.number == 1)
	{
		enemy_health = ft_itoa(g->enemy.health);
		mlx_string_put(g->mlx, g->win, 30, 70, 0xFFFFFF, "enemy health :");
		mlx_string_put(g->mlx, g->win, 150, 70, 0xFFFFFF, enemy_health);
		free(enemy_health);
	}
	free(player_health);
}

void	display_remaining_collectibles(t_game *g)
{
	char	*remaining_collec;

	remaining_collec = ft_itoa(g->collectibles_numbers);
	mlx_string_put(g->mlx, g->win, 30, 50, 0xFFFFFF,
		"remaining collectibles :");
	mlx_string_put(g->mlx, g->win, 180, 50, 0xFFFFFF, remaining_collec);
	free(remaining_collec);
}

void	display_hud(t_game *g)
{
	display_step_count(g);
	display_health(g);
	display_remaining_collectibles(g);
}
