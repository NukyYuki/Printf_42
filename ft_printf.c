/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:07:41 by mipinhei          #+#    #+#             */
/*   Updated: 2025/04/23 15:58:12 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *str, ...)
{
	va_list	var_args;
	int		count;

	va_start(var_args, str);
	while (str)
	{
		while (*str != '%')
		{
			count += ft_putchar(*str);
			str++;
		}
		if (*str == '%')
		{
			count += ft_see_format(*str, var_args);
			if (!ft_see_format(*str, var_args))
				return (NULL);
			str += 2;
		}
	}
	return (count);
}
