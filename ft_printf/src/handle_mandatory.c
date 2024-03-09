/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mandatory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:19:57 by vopekdas          #+#    #+#             */
/*   Updated: 2023/11/24 15:48:26 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_handle_s(const char *str)
{
	int	len;

	len = 0;
	if (str != NULL)
		ft_putstr(str);
	else
	{
		ft_putstr("(null)");
		return (6);
	}
	len = ft_strlen(str);
	return (len);
}

int	ft_handle_u(unsigned int value)
{
	int	len;

	len = 0;
	len = ft_putnbr(value);
	return (len);
}

int	ft_handle_d_i(int value)
{
	int	len;

	len = 0;
	len = ft_putnbr(value);
	return (len);
}

int	ft_handle_x_x(const char c, long long value)
{
	int	len;

	len = 0;
	if (c == 'x')
	{
		len = ft_putnbr_base(value, "0123456789abcdef");
	}
	else if (c == 'X')
	{
		len = ft_putnbr_base(value, "0123456789ABCDEF");
	}
	return (len);
}

int	ft_handle_p(void*ptr)
{
	int	len;

	len = 0;
	if (ptr != NULL)
	{
		write(1, "0x", 2);
		len = ft_putnbr_base_p((uintptr_t)ptr, "0123456789abcdef") + 2;
	}
	else
	{
		len = write(1, "(nil)", 5);
	}
	return (len);
}
