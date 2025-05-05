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

#include "ft_printf.h"

void	ft_init(char **return_val, char **base, char *c, int spec)
{
	*c = 0;
	*return_val = NULL;
	if (spec == 'X')
		*base = "0123456789ABCDEF";
	else if (spec == 'x' || spec == 'p')
		*base = "0123456789abcdef";
	else
		*base = "0123456789";
}

char	*ft_see_format(const char *s, va_list varg)
{
	char	c;
	char	*return_val;
	char	*base;

	ft_init(&return_val, &base, &c, *s);
	if (*s == 'c')
	{
		c = va_arg(varg, int);
		if (c < 0)
			return (ft_strdup("0"));
		return (return_val = ft_strdup(return_val));

	}
	else if (*s == 's')
		return (return_val = ft_strdup(va_arg(varg, char *)));
	else if (*s == 'i' || *s == 'd')
		return (return_val = ft_itoa(va_arg(varg, int)));
	else if (*s == 'u')
		return (return_val = ft_itoa_base(va_arg(varg, unsigned long), base));
	else if (*s == 'x')
		return (return_val = ft_itoa_base(va_arg(varg, unsigned long), base));
	else if (*s == 'X')
		return (return_val = ft_itoa_base(va_arg(varg, unsigned long), base));
	else if (*s == 'p')
		return (return_val = ft_itoa_base(va_arg(varg, unsigned long), base));
	else if (*s == '%')
		return (return_val = ft_strdup("%"));
	return (NULL);
}
