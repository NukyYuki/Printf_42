/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_see_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:53:50 by mipinhei          #+#    #+#             */
/*   Updated: 2025/04/29 18:33:56 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_see_format(const char *s, va_list var_args)
{
	int		count;
	int		i;
	char	*return_val;

	count = 0;
	i = 0;
	if (s[i + 1]  == 'c')
		return_val = strdup((char *)&va_arg(varg, int));
	else if (s[i + 1] == 's')
		return_val = ft_strdup(va_arg(varg, char *));
	else if (s[i + 1] == 'i' || s[i + 1] == 'd')
		return_val = ft_itoa(va_arg(varg, int));
	else if (s[i + 1] == 'u')
		return_val = ft_itoa(va_arg(varg, int));
	else if (s[i + 1] == 'x')
		return_val = ft_itoa_base(va_arg(varg, int));
	else if (s[i + 1] == 'X')
		count += ft_putnbr_base_hexa(va_arg(var_args, int),
				"0123456789ABCDEF");
	else if (s[i + 1] == 'p')
		count += ft_putnbr_base_hexa(va_arg(var_args, long),
				"0123456789acdef");
	else if (s[i + 1] == '%')
		count += ft_putchar('%');
	else
		return (-1);
	return (count);
}
