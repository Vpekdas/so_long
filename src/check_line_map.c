/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:18:49 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/09 17:31:34 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	check_first_line(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_width)
	{
		if (game->map[0][i] && game->map[0][i] != '1')
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
	map_height = game->map_height;
	while (i < game->map_width)
	{
		if (game->map[map_height - 1][i] && game->map[map_height - 1][i] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	check_first_column(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		if (game->map[i][0] && game->map[i][0] != '1')
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
	map_width = game->map_width;
	while (i < game->map_height)
	{
		if (game->map[i][map_width - 1]
			&& game->map[i][map_width - 1] != '1')
			return (false);
		i++;
	}
	return (true);
}
