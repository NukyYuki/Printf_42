/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:15:28 by manmaria          #+#    #+#             */
/*   Updated: 2025/05/11 01:47:09 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*ft_flagcheck(const char *s, int *count)
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

char	*flags_helper(char **ret)
{
	return (free(*ret), ft_strdup(""));
}

char	*ft_flags(const char *s, char *ret, int *p_fs, char *spec)
{
	t_flags	*fi;
	size_t	len;

	len = ft_strlen(ret);
	fi = ft_flagcheck(s, p_fs);
	if (ft_strcmp(ret, "0") == 0 && !fi->precision && fi->in_precision)
		ret = flags_helper(&ret);
	if (*spec == '%')
		return (free(fi), ret);
	if (ft_strrchr_b(ret, '-') == 1 && (check_spec(*spec, "di")))
		ret = ft_negzeros(fi, ret, &len);
	else if (fi->in_precision == 1 && *spec != 'p')
		ret = ft_has_precision(fi, ret, &len, *spec);
	if (fi->hash == 1 || *spec == 'p')
		ret = ft_sethash(ret, &len, fi, *spec);
	else if (fi->plus == 1 && check_spec(*spec, "di")
		&& !ft_strrchr_b(ret, '-'))
		ret = ft_setchar_ra(ret, ++len, '+');
	if (fi->space == 1 && check_spec(*spec, "di") && !ft_strrchr_b(ret, '-'))
		ret = ft_setchar_ra(ret, ++len, ' ');
	if (fi->width > len)
		ret = ft_check_ifnull(ret, fi, &spec);
	return (free(fi), ret);
}

char	*ft_check_ifnull(char *ret, t_flags *fi, char **spec)
{
	char		*s;
	size_t		i;

	if (**spec != 'c' || *ret)
		return (ret = ft_width_bigger_len(fi, ret));
	i = 0;
	if (!fi->minus)
		fi->width--;
	s = malloc(sizeof(char) * fi->width + 1);
	if (!s)
		return (NULL);
	if (fi->minus)
	{
		s[0] = 0;
		while (++i < fi->width)
			s[i] = ' ';
	}
	else if (!fi->minus)
		while (i < fi->width)
			s[i++] = ' ';
	s[i] = 0;
	**spec = 1;
	return (free(ret), s);
}

char	*ft_retmaisum(char *ret)
{
	char	*dup;
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
	char	*p_s;
	char	*dup;
	char	*tmp;
	size_t	i;

	if ((fi->zeros == 0 && fi->precision == 0)
		|| (fi->precision <= (*len - 1) && fi->in_precision))
		return (ret);
	i = 0;
	dup = ft_retmaisum(ret);
	if (!dup)
		return (NULL);
	if (fi->in_precision && (fi->precision > (*len - 1)))
		tmp = ft_setchar_ra(dup, fi->precision, '0');
	else if (dup && fi->zeros && (fi->width > (ft_strlen(dup) + 1)))
		tmp = ft_setchar_ra(dup, fi->width - 1, '0');
	else
		return (ft_setchar_ra(dup, ft_strlen(dup) + 1, '-'));
	p_s = calloc(ft_strlen(tmp) + 2, sizeof(char));
	if (!p_s || !tmp)
		return (free(tmp), free(tmp), NULL);
	p_s[i++] = '-';
	ft_strlcpy(p_s + 1, tmp, ft_strlen(tmp) + 1);
	*len = ft_strlen(p_s);
	return (free(tmp), p_s);
}
