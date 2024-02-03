/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:41:00 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/03 18:03:02 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf/include/ft_printf.h"
#include "so_long.h"

int	ft_key_pressed(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		mlx_loop_end(game->mlx);
	if (keycode == 'w')
		game->key_w = 1;
	if (keycode == 's')
		game->key_s = 1;
	if (keycode == 'a')
		game->key_a = 1;
	if (keycode == 'd')
		game->key_d = 1;
	return (0);
}

int	ft_key_released(int keycode, t_game *game)
{
	if (keycode == 'w')
		game->key_w = 0;
	if (keycode == 's')
		game->key_s = 0;
	if (keycode == 'a')
		game->key_a = 0;
	if (keycode == 'd')
		game->key_d = 0;
	return (0);
}

suseconds_t	ft_getms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	ft_close(t_game *game)
{
	mlx_loop_end(game->mlx);
	return (0);
}

char	*ft_gnl(char **line, int fd)
{
	*line = get_next_line(fd);
	return (*line);
}

char	**ft_parse_map(char *path)
{
	char	**map;
	char	*line;
	int		fd;
	int		i;

	i = 0;
	map = malloc(sizeof(char *) * 1000);
	if (!map)
		return (NULL);
	fd = open(path, O_RDONLY);
	while (ft_gnl(&line, fd))
	{
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	return (map);
}

int	ft_print_map(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				ft_draw_sprite(game, game->wall, j * 64, i * 64);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_update(t_game *game)
{
	suseconds_t	now;

	now = ft_getms();
	if (now - game->last_frame < FRAME_INTERVAL)
		return (0);
	game->last_frame = now;
	if (game->key_w)
		game->y -= SPEED;
	if (game->key_s)
		game->y += SPEED;
	if (game->key_a)
		game->x -= SPEED;
	if (game->key_d)
		game->x += SPEED;
	ft_clear_sprite(game->screen, 0x0);
	ft_draw_sprite(game, game->player, game->x, game->y);
	ft_print_map(ft_parse_map("map.ber"), game);
	mlx_put_image_to_window(game->mlx, game->win, game->screen, 0, 0);
	return (0);
}

int	main(void)
{
	t_game	game;
	int height = 100;
	int width = 100;

	ft_bzero(&game, sizeof(t_game));
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 1280, 720, "so_long");
	game.screen = mlx_new_image(game.mlx, 1280, 720);
	game.player = mlx_xpm_file_to_image(game.mlx, "Idle_1.xpm", &width, &height);
	game.wall = mlx_xpm_file_to_image(game.mlx, "tilesetcave.xpm", &width, &height);

	mlx_loop_hook(game.mlx, ft_update, &game);
	mlx_hook(game.win, KeyPress, KeyPressMask, ft_key_pressed, &game);
	mlx_hook(game.win, KeyRelease, KeyReleaseMask, ft_key_released, &game);
	mlx_hook(game.win, DestroyNotify, ButtonPressMask, ft_close, &game);
	mlx_loop(game.mlx);
	mlx_destroy_window(game.mlx, game.win);
}
// TODO: parse and print the map