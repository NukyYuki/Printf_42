/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 00:56:10 by manmaria          #+#    #+#             */
/*   Updated: 2025/05/02 11:17:20 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_printf(const char *str, ...)
{
	va_list	var_args;
	int		count;
	int		i;
	char	*ret;

	va_start(var_args, str);
	i = 0;
	count = 0;
	ret = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '%' && str[i] != '\0')
		{
			count += ft_putchar(str[i]);
			i++;
		}
		if (str[i] == '%')
		{
			char spec = ft_strchr(str + ++i);
			ret = ft_see_format(&spec, var_args);
			int flag_skip = 0;
			ret = ft_flags(str + i, ret, &flag_skip, spec);
			i += flag_skip;
			count += ft_putstr(ret);
			i++;
			free(ret);
		}
	}
	va_end (var_args);
	return (count);
}
/*
int	ft_printf(const char *s, ...)
{
	va_list	vargs;
	int		count;
	int		i;

	va_start(vargs, s);
	i = 0;
	count = 0;
	print(s)
	count += ft_flags(*s)
	va_end(vargs);
	return (count);
}*/
