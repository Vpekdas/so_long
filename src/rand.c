/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:45:42 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/07 13:08:18 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

uint32_t	xorshift32(t_xorshift32_state *state)
{
	uint32_t	x;

	x = state->a;
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return (state->a = x);
}
