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

char	*ft_see_format(const char *s, va_list var_args)
{
	int		count;
	int		i;
	char	*return_val;

	count = 0;
	i = 0;
	if (s[i + 1] == 'c')
		return_val = ft_strdup((char *)&va_arg(varg, int));
	else if (s[i + 1] == 's')
		return_val = ft_strdup(va_arg(varg, char *));
	else if (s[i + 1] == 'i' || s[i + 1] == 'd')
		return_val = ft_itoa_base(va_arg(varg, unsigned long));
	else if (s[i + 1] == 'u')
		return_val = ft_itoa_base(va_arg(varg, unsigned long));
	else if (s[i + 1] == 'x')
		return_val = ft_itoa_base(va_arg(varg, unsigned long);
				"0123456789abcdef");
	else if (s[i + 1] == 'X')
		return_val = ft_itoa_base(va_arg(varg, unsigned long);
				"0123456789ABCDEF");
	else if (s[i + 1] == 'p')
		return_val = ft_itoa_base(va_arg(varg, unsigned long);
				"0123456789abcdef");
	else if (s[i + 1] == '%')
			return_val = ft_strdup("%");
	return (return_val);
}
