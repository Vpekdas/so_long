/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:27:28 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/23 17:51:41 by vopekdas         ###   ########.fr       */
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
		{
			ft_putstr_fd("Error\n, the map is not rectangular\n", 2);
			return (false);
		}
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
	{
		ft_putstr_fd("Error\n, there is no wall somewhere in first column\n", 2);
		return (false);
	}
	if (check_last_column(game) == false)
	{
		ft_putstr_fd("Error\n, there is no wall somewhere in last column\n", 2);
		return (false);
	}
	if (check_first_line(game) == false)
	{
		ft_putstr_fd("Error\n, there is no wall somewhere in first line\n", 2);
		return (false);
	}
	if (check_last_line(game) == false)
	{
		ft_putstr_fd("Error\n, there is no wall somewhere in last line\n", 2);
		return (false);
	}
	else
		return (true);
}

bool	is_valid_character(char character)
{
	if (character == '0')
		return (true);
	else if (character == '1')
		return (true);
	else if (character == 'C')
		return (true);
	else if (character == 'E')
		return (true);
	else if (character == 'P')
		return (true);
	else if (character == 'G' && BONUS)
		return (true);
	else
		return (false);
}

bool	check_map_character(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (is_valid_character(game->map[i][j]) == false)
			{
				ft_putstr_fd("Error\n, there is an unknown character\n", 2);
				return (false);
			}
			else
				j++;
		}
		i++;
	}
	return (true);
}
