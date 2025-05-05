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

#include "ft_printf.h"

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
	if (fbool->plus == 1)
		fbool->space = 0;
	*count = i; // or *count += i; if variable flag_skip is not used in printf();
	return (fbool);
}

int	check_spec(char const c, char *spec_lst)
{
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
	return (0);
}

char	*ft_flags(const char *s, char *ret, int *p_fs, char spec)
{
	t_flags	*flag_info;
	size_t	len;

	len = ft_strlen(ret);
	flag_info = ft_flag_check(s, p_fs);
	if (flag_info->in_precision == 1 && spec != 'p')
	{
		if (flag_info->precision > len && (spec != 's' && spec != 'c'))
		{
			len = flag_info->precision;
			ret = ft_setchar_ra(ret, len, '0');
		}
		else if (flag_info->precision < len && spec == 's')
		{
			len = flag_info->precision;
			ret = ft_substr(ret, 0, len);
		}
	}
	if (flag_info->hash == 1 || spec == 'p')
		ret = ft_sethash(ret, &len, flag_info, spec);
	else if (flag_info->plus == 1)
		ret = ft_setchar_ra(ret, ++len, '+');
	if (flag_info->space == 1 && (spec == 'd' || spec == 'i'))
		ret = ft_setchar_ra(ret, ++len, ' ');
/*	nova func a partir daqui  */
	if (flag_info->width > len)
	{
		if (flag_info->minus == 1)
			ret = ft_setspace_la(ret, flag_info->width);
		else if (flag_info->zeros == 1)
			ret = ft_setchar_ra(ret, flag_info->width, '0');
		else
			ret = ft_setchar_ra(ret, flag_info->width, ' ');
	}
	free(flag_info);
	return (ret);
}
