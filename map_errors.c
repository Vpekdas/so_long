/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:27:28 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/23 16:56:01 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_map_rectangular(t_game *game)
{
	int	i;
	int	actual_line;
	int	previous_line;

	i = 0;
	while (i < game->map_height - 1)
	{
		previous_line = ft_strlen(game->map[i]);
		i++;
		actual_line = ft_strlen(game->map[i]);
		if (actual_line != previous_line)
			return (false);
	}
	return (true);
}

bool	check_first_line(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_width)
	{
		if (game->map[0][i] != '1')
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
		if (game->map[map_height - 1][i] != '1')
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
		if (game->map[i][0] != '1')
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
		if (game->map[i][map_width - 1] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	is_map_surrounder_walls(t_game *game)
{
	if (check_first_column(game) == false)
		return (false);
	if (check_last_column(game) == false)
		return (false);
	if (check_first_line(game) == false)
		return (false);
	if (check_last_line(game) == false)
		return (false);
	else
		return (true);
}