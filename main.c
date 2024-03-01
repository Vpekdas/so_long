/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:41:00 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/01 17:20:46 by vopekdas         ###   ########.fr       */
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

	copy_map = malloc(sizeof(char *) * (count_map_height(game->map_path) + 1));
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

int	main(int ac, char **av)
{
	t_game		game;

	if (ac != 2)
	{
		ft_putstr_fd("You need to give one map\n", 2);
		return (-1);
	}
	game = (t_game){0};
	game.mlx = mlx_init();
	if (!game.mlx)
		return (-1);
	game.win = mlx_new_window(game.mlx, WINDOWS_WIDTH, WINDOWS_HEIGHT, "so_long");
	if (game.win)
		return (-1);
	game.screen = mlx_new_image(game.mlx, WINDOWS_WIDTH, WINDOWS_HEIGHT);
	if (!game.screen)
		return (-1);
	game.map_path = av[1];
	init_player_and_map(&game);
	if (check_map_character_overall(&game) == false)
	{
		free_map(&game);
		free_copy_map(&game);
		mlx_destroy_window(game.mlx, game.win);
		mlx_destroy_image(game.mlx, game.screen);
		mlx_destroy_display(game.mlx);
		free(game.mlx);
		free_list_bubble(game.bubble_list);
		free_list_collectible(game.collectible_list);
		return (1);
	}
	init_sprite(&game);
	if (check_all_sprite_load(&game) == false)
	{
		free_map(&game);
		free_copy_map(&game);
		free_all_sprites(&game);
		free_list_bubble(game.bubble_list);
		free_list_collectible(game.collectible_list);
		mlx_destroy_window(game.mlx, game.win);
		mlx_destroy_image(game.mlx, game.screen);
		mlx_destroy_display(game.mlx);
		free(game.mlx);
		return (1);
	}
	mlx_loop_hook(game.mlx, update, &game);
	mlx_hook(game.win, KeyPress, KeyPressMask, key_pressed, &game);
	mlx_hook(game.win, KeyRelease, KeyReleaseMask, key_released, &game);
	mlx_hook(game.win, DestroyNotify, 0, close_game, &game);
	mlx_loop(game.mlx);
	free_copy_map(&game);
	free_map(&game);
	free_all_sprites(&game);
	free_list_bubble(game.bubble_list);
	free_list_collectible(game.collectible_list);
	mlx_destroy_window(game.mlx, game.win);
	mlx_destroy_image(game.mlx, game.screen);
	mlx_destroy_display(game.mlx);
	free(game.mlx);
}
