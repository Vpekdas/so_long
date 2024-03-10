/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:04:31 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/10 18:09:39 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**copy_map(t_game *game)
{
	char	**copy_map;
	int		map_height;
	int		i;

	map_height = count_map_height(game->map_path);
	if (map_height == -1)
	{
		ft_putstr_fd(RED"Error\n⏳there was a problem when loading the map⏳", 2);
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
