/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:41:00 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/10 18:41:37 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_game(t_game *game)
{
	mlx_loop_end(game->mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_game		game;

	if (ac != 2)
	{
		ft_putstr_fd(RED"Error\n🗺️ You need to give one map🗺️\n", 2);
		return (-1);
	}
	game = (t_game){0};
	if (init_mlx_settings(&game, av) == -1)
		return (-1);
	if (init_player_and_map(&game) == -1)
		return (free_if_error_init_map_player(&game));
	if (check_map_character_overall(&game) == false)
		return (free_if_error_map(&game));
	init_sprite(&game);
	if (check_all_sprite_load(&game) == false)
		return (free_if_error_sprites(&game));
	mlx_loop_hook(game.mlx, update, &game);
	mlx_hook(game.win, KeyPress, KeyPressMask, key_pressed, &game);
	mlx_hook(game.win, KeyRelease, KeyReleaseMask, key_released, &game);
	mlx_hook(game.win, DestroyNotify, 0, close_game, &game);
	mlx_loop(game.mlx);
	free_if_no_error(&game);
	display_end_message(&game);
}
