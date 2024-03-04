/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:18:49 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/04 15:19:00 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_first_line(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_copy.map_width)
	{
		if (game->map_copy.map[0][i] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	check_last_line(t_game *game)
{
	int	i;
	int	map_height;

	i = 0;
	map_height = game->map_copy.map_height;
	while (i < game->map_copy.map_width)
	{
		if (game->map_copy.map[map_height - 1][i] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	check_first_column(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_copy.map_height)
	{
		if (game->map_copy.map[i][0] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	check_last_column(t_game *game)
{
	int	i;
	int	map_width;

	i = 0;
	map_width = game->map_copy.map_width;
	while (i < game->map_copy.map_height)
	{
		if (game->map_copy.map[i][map_width - 1] != '1')
			return (false);
		i++;
	}
	return (true);
}
