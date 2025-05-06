/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_see_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:53:50 by mipinhei          #+#    #+#             */
/*   Updated: 2025/05/05 17:10:32 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_see_format(const char *s, va_list var_args)
{
	int		count;
	char	spec;

	count = 0;
	spec = s[1];
	if (spec == 'c')
		count += ft_putchar(va_arg(var_args, int));
	else if (spec == 's')
		count += ft_putstr(va_arg(var_args, char *));
	else if (spec == 'i' || spec == 'd')
		count += ft_putnbr_decimal(va_arg(var_args, int));
	else if (spec == 'u')
		count += ft_putnbr_decimal(va_arg(var_args, unsigned int));
	else if (spec == 'x')
		count += ft_putnbr_base_hexa(va_arg(var_args, unsigned int),
				"0123456789abcdef");
	else if (spec == 'X')
		count += ft_putnbr_base_hexa(va_arg(var_args, unsigned int),
				"0123456789ABCDEF");
	else if (spec == 'p')
	{
		count += ft_putstr("0x");
		count += ft_putnbr_base_pointer(va_arg(var_args, long),
				"0123456789abcdef");
	}
	else if (spec == '%')
		count += ft_putchar('%');
	else
	{
		count += ft_putchar('%');
		count += ft_putchar(s[1]);
	}
	return (count);
}
