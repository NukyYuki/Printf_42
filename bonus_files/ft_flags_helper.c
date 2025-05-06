/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:07:00 by mipinhei          #+#    #+#             */
/*   Updated: 2025/05/06 15:42:31 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_check_helper(const char *s, t_flags **fb)
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
/*		THE VERIFICATIONS ABOVE BEFORE TRIMMING FT_FLAG:
		else if (s[i] >= '1' && s[i] <= '9')
		{
			if (fbool->in_precision == 1)
				fbool->precision = fbool->precision * 10 + (s[i] - 48);
			else
				fbool->width = fbool->width * 10 + (s[i] - 48);
			fbool->in_value = 1;
		}
 
			if (!fbool->in_precision && !fbool->in_value && !fbool->zeros)
				fbool->zeros = 1;
			else if (fbool->in_precision)
				fbool->precision = fbool->precision * 10 + (s[i] - 48);
			else
				fbool->width = fbool->width * 10 + (s[i] - 48);
			fbool->in_value = 1;
		}
*/

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
