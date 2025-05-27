/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_see_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 02:42:50 by manmaria          #+#    #+#             */
/*   Updated: 2025/05/13 02:42:52 by manmaria         ###   ########.fr       */
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
	else if (*s == 'x' || *s == 'X' || *s == 'u')
		return (return_val = ft_itoa_base(va_arg(varg, unsigned int), base));
	else if (*s == 'p')
		return (return_val = ft_set_point(va_arg(varg, void *), base));
	else if (*s == '%')
		return (return_val = ft_dupchar('%'));
	return (NULL);
}

char	*ft_set_point(void *ptr, char *base)
{
	unsigned long	val;

	val = (unsigned long)ptr;
	if (!ptr)
		return (ft_strdup("(nil)"));
	return (ft_itoa_pt(val, base));
}
