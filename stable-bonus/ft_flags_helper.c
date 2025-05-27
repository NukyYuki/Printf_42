/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 02:38:39 by manmaria          #+#    #+#             */
/*   Updated: 2025/05/13 02:38:41 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flagcheck_helper(const char *s, t_flags **fb)
{
	if (*s >= '0' && *s <= '9')
	{
		if (*s == '0' && !(*fb)->in_precision
			&& !(*fb)->in_value && !(*fb)->zeros)
			(*fb)->zeros = 1;
		else if ((*s >= '1' && *s <= '9') || *s == '0')
		{
			if ((*fb)->in_precision)
				(*fb)->precision = (*fb)->precision * 10 + (*s - 48);
			else
				(*fb)->width = (*fb)->width * 10 + (*s - 48);
		}
		(*fb)->in_value = 1;
		return ;
	}
	if ((*fb)->minus == 1 || (*fb)->in_precision == 1)
		(*fb)->zeros = 0;
	if ((*fb)->plus == 1)
		(*fb)->space = 0;
}

char	*ft_width_bigger_len(t_flags *fi, char *ret)
{
	if (fi->minus == 1)
		ret = ft_setspace_la(ret, fi->width);
	else if (fi->zeros == 1)
		ret = ft_setchar_ra(ret, fi->width, '0');
	else
		ret = ft_setchar_ra(ret, fi->width, ' ');
	return (ret);
}

char	*ft_has_precision(t_flags *fi, char *ret, size_t *len, char spec)
{
	if (fi->precision > *len && (spec != 's' && spec != 'c'))
	{
		*len = fi->precision;
		ret = ft_setchar_ra(ret, *len, '0');
	}
	else if (fi->precision < *len && spec == 's')
	{
		if (ft_strcmp(ret, "(nil)") == 0 || ft_strcmp(ret, "(null)") == 0)
		{
			*len = 0;
			free(ret);
			return (ft_strdup(""));
		}
		*len = fi->precision;
		ret = ft_substr(ret, 0, *len);
	}
	return (ret);
}
