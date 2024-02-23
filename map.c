/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:43:00 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/23 14:54:04 by vopekdas         ###   ########.fr       */
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

	map_height = 0;
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
	map = malloc(sizeof(char *) * (count_map_height(path) + 1));
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
	game->map_height = count_map_height(path);
	return (map);
}

int	print_map(char **map, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (map[y][x] == '1')
				draw_tile(game, game->map, x, y);
			else if (map[y][x] == 'E')
				draw_chest(game, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
