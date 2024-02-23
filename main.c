/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:41:00 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/23 16:46:31 by vopekdas         ###   ########.fr       */
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
	// char		**copy_map_tab;

	ft_bzero(&game, sizeof(t_game));
	// game.mlx = mlx_init();
	// TODO: Protect mlx NULL pointer
	// game.win = mlx_new_window(game.mlx, WINDOWS_WIDTH, WINDOWS_HEIGHT, "so_long");
	// game.screen = mlx_new_image(game.mlx, WINDOWS_WIDTH, WINDOWS_HEIGHT);
	init_player_and_map(&game);
	// init_sprite(&game);
	// mlx_loop_hook(game.mlx, update, &game);
	// mlx_hook(game.win, KeyPress, KeyPressMask, key_pressed, &game);
	// mlx_hook(game.win, KeyRelease, KeyReleaseMask, key_released, &game);
	// mlx_hook(game.win, DestroyNotify, 0, close_game, &game);
	// mlx_loop(game.mlx);
	// mlx_destroy_window(game.mlx, game.win);

	// copy_map_tab = copy_map(&game);
	// pathfinding(game.pathfinding.pos_x, game.pathfinding.pos_y, copy_map_tab, 0, &game, 0);

	// if (game.accessible_collectibles == game.collectibles_numbers && game.accessible_door == 1)
	// 	printf("\nMAP CAN BE COMPLETED FOR PLAYER POS\n");
	// else
	// 	printf("\nMAP CANNOT BE COMPLETED\n");;

	// t_node	*list = NULL;
	// t_node	*current;
	// list = create_list_collectible(&game);
	// current = list;


	// while(current)
	// {
	// 	free(copy_map_tab);
	// 	copy_map_tab = copy_map(&game);
	// 	game.accessible_collectibles = 0;
	// 	game.accessible_door = 0;
	// 	pathfinding(current->pos_x, current->pos_y, copy_map_tab, 0, &game, 0);
	// 	if (game.accessible_door == 1)
	// 		printf("\nMAP CAN BE COMPLETED FOR COIN POS\n");
	// 	else
	// 	{
	// 		printf("\nMAP CANNOT BE COMPLETED -> x : %d| y : %d\n", current->pos_x, current->pos_y);
	// 		printf("collectible : %d | door : %d\n", game.accessible_collectibles, game.accessible_collectibles);
	// 	}
	// 	current = current->next;
	// }
	if (is_map_surrounder_walls(&game) == true)
		printf("MAP IS SURROUNDED BY WALLS\n");
	else
		printf("MAP IS NOT SURROUNDED BY WALLS\n");

}