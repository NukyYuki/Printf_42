/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:15:28 by manmaria          #+#    #+#             */
/*   Updated: 2025/05/06 10:57:30 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*ft_flag_check(const char *s, int *count)
{
	t_flags	*fbool;
	int		i;
	
	fbool = ft_calloc(1, sizeof(t_flags));
	i = -1;
	while (check_spec(s[++i], "cspdiuxX%") == 0)
	{
		if (s[i] == '#')
			fbool->hash = 1;
		else if (s[i] == '.')
			fbool->in_precision = 1;
		else if (s[i] >= '1' && s[i] <= '9')
			ft_flag_check_helper(s, &fbool);
		else if (s[i] == ' ')
			fbool->space = 1;
		else if (s[i] == '-')
			fbool->minus = 1;
		else if (s[i] == '0')
			ft_flag_check_helper(s, &fbool);
		else if (s[i] == '+')
			fbool->plus = 1;
	}
	ft_flag_check_helper(s, &fbool);
	*count = i;
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
		ft_has_precision(flag_info, ret, &len, spec);
		/*if (flag_info->precision > len && (spec != 's' && spec != 'c'))
		{
			len = flag_info->precision;
			ret = ft_setchar_ra(ret, len, '0');
		}
		else if (flag_info->precision < len && spec == 's')
		{
			len = flag_info->precision;
			ret = ft_substr(ret, 0, len);
		}*/
	}
	if (flag_info->hash == 1 || spec == 'p')
		ret = ft_sethash(ret, &len, flag_info, spec);
	else if (flag_info->plus == 1)
		ret = ft_setchar_ra(ret, ++len, '+');
	if (flag_info->space == 1 && (spec == 'd' || spec == 'i'))
		ret = ft_setchar_ra(ret, ++len, ' ');
	if (flag_info->width > len)
	{
		ft_width_bigger_len(flag_info, ret);
/*		if (flag_info->minus == 1)
			ret = ft_setspace_la(ret, flag_info->width);
		else if (flag_info->zeros == 1)
			ret = ft_setchar_ra(ret, flag_info->width, '0');
		else
			ret = ft_setchar_ra(ret, flag_info->width, ' ');*/
	}
	free(flag_info);
	return (ret);
}
