/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:07:41 by mipinhei          #+#    #+#             */
/*   Updated: 2025/05/05 17:10:32 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	var_args;
	int		count;
	int		i;
	int		ret;

	va_start(var_args, str);
	i = 0;
	count = 0;
	ret = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			ret = ft_see_format(&str[i], var_args);
			if (ret == -1)
				return (-1);
			count += ret;
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
