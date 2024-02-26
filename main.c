/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:41:00 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/26 16:25:12 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_game *game)
{
	mlx_loop_end(game->mlx);
	return (0);
}

char	**copy_map(t_game *game)
{
	char	**copy_map;
	int		i;

	copy_map = malloc(sizeof(char *) * (count_map_height("maps/map.ber") + 1));
	i = 0;
	while (i < game->map_height)
	{
		copy_map[i] = ft_strdup(game->map[i]);
		i++;
	}
	return (copy_map);
}

int	main(void)
{
	t_game		game;

	game = (t_game){0};
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WINDOWS_WIDTH, WINDOWS_HEIGHT, "so_long");
	game.screen = mlx_new_image(game.mlx, WINDOWS_WIDTH, WINDOWS_HEIGHT);
	init_player_and_map(&game);
	game.map_copy.map = copy_map(&game);
	if (check_map_character_overall(&game) == false)
	{
		free_map(&game);
		free_copy_map(&game);
		mlx_destroy_window(game.mlx, game.win);
		mlx_destroy_image(game.mlx, game.screen);
		mlx_destroy_display(game.mlx);
		free(game.mlx);
		return 1;
	}
	init_sprite(&game);
	mlx_loop_hook(game.mlx, update, &game);
	mlx_hook(game.win, KeyPress, KeyPressMask, key_pressed, &game);
	mlx_hook(game.win, KeyRelease, KeyReleaseMask, key_released, &game);
	mlx_hook(game.win, DestroyNotify, 0, close_game, &game);
	mlx_loop(game.mlx);
	free_map(&game);
	free_all_sprites(&game);
	mlx_destroy_window(game.mlx, game.win);
	mlx_destroy_image(game.mlx, game.screen);
	mlx_destroy_display(game.mlx);
	free(game.mlx);
}
