/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:15:28 by manmaria          #+#    #+#             */
/*   Updated: 2025/05/02 11:16:45 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
		else if (s[i] == '.')
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
	if (fbool->plus == 1 || fbool->width > 0)
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

//											  s[*p_i] = '%'
char	*ft_flags(const char *s, char *ret, int *p_fs, char spec)
{
	t_flags	*flag_info;
	char	*tmp;
	int		len;

	len = ft_strlen(ret);
	tmp = ret;
	flag_info = ft_flag_check(s, p_fs);
	if (spec == 'p')
		flag_info->hash = 1;
	if (flag_info->in_precision == 1)
	{
		if (flag_info->precision > len && spec != 's')
		{
			len = flag_info->precision;
			ret = ft_setchar_ra(ret, tmp, len, '0');
			tmp = ret;
		}
		else if (flag_info->precision < len && spec == 's')
			len = flag_info->precision;
	}
	if (flag_info->hash == 1)
		ft_sethash(ret, tmp, len + 2, spec);
	else if (flag_info->plus == 1)
	{
		ret = ft_setchar_ra(ret, tmp, len + 1, '+');
		tmp = ret;
	}
/*	nova func a partir daqui  */

	return (ret);
}
