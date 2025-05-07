/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:07:41 by mipinhei          #+#    #+#             */
/*   Updated: 2025/05/07 11:25:51 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	var_args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(var_args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			count += ft_see_format(&str[i], var_args);
			i += 2;
		}
		else
		{
			if (ft_putchar(str[i++]) == -1)
				return (-1);
			count++;
		}
	}
	va_end (var_args);
	return (count);
}
