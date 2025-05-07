/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_see_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:53:50 by mipinhei          #+#    #+#             */
/*   Updated: 2025/05/07 12:18:45 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init(char **base, char *s, int *count, char *spec)
{
	*count = 0;
	*spec = s[1];
	if (*spec == 'X')
		*base = "0123456789ABCDEF";
	else if (*spec == 'u')
		*base = "0123456789";
	else
		*base = "0123456789abcdef";
}

int	ft_print_inv(char *s, int count)
{
	count += ft_putchar('%');
	count += ft_putchar(s[1]);
	return (count);
}

int	ft_see_format(const char *s, va_list var_args)
{
	int		count;
	char	spec;
	char	*base;

	ft_init(&base, (char *)s, &count, &spec);
	if (spec == 'c')
		count += ft_putchar(va_arg(var_args, int));
	else if (spec == 's')
		count += ft_putstr(va_arg(var_args, char *));
	else if (spec == 'i' || spec == 'd')
		count += ft_putnbr_decimal(va_arg(var_args, int));
	else if (spec == 'x' || spec == 'X' || spec == 'u')
		count += ft_putnbr_hex(va_arg(var_args, unsigned int), base);
	else if (spec == 'p')
		count += ft_print_pt(va_arg(var_args, void *), base);
	else if (spec == '%')
		count += ft_putchar('%');
	else
		count = ft_print_inv((char *)s, count);
	return (count);
}
