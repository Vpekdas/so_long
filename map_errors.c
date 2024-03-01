/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:27:28 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/01 17:19:29 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_map_rectangular(t_game *game)
{
	int	i;
	int	actual_line;
	int	previous_line;

	i = 0;
	while (i < game->map_copy.map_height - 1)
	{
		previous_line = ft_strlen(game->map_copy.map[i]);
		i++;
		actual_line = ft_strlen(game->map_copy.map[i]);
		if (actual_line != previous_line)
		{
			ft_putstr_fd("Error\n the map is not rectangular\n", 2);
			return (false);
		}
	}
	return (true);
}

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

bool	is_map_surrounder_walls(t_game *game)
{
	if (check_first_column(game) == false)
	{
		ft_putstr_fd("Error\nThere is no wall somewhere in first column\n", 2);
		return (false);
	}
	if (check_last_column(game) == false)
	{
		ft_putstr_fd("Error\nThere is no wall somewhere in last column\n", 2);
		return (false);
	}
	if (check_first_line(game) == false)
	{
		ft_putstr_fd("Error\nThere is no wall somewhere in first line\n", 2);
		return (false);
	}
	if (check_last_line(game) == false)
	{
		ft_putstr_fd("Error\nThere is no wall somewhere in last line\n", 2);
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
	while (i < game->map_copy.map_height)
	{
		j = 0;
		while (j < game->map_copy.map_width)
		{
			if (is_valid_character(game->map_copy.map[i][j]) == false)
			{
				ft_putstr_fd("Error\nThere is an unknown character\n", 2);
				return (false);
			}
			else
				j++;
		}
		i++;
	}
	return (true);
}

bool	check_character_number(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_copy.map_height)
	{
		j = 0;
		while (j < game->map_copy.map_width)
		{
			if (is_valid_character(game->map_copy.map[i][j]) == true)
			{
				if (game->map_copy.map[i][j] == 'C')
					game->character_map.collectible_nb++;
				else if (game->map_copy.map[i][j] == 'E')
					game->character_map.exit_nb++;
				else if (game->map_copy.map[i][j] == 'P')
					game->character_map.player_nb++;
				else if (game->map_copy.map[i][j] == 'G' && BONUS)
					game->character_map.enemy_nb++;
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	print_error(char *str)
{
	ft_putstr_fd(str, 2);
	return (false);
}

bool	check_map_character_overall(t_game *game)
{
	if (is_map_surrounder_walls(game) == false)
		return (false);
	if (check_map_character(game) == false)
		return (false);
	check_character_number(game);
	if (game->character_map.collectible_nb == 0)
		return (print_error("Error\nPlace atleast 1 collectible\n"));
	if (game->character_map.exit_nb != 1)
		return (print_error("Error\nYou need to place only 1 exit\n"));
	if (game->character_map.player_nb != 1)
		return (print_error("Error\nYou need to place only 1 player\n"));
	if (game->character_map.enemy_nb > 1 && BONUS)
		return (print_error("Error\nYou can only place 1 enemy maximum\n"));
	if (is_map_finishable(game) == false)
		return (print_error("Error\nYou can't finish the map\n"));
	return (true);
}
