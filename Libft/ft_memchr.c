/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:38:47 by vopekdas          #+#    #+#             */
/*   Updated: 2023/11/07 11:46:04 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ptr;
	unsigned char		uc;

	uc = (unsigned char) c;
	i = 0;
	ptr = s;
	while (i < n)
	{
		if (ptr[i] == uc)
		{
			return ((char *)(ptr + i));
		}
		i++;
	}
	if (uc == 0)
	{
		return (NULL);
	}
	return (NULL);
}
