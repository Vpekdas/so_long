/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:43:00 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/08 14:26:25 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	print_map(char **map, t_game *game)
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
				print_tile(game, game->map, j, i);
			j++;
		}
		i++;
	}
	return (0);
}
