/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:55:08 by htam              #+#    #+#             */
/*   Updated: 2022/12/28 18:55:14 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft.h"

typedef int	(*t_format)(va_list);

int	ft_printf(const char *str, ...);
int	ft_format_decimal(va_list arg);
int	ft_format_string(va_list arg);
int	ft_format_char(va_list arg);
int	ft_putstr_len(char *str);
int	ft_putchar_len(char c);
int	ft_format_percent(va_list arg);
int	ft_format_unsigned(va_list arg);
int	ft_format_hex_lowercase(va_list arg);
int	ft_format_hex_uppercase(va_list arg);
int	ft_format_pointer(va_list arg);

#endif
