/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:22:25 by mipinhei          #+#    #+#             */
/*   Updated: 2025/05/07 12:19:37 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr_hex(unsigned int nb, char *base);
int		ft_putnbr_pt(unsigned long nb, char *base);
int		ft_putnbr_decimal(long nb);
int		ft_strlen(char *s);
int		ft_see_format(const char *s, va_list var_args);
int		ft_print_pt(void *ptr, char *base);

#endif
