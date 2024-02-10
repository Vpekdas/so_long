/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:43:00 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/10 17:19:55 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*gnl(char **line, int fd)
{
	*line = get_next_line(fd);
	return (*line);
}
int	count_map_height(char *path)
{
	int		fd;
	char	*line;
	int		map_height;

	map_height = 1;
	fd = open(path, O_RDONLY);
	while (gnl(&line, fd))
	{
		map_height++;
		free(line);
	}
	close(fd);
	return (map_height);
}

char	**parse_map(t_game *game, char *path)
{
	char	**map;
	char	*line;
	int		fd;
	int		i;

	i = 0;
	map = malloc(sizeof(char *) * count_map_height(path));
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

void	print_door(t_game *g, int x, int y)
{
	draw_sprite(g, g->sprite.door, x * 32 * SCALE, y * 32 * SCALE);
}

void	print_collectible(t_game *g, int x, int y)
{
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
			else if (map[y][x] == 'C')
				print_collectible(game, x, y);
			else if (map[y][x] == 'D')
				print_door(game, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
