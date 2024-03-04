/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:20:38 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/04 15:21:13 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	else if (character == 'G' && BONUS)
		return (true);
	else
		return (false);
}
