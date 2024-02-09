/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:43:00 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/09 19:05:14 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx_int.h"
#include "so_long.h"
#include <X11/Xlib.h>

char	*gnl(char **line, int fd)
{
	*line = get_next_line(fd);
	return (*line);
}

char	**parse_map(t_game *game, char *path)
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
	while (gnl(&line, fd))
	{
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	game->map_width = ft_strlen(map[0]) - 1;
	game->map_height = i;
	return (map);
}

void	print_collectible(t_game *g, int x, int y)
{
	t_box	player;

	player = player_box_x_y_off(g, g->player.velocity_x, g->player.velocity_y);
	if (collide_with_collectible(player, g, x, y) == true)
	{
		g->map[x][y] = '0';
		return ;
	}
	draw_sprite(g, g->sprite.collectible, x * 32 * SCALE, y * 32 * SCALE);
}

int	print_map(char **map, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				print_tile(game, game->map, x, y);
			if (map[y][x] == 'C')
				print_collectible(game, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
