/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overall_free_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:16:37 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/16 15:33:08 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	free_if_error_map(t_game *game)
{
	free_map(game);
	free_copy_map(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->screen);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_list_bubble(game->bubble_list);
	free_list_enemy(game->enemy_list);
	free_list_collectible(game->collectible_list);
	return (-1);
}

int	free_if_error_sprites(t_game *game)
{
	free_map(game);
	free_copy_map(game);
	free_all_sprites(game);
	free_list_bubble(game->bubble_list);
	free_list_enemy(game->enemy_list);
	free_list_collectible(game->collectible_list);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->screen);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	return (-1);
}

void	free_if_no_error(t_game *game)
{
	free_copy_map(game);
	free_map(game);
	free_all_sprites(game);
	free_list_bubble(game->bubble_list);
	free_list_enemy(game->enemy_list);
	free_list_collectible(game->collectible_list);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->screen);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

int	free_if_error_init_map_player(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->screen);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	return (-1);
}
