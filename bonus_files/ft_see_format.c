/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_see_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:53:50 by mipinhei          #+#    #+#             */
/*   Updated: 2025/04/29 20:08:03 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_see_format(const char *s, va_list varg)
{
	int		count;
	char	c;
	char	*return_val;

	count = 0;
	if (*s == 'c')
	{
		c = va_arg(varg, int);
		return (return_val = ft_strdup((char *)&c));
	}
	else if (*s == 's')
		return (return_val = ft_strdup(va_arg(varg, char *)));
	else if (*s == 'i' || *s == 'd')
		return (return_val = ft_itoa_base(va_arg(varg, unsigned long), "0123456789"));
	else if (*s == 'u')
		return (return_val = ft_itoa_base(va_arg(varg, unsigned long), "0123456789"));
	else if (*s == 'x')
		return (return_val = ft_itoa_base(va_arg(varg, unsigned long), "0123456789abcdef"));
	else if (*s == 'X')
		return (return_val = ft_itoa_base(va_arg(varg, unsigned long), "0123456789ABCDEF"));
	else if (*s == 'p')
		return (return_val = ft_itoa_base(va_arg(varg, unsigned long), "0123456789abcdef"));
	else if (*s == '%')
		return (return_val = ft_strdup("%"));
	return (NULL);
}
