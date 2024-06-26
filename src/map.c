/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:43:00 by vopekdas          #+#    #+#             */
/*   Updated: 2024/05/30 17:50:50 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
	fd = open(path, O_RDONLY | O_DIRECTORY);
	if (fd == -1)
		fd = open(path, O_RDONLY);
	else
		return (-1);
	if (fd == -1)
		return (-1);
	while (gnl(&line, fd))
	{
		map_height++;
		free(line);
	}
	close(fd);
	return (map_height);
}

bool	check_fd(char *path, int *fd)
{
	*fd = open(path, O_RDONLY | O_DIRECTORY);
	if (*fd == -1)
	{
		*fd = open(path, O_RDONLY);
		if (*fd == -1)
		{
			ft_putstr_fd(RED "Error\n❌the map does not exist❌\n", 2);
			return (false);
		}
		return (true);
	}
	else
	{
		close(*fd);
		ft_putstr_fd(RED "Error\n📁the map cannot be a directory📁\n", 2);
		return (false);
	}
}

char	**parse_map(t_game *game, char *path)
{
	char	**map;
	char	*line;
	int		fd;
	int		i;

	i = 0;
	if (check_fd(path, &fd) == false)
		return (NULL);
	if (is_map_ber(path) == false)
		return (NULL);
	map = malloc(sizeof(char *) * (count_map_height(path) + 1));
	if (!map)
		return (NULL);
	while (gnl(&line, fd))
	{
		map[i] = line;
		i++;
	}
	close(fd);
	map[i] = NULL;
	game->map_width = ft_strlen(map[0]) - 1;
	game->map_copy.map_width = game->map_width;
	game->map_height = count_map_height(path);
	game->map_copy.map_height = game->map_height;
	return (map);
}

void	draw_map(char **map, t_game *game)
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
}