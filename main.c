/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:41:00 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/08 14:26:17 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_game *game)
{
	mlx_loop_end(game->mlx);
	return (0);
}

void	init_player_and_map(t_game *game)
{
	game->player.x = 128;
	game->player.y = 128;
	game->player.w = 24 * SCALE;
	game->player.h = 60 * SCALE;
	game->player.ox = 32 * SCALE;
	game->player.oy = 0;
	game->map = parse_map(game, "maps/map.ber");

}

int	main(void)
{
	t_game		game;

	ft_bzero(&game, sizeof(t_game));

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 1280, 720, "so_long");
	game.screen = mlx_new_image(game.mlx, 1280, 720);
	init_player_and_map(&game);
	init_sprite(&game);
	mlx_loop_hook(game.mlx, update, &game);
	mlx_hook(game.win, KeyPress, KeyPressMask, key_pressed, &game);
	mlx_hook(game.win, KeyRelease, KeyReleaseMask, key_released, &game);
	mlx_hook(game.win, DestroyNotify, ButtonPressMask, close, &game);
	mlx_loop(game.mlx);
	mlx_destroy_window(game.mlx, game.win);
}
