/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:15:28 by manmaria          #+#    #+#             */
/*   Updated: 2025/05/13 02:39:18 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*ft_flagcheck(const char *s, int *count)
{
	t_flags	*fbool;
	int		i;

	fbool = ft_calloc(1, sizeof(t_flags));
	i = -1;
	while (ft_checkspec(s[++i], "cspdiuxX%") == 0)
	{
		if (s[i] == '#')
			fbool->hash = 1;
		else if (s[i] == '.')
			fbool->in_precision = 1;
		else if (s[i] >= '1' && s[i] <= '9')
			ft_flagcheck_helper(s + i, &fbool);
		else if (s[i] == ' ')
			fbool->space = 1;
		else if (s[i] == '-')
			fbool->minus = 1;
		else if (s[i] == '0')
			ft_flagcheck_helper(s + i, &fbool);
		else if (s[i] == '+')
			fbool->plus = 1;
	}
	ft_flagcheck_helper(s + i, &fbool);
	*count = i;
	return (fbool);
}

char	*ft_flags(const char *s, char *ret, int *p_fs, char *spec)
{
	t_flags	*fi;
	size_t	len;

	len = ft_strlen(ret);
	fi = ft_flagcheck(s, p_fs);
	if (ft_strcmp(ret, "0") == 0 && !fi->precision && fi->in_precision)
		ret = ft_minihelper(&ret);
	if (*spec == '%')
		return (free(fi), ret);
	if (ft_strrchr_b(ret, '-') == 1 && (ft_checkspec(*spec, "di")))
		ret = ft_negzeros(fi, ret, &len);
	else if (fi->in_precision == 1 && *spec != 'p')
		ret = ft_has_precision(fi, ret, &len, *spec);
	if (fi->hash == 1 || *spec == 'p')
		ret = ft_sethash(ret, &len, fi, *spec);
	else if (fi->plus == 1 && ft_checkspec(*spec, "di")
		&& !ft_strrchr_b(ret, '-'))
		ret = ft_setchar_ra(ret, ++len, '+');
	if (fi->space == 1 && ft_checkspec(*spec, "di") && !ft_strrchr_b(ret, '-'))
		ret = ft_setchar_ra(ret, ++len, ' ');
	if (fi->width > len)
		ret = ft_check_ifnull(ret, fi, &spec);
	return (free(fi), ret);
}
