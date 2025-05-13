/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_helper2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:25:57 by manmaria          #+#    #+#             */
/*   Updated: 2025/05/13 02:06:03 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_mini_helper(char **ret)
{
	return (free(*ret), ft_strdup(""));
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

char	*ft_ret_abs(char *ret)
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

	if ((!fi->zeros && fi->precision == 0)
		|| (fi->precision <= (*len - 1) && fi->in_precision))
		return (ret);
	i = 0;
	dup = ft_ret_abs(ret);
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
		return (free(tmp), free(p_s), NULL);
	p_s[i++] = '-';
	ft_strlcpy(p_s + 1, tmp, ft_strlen(tmp) + 1);
	*len = ft_strlen(p_s);
	return (free(tmp), p_s);
}
