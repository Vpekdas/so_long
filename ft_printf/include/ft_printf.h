/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:06:45 by vopekdas          #+#    #+#             */
/*   Updated: 2023/11/24 15:07:25 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>

int		ft_printf(const char *fmt, ...);
int		ft_handle_flags(const char **fmt, va_list *ap);
int		ft_handle_mandatory(const char **fmt, va_list *ap);
size_t	ft_strlen(const char *s);
int		ft_putchar(const char c);
void	ft_putstr(const char *str);
int		ft_putnbr(long long nbr);
int		ft_putnbr_base_p(uintptr_t nb, char *base);
int		ft_putnbr_base(unsigned int nb, char *base);
int		ft_handle_s(const char *str);
int		ft_handle_u(unsigned int value);
int		ft_handle_d_i(int value);
int		ft_handle_x_x(const char c, long long value);
int		ft_handle_p(void*ptr);
int		ft_handle_c(int fmt);
int		ft_handle_percent(const char **fmt);
int		ft_handle_sharp(long long value, const char *fmt);
int		ft_handle_space(int value, const char **fmt);
int		ft_handle_plus(int value, const char **fmt);
#endif