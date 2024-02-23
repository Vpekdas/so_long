/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:27:28 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/23 15:19:46 by vopekdas         ###   ########.fr       */
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