/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:34:33 by vopekdas          #+#    #+#             */
/*   Updated: 2023/11/14 14:50:30 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	ft_len_number(long long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_swap(char *a, char *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	ft_handle_sign(char	*str, int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		str[i] = '-';
		i++;
	}
	return (i);
}

static void	ft_reverse(char *str, int size)
{
	int	i;

	i = 0;
	if (str[0] == '-')
	{
		i = 1;
		size++;
	}
	while (i < size / 2)
	{
		ft_swap(&str[i], &str[size - i - 1]);
		i++;
	}
}

char	*ft_itoa(int n)
{
	int			i;
	int			size;
	char		*ptr;
	long long	nbr;

	nbr = n;
	size = ft_len_number(nbr);
	ptr = malloc(size + 1);
	if (!ptr)
		return (NULL);
	i = ft_handle_sign(ptr, nbr);
	if (nbr < 0)
		nbr *= -1;
	if (nbr == 0)
		ptr[i++] = nbr % 10 + 48;
	while (nbr > 0)
	{
		ptr[i++] = nbr % 10 + 48;
		nbr /= 10;
	}
	ft_reverse(ptr, size);
	ptr[size] = '\0';
	return (ptr);
}
