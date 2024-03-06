/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:34:13 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/06 16:18:42 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
unsigned int	blend_colors(unsigned int a, unsigned int b, float ratio)
{
	const unsigned char	c1[] = {(a >> 16) & 0xFF, (a >> 8) & 0xFF, a & 0xFF};
	const unsigned char	c2[] = {(b >> 16) & 0xFF, (b >> 8) & 0xFF, b & 0xFF};

	return (((unsigned int)(c1[0] * (1 - ratio) + c2[0] * ratio) << 16)
	| ((unsigned int)(c1[1] * (1 - ratio) + c2[1] * ratio) << 8)
	| ((unsigned int)(c1[2] * (1 - ratio) + c2[2] * ratio)));
}
