/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:27:28 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/16 16:25:27 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
			ft_putstr_fd(RED"Error\n📐the map is not rectangular📐\n", 2);
			return (false);
		}
	}
	return (true);
}

bool	is_map_surrounded_walls(t_game *game)
{
	if (check_first_column(game) == false)
	{
		ft_putstr_fd(RED"Error\n🧱There is no wallsomewhere in first col🧱\n", 2);
		return (false);
	}
	if (check_last_column(game) == false)
	{
		ft_putstr_fd(RED"Error\n🧱There is no wall somewhere in last col🧱\n", 2);
		return (false);
	}
	if (check_first_line(game) == false)
	{
		ft_putstr_fd(RED"Error\n🧱There is no wall somewhere in first line🧱\n", 2);
		return (false);
	}
	if (check_last_line(game) == false)
	{
		ft_putstr_fd(RED"Error\n🧱There is no wall somewhere in last line🧱\n", 2);
		return (false);
	}
	else
		return (true);
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
			if (game->map[i][j] && is_valid_character(game->map[i][j]) == false)
			{
				ft_putstr_fd(RED "Error\n❓There is an unknown character❓\n", 2);
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
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] && is_valid_character(game->map[i][j]) == true)
			{
				if (game->map[i][j] == 'C')
					game->character_map.collectible_nb++;
				else if (game->map[i][j] == 'E')
					game->character_map.exit_nb++;
				else if (game->map[i][j] == 'P')
					game->character_map.player_nb++;
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_map_character_overall(t_game *game)
{
	if (is_map_rectangular(game) == false)
		return (false);
	if (is_map_surrounded_walls(game) == false)
		return (false);
	if (check_map_character(game) == false)
		return (false);
	check_character_number(game);
	if (game->character_map.collectible_nb == 0)
		return (print_error(RED "Error\n🪙Place atleast 1 collectible🪙\n"));
	if (game->character_map.exit_nb != 1)
		return (print_error(RED "Error\n🔚You need to place only 1 exit🔚\n"));
	if (game->character_map.player_nb != 1)
		return (print_error(RED "Error\n🎮You need to place only 1 player🎮\n"));
	if (game->character_map.enemy_nb > 1 && BONUS)
		return (print_error(RED "Error\n👻You can only place 1 enemy maximum👻\n"));
	if (is_map_finishable(game) == false)
		return (print_error(RED "Error\n❌🏁You can't finish the map🏁❌\n"));
	return (true);
}
