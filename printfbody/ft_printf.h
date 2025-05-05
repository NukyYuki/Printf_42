/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:22:25 by mipinhei          #+#    #+#             */
/*   Updated: 2025/05/05 17:10:19 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_type
{
	int	width;
	int	minus;
	int	zeros;
	int	precision;
	int	hash;
	int	space;
	int	plus;
}			t_flags;

void	ft_bzero(void *s, size_t n);
int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr_base_hexa(unsigned int nb, char *base);
int		ft_putnbr_base_pointer(long nb, char *base);
int		ft_putnbr_decimal(long nb);
int		ft_strlen(char *s);
int		ft_see_format(const char *s, va_list var_args);

#endif
