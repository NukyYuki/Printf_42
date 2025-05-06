/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ftflags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:07:00 by mipinhei          #+#    #+#             */
/*   Updated: 2025/05/06 10:54:00 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_width_bigger_len(t_flags *flag_info, char *ret)
{
	if (flag_info->minus == 1)
		ret = ft_setspace_la(ret, flag_info->width);
	else if (flag_info->zeros == 1)
		ret = ft_setchar_ra(ret, flag_info->width, '0');
	else
		ret = ft_setchar_ra(ret, flag_info->width, ' ');
	return (ret);
}

char	*ft_has_precision(t_flags *flag_info, char *ret, size_t *len, char spec)
{
	if (flag_info->precision > *len && (spec != 's' && spec != 'c'))
	{
		*len = flag_info->precision;
		ret = ft_setchar_ra(ret, *len, '0');
	}
	else if (flag_info->precision < *len && spec == 's')
	{
		*len = flag_info->precision;
		ret = ft_substr(ret, 0, *len);
	}
	return (ret);
}
