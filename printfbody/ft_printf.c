/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:07:41 by mipinhei          #+#    #+#             */
/*   Updated: 2025/04/24 14:05:27 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *str, ...)
{
	va_list	var_args;
	int		count;
	int		i;

	va_start(var_args, str);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '%' && str[i] != '\0')
		{
			count += ft_putchar(str[i]);
			i++;
		}
		if (str[i] == '%')
		{
			count += ft_see_format(str + i, var_args);
			if (!ft_see_format(str, var_args))
				return (0);
			i += 2;
		}
	}
	va_end (var_args);
	return (count);
}
