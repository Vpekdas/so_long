/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:20:38 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/16 16:25:31 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	print_error(char *str)
{
	ft_putstr_fd(str, 2);
	return (false);
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
	else
		return (false);
}

bool	is_map_ber(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (ft_strncmp(str + len - 4, ".ber", 4) != 0)
	{
		ft_putstr_fd(RED"Error\n⛔the map is not a .ber⛔\n", 2);
		return (false);
	}
	return (true);
}
