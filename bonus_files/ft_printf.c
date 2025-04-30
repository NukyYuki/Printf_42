/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 00:56:10 by manmaria          #+#    #+#             */
/*   Updated: 2025/04/30 17:18:58 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	check_spec(char const c, char *spec_lst);

t_flags	*ft_flag_check(const char *s, int *count)
{
	t_flags	*fbool;
	int		i;

	i = 0;
	fbool = ft_calloc(1, sizeof(t_flags));
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
			if (!fbool->in_precision && !fbool->in_value && !fbool->zeros)
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
	*count = i; // or *count += i; if variable flag_skip is not used in printf();
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

char	ft_strchr(const char *s)
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
		return ((char)s[i]);
	}
	return (0); //nsei se devia retornar '\0' aqui ou outra coisa
}

 //TODO:
	//ESTA FUNCAO VAI UTILIZAR A INFO NA VAR TIPO t_flags
	//E MODIFICAR A STR ret PARA A O FORMATO DAS FLAGS.
	//PRECISAMOS DE SABER QUAL O SPEC QUE ESTA' DEPOIS DAS
	//FLAGS PARA FORMATARMOS ACCORDINGLY
//											  s[*p_i] = '%'
char	*ft_flags(const char *s, char *ret, int *p_fs, char spec)
{
	t_flags	*flag_info;
	char	*tmp;
	int		len;

	len = ft_strlen(ret);
	if (spec == 'p')
		flag_info->hash = 1;
	tmp = ret;
	flag_info = ft_flag_check(s, p_fs);
	if (flag_info->hash == 1)
		len += 2;
	if (flag_info->precision > len)
		len += flag_info->precision - len;
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
			char spec = ft_strchr(str + i + 1);
			ret = ft_see_format(&spec, var_args);
			int flag_skip = 0;
			ft_flags(str + i, ret, &flag_skip, spec);
			i += flag_skip;
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
