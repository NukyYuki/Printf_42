/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_see_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:53:50 by mipinhei          #+#    #+#             */
/*   Updated: 2025/04/23 19:31:42 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_see_format(const char *s, va_list var_args)
{
	int	count;

	count = 0;
	if (*s + 1 == 'c')
		count += ft_putchar(va_arg(va_args, char));
	else if (*s + 1 == 's')
		count += ft_putstr(va_arg(va_args, char *));
	else if (*s + 1 == 'i' || *s + 1 == 'd')
		count += ft_putnbr(va_arg(va_args, int));
	else if (*s + 1 == 'u')
		count += ft_putnbr_base(va_arg(va_args, unsigned int));
	else if (*s + 1 == 'x')
		count += ft_putnbr_base_lower(va_arg(va_args, int));
	else if (*s + 1 == 'X')
		count += ft_putnbr_base_upper(va_arg(va_args, int));
	else if (*s + 1 == 'p')
		count += ft_print_hexa();
	else if (*s + 1 == '%')
		count += ft_putchar('%');
	else
		return (NULL);
	return (count);
}
