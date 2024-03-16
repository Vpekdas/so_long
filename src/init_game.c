/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:19:36 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/16 17:09:54 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_player(t_game *game)
{
	game->play.width = 22 * SCALE;
	game->play.height = 29 * SCALE;
	game->play.offset_x = 37 * SCALE;
	game->play.offset_y = 0;
	game->play.health = 3;
}

void	init_bomb(t_game *game)
{
	game->bomb.speed = 15;
	game->bomb.height = SPRITE_SIZE;
	game->bomb.width = SPRITE_SIZE;
	game->bomb.offset_y = 48;
}

int	init_player_and_map(t_game *game)
{
	init_player(game);
	init_bomb(game);
	game->map = parse_map(game, game->map_path);
	if (!game->map)
		return (-1);
	find_player_position(game, game->map);
	game->collectibles_numbers = find_collectible_numbers(game, game->map);
	game->bubble_list = create_list_bubble(game);
	game->collectible_list = create_list_collectible(game);
	game->enemy_list = create_list_enemy(game);
	game->map_copy.map = copy_map(game);
	return (0);
}

int	init_mlx_settings(t_game *game, char **av)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putstr_fd(RED"Error\n❌the mlx pointer is NULL❌\n", 2);
		return (-1);
	}
	game->win = mlx_new_window(game->mlx, WIN_W, WIN_H, "so_long");
	game->screen = mlx_new_image(game->mlx, WIN_W, WIN_H);
	game->map_path = av[1];
	return (0);
}
