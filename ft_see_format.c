/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_see_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:53:50 by mipinhei          #+#    #+#             */
/*   Updated: 2025/04/24 14:10:05 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_see_format(const char *s, va_list var_args)
{
	int	count;

	count = 0;
	if (*s + 1 == 'c')
		count += ft_putchar(va_arg(var_args, char));
	else if (*s + 1 == 's')
		count += ft_putstr(va_arg(var_args, char *));
	else if (*s + 1 == 'i' || *s + 1 == 'd')
		count += ft_putnbr_decimal(va_arg(var_args, int));
	else if (*s + 1 == 'u')
		count += ft_putnbr_decimal(va_arg(var_args, unsigned int));
	else if (*s + 1 == 'x')
		count += ft_putnbr_base_base_hexa(va_arg(var_args, int),
				"0123456789abcdef");
	else if (*s + 1 == 'X')
		count += ft_putnbr_base_base_hexa(va_arg(var_args, int),
				"0123456789ABCDEF");
	else if (*s + 1 == 'p')
		count += ft_putnbr_base_hexa(va_arg(var_args, void *),
				"0123456789acdef");
	else if (*s + 1 == '%')
		count += ft_putchar('%');
	else
		return (0);
	return (count);
}
