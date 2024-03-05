/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:41:00 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/05 13:46:30 by vopekdas         ###   ########.fr       */
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
	int		map_height;
	int		i;

	map_height = count_map_height(game->map_path);
	if (map_height == -1)
	{
		ft_putstr_fd("Error\nthere was a problem when loading the map", 2);
		return (NULL);
	}
	copy_map = malloc(sizeof(char *) * (map_height + 1));
	if (!copy_map)
		return (NULL);
	i = 0;
	while (i < game->map_height)
	{
		copy_map[i] = ft_strdup(game->map[i]);
		i++;
	}
	return (copy_map);
}

int	init_mlx_settings(t_game *game, char **av)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (-1);
	game->win = mlx_new_window(game->mlx, WIN_W, WIN_H, "so_long");
	game->screen = mlx_new_image(game->mlx, WIN_W, WIN_H);
	game->map_path = av[1];
	return (0);
}

int	main(int ac, char **av)
{
	t_game		game;

	if (ac != 2)
	{
		ft_putstr_fd("You need to give one map\n", 2);
		return (-1);
	}
	game = (t_game){0};
	if (init_mlx_settings(&game, av) == -1)
		return (-1);
	if (init_player_and_map(&game) == -1)
		return (-1);
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
}
