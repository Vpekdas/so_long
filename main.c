/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:41:00 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/20 18:50:34 by vopekdas         ###   ########.fr       */
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
	char		**copy_map_tab;

	ft_bzero(&game, sizeof(t_game));
	game.mlx = mlx_init();
	// TODO: Protect mlx NULL pointer
	game.win = mlx_new_window(game.mlx, WINDOWS_WIDTH, WINDOWS_HEIGHT, "so_long");
	game.screen = mlx_new_image(game.mlx, WINDOWS_WIDTH, WINDOWS_HEIGHT);
	init_player_and_map(&game);
	init_sprite(&game);
	mlx_loop_hook(game.mlx, update, &game);
	mlx_hook(game.win, KeyPress, KeyPressMask, key_pressed, &game);
	mlx_hook(game.win, KeyRelease, KeyReleaseMask, key_released, &game);
	mlx_hook(game.win, DestroyNotify, 0, close_game, &game);
	mlx_loop(game.mlx);
	mlx_destroy_window(game.mlx, game.win);

	copy_map_tab = copy_map(&game);
	sand_fill(game.sandfill.pos_x, game.sandfill.pos_y, copy_map_tab, 3, game);
	for (int i = 0; i < game.map_height; i++)
	{
		printf("%s", copy_map_tab[i]);
	}
}