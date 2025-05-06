/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_see_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:53:50 by mipinhei          #+#    #+#             */
/*   Updated: 2025/05/06 21:47:04 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init(char **return_val, char **base, int spec)
{
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
	char	*return_val;
	char	*base;

	ft_init(&return_val, &base, *s);
	if (*s == 'c')
		return (return_val = ft_dupchar(va_arg(varg, int)));
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
		return (return_val = ft_dupchar('%'));
	return (NULL);
}
