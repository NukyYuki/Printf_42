/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 00:56:10 by manmaria          #+#    #+#             */
/*   Updated: 2025/05/06 20:14:03 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *s)
{
	return (write(1, s, ft_strlen(s)));
}

int	ft_setpercent(va_list var_args, const char *str, int *p, int count)
{
	char	*ret;
	char	spec;
	int		flag_skip;

	flag_skip = 0;
	ret = 0;
	spec = ft_strchr(str + ++(*p));
	ret = ft_see_format(&spec, var_args);
	ret = ft_flags(str + *p, ret, &flag_skip, spec);
	*p += flag_skip;
	count += ft_putstr(ret);
	*p += 1;
	free(ret);
	return (count);
}

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
			count = ft_setpercent(var_args, str, &i, count);
	}
	va_end (var_args);
	return (count);
}
/*			char spec = ft_strchr(str + ++i);
			ret = ft_see_format(&spec, var_args);
			int flag_skip = 0;
			ret = ft_flags(str + i, ret, &flag_skip, spec);
			i += flag_skip;
			count += ft_putstr(ret);
			i++;
			free(ret);*/
