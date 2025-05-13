/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 00:56:10 by manmaria          #+#    #+#             */
/*   Updated: 2025/05/13 02:31:44 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_setpercent(va_list var_args, const char *str, int *p, int count)
{
	char	*ret;
	char	spec;
	int		flag_skip;

	flag_skip = 0;
	ret = 0;
	spec = ft_strchr(str + ++(*p));
	ret = ft_see_format(&spec, var_args);
	ret = ft_flags(str + *p, ret, &flag_skip, &spec);
	*p += flag_skip + 1;
	count += ft_putstr_spec(ret, spec);
	free(ret);
	return (count);
}

int	ft_putstr_spec(const char *s, char spec)
{
	int	i;

	i = 0;
	if (spec == 1)
	{
		if (s[0] == 0)
		{
			i += write(1, "", 1);
			i += write(1, &s[1], ft_strlen(&s[1]));
		}
		else
		{
			i += write(1, s, ft_strlen(s));
			i += write(1, "", 1);
		}
		return (i);
	}
	if (spec == 'c' && !*s)
		i += write(1, "", 1);
	else
		i += write(1, s, ft_strlen(s));
	return (i);
}

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

char	*ft_return_null(void)
{
	return (ft_strdup("(null)"));
}
