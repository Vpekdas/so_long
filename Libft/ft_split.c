/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:10:48 by vopekdas          #+#    #+#             */
/*   Updated: 2023/11/20 11:24:21 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (tab);
}

static char	*ft_strcpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_count_words(const char *str, char c)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
			count++;
		while (*str && *str != c)
			str++;
	}
	return (count);
}

static char	*ft_copy_words(const char *str, char sep, int *length)
{
	int			len;
	const char	*start;
	char		*ptr;

	start = str;
	while (*str && *str != sep)
		str++;
	len = str - start;
	*length = len;
	ptr = malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	ft_strcpy(ptr, start, len);
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		len;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	result = ft_calloc(sizeof(char *), (ft_count_words(s, c) + 1));
	if (!result)
		return (NULL);
	while (*s)
	{
		len = 0;
		if (*s != c)
		{
			result[i] = ft_copy_words(s, c, &len);
			if (!result[i])
				return (ft_free(result));
			i++;
		}
		if (*s == c)
			s++;
		s += len;
	}
	return (result);
}
