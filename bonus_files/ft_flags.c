/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:15:28 by manmaria          #+#    #+#             */
/*   Updated: 2025/05/08 20:00:40 by manmaria         ###   ########.fr       */
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
			ft_flag_check_helper(s + i, &fbool);
		else if (s[i] == ' ')
			fbool->space = 1;
		else if (s[i] == '-')
			fbool->minus = 1;
		else if (s[i] == '0')
			ft_flag_check_helper(s + i, &fbool);
		else if (s[i] == '+')
			fbool->plus = 1;
	}
	ft_flag_check_helper(s + i, &fbool);
	*count = i;
	return (fbool);
}

// if nbr == 0 && precision == 0, strdup ("");
char	*ft_flags(const char *s, char *ret, int *p_fs, char spec)
{
	t_flags	*flag_info;
	size_t	len;

	len = ft_strlen(ret);
	flag_info = ft_flag_check(s, p_fs);
	if (ft_strcmp(ret, "0") == 0 && !flag_info->precision
		&& flag_info->in_precision == 1)
	{
		free(ret);
		ret = NULL;
		ret = ft_strdup("");
	}
	if (spec != '%')
	{
		if (ft_strrchr_b(ret, '-') == 1 && (spec == 'd' || spec == 'i'))
			ret = ft_negzeros(flag_info, ret, &len);
		else if (flag_info->in_precision == 1 && spec != 'p')
			ret = ft_has_precision(flag_info, ret, &len, spec);
		if (flag_info->hash == 1 || spec == 'p')
			ret = ft_sethash(ret, &len, flag_info, spec);
		else if (flag_info->plus == 1 && ft_strrchr_b(ret, '-') == 0 && (spec != 'd' || spec != 'i'))
			ret = ft_setchar_ra(ret, ++len, '+');
		if (flag_info->space == 1 && (spec == 'd' || spec == 'i') && flag_info->width <= len)
		{
			if (ft_strrchr_b(ret, '-') == 1)
				len--;
			ret = ft_setchar_ra(ret, ++len, ' ');
		}
		if (flag_info->width > len)
		{
			if(spec == 'c' && !*ret)
				flag_info->width--;
			ret = ft_width_bigger_len(flag_info, ret);
		}
	}
	free(flag_info);
	return (ret);
}

char	*ft_retmaisum(char *ret)
{
	char *dup;

	size_t	i;

	i = ft_strlen(ret);
	dup = malloc(i * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (ret[i + 1])
	{
		dup[i] = ret[i + 1];
		i++;
	}
	free(ret);
	dup[i] = '\0';
	return (dup);
}

char	*ft_negzeros(t_flags *fi, char *ret, size_t *len)
{
	char	*p_s = NULL;
	char	*dup = NULL;
	char	*tmp = NULL;
	size_t	i;

	if ((fi->zeros == 0 && fi->precision == 0)
		|| (fi->precision <= (*len - 1) && fi->in_precision))
		return (ret);
	i = 0;
	dup = ft_retmaisum(ret);
	if (!dup)
		return (NULL);
	//ret = NULL;
	if (fi->in_precision && (fi->precision > (*len - 1)))
		/*ret*/tmp = ft_setchar_ra(dup, fi->precision, '0');
	else if (dup && fi->zeros && (fi->width > (ft_strlen(dup) + 1)))
		/*ret*/tmp = ft_setchar_ra(dup, fi->width - 1, '0');
	else
		return (ft_setchar_ra(dup, ft_strlen(dup) + 1, '-'));
	                     //ret was here
	p_s = calloc(ft_strlen(tmp) + 2, sizeof(char));
	if (!p_s)
		return (free(tmp), NULL);
	p_s[i++] = '-';
	ft_strlcpy(p_s + 1, tmp, ft_strlen(tmp) + 1);
	free(tmp);
	*len = ft_strlen(p_s);
	return (p_s);
}
