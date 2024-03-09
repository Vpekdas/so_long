/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:18:11 by vopekdas          #+#    #+#             */
/*   Updated: 2023/11/24 15:48:41 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putnbr_base_p(uintptr_t nb, char *base)
{
	long long		i;
	char			result [100];
	int				len;

	if (nb == 0)
	{
		ft_putchar(base[0]);
		return (1);
	}
	i = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	while (nb > 0)
	{
		result[i] = base[nb % ft_strlen(base)];
		nb /= ft_strlen(base);
		i++;
	}
	len = i;
	while (i > 0)
		ft_putchar(result[i-- - 1]);
	return (len);
}

int	ft_putnbr_base(unsigned int nb, char *base)
{
	long long		i;
	char			result [100];
	int				len;

	if (nb == 0)
	{
		ft_putchar(base[0]);
		return (1);
	}
	i = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	while (nb > 0)
	{
		result[i] = base[nb % ft_strlen(base)];
		nb /= ft_strlen(base);
		i++;
	}
	len = i;
	while (i > 0)
		ft_putchar(result[i-- - 1]);
	return (len);
}
