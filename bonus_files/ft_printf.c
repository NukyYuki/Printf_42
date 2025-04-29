/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:29:33 by mipinhei          #+#    #+#             */
/*   Updated: 2025/04/29 17:27:19 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	check_spec(char const c, char *spec_lst);

t_flags	*flag_check(const char *s, int count)
{
	t_flags	*fbool;
	int		i;

	i = 0;
	fbool = ft_calloc(1, sizeof(t_flags)); //calloc to set all vars to 0
	while (check_spec(s[i], "cspdiuxX%") == 0)
	{
		if (s[i] == '#')
			fbool->hash = 1;
		else if	(s[i] == '.')
			fbool->in_precision = 1;
		else if (s[i] >= '1' && s[i] <= '9')
		{
			if (fbool->in_precision == 1)
				fbool->precision = fbool->precision * 10 + (s[i] - 48);
			else
				fbool->width = fbool->width * 10 + (s[i] - 48);
			fbool->in_value = 1;
		}
		else if (s[i] == ' ')
			fbool->space = 1;
		else if (s[i] == '-')
			fbool->minus = 1;
		else if (s[i] == '0')
		{
			if (!fbool->in_precision && !fbool->in_value && fbool->zeros == 0)
				fbool->zeros = 1;
			else if (fbool->in_precision)
				fbool->precision = fbool->precision * 10 + (s[i] - 48);
			else
				fbool->width = fbool->width * 10 + (s[i] - 48);
			fbool->in_value = 1;

		}
		else if (s[i] == '+')
			fbool->plus = 1;
		i++;
	}
	if (fbool->minus == 1 || fbool->in_precision == 1)
		fbool->zeros = 0;
	if (fbool->plus == 1)
		fbool->space = 0;
	return (fbool);
}

int	check_spec(char const c, char *spec_lst)
{
	int	i;

	i = 0;
	while (*spec_lst)
	{
		if (c == *spec_lst)
			return (1);
		spec_lst++;
	}
	return (0);
}

char	*ft_strchr(const char *s)
{
	int	i;

	i = 0;
	while (check_spec(s[i], "cspdiuxX%") == 0)
	{
		if (s[i] == '\0')
			break ;
		i++;
	}
	if (check_spec(s[i], "cspdiuxX%") == 1)
	{
		return ((char *)s + i);
	}
	return (NULL);
}


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
			ret = ft_see_format(ft_strchr(str + i + 1), var_args);
			//count += ret;// if see_format worked, then count gets the addition
			//i += 2;
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
