/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setpercent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:22:11 by mipinhei          #+#    #+#             */
/*   Updated: 2025/05/06 16:59:13 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_setpercent(va_list var_args, const char *str, int *p, int count)
{
	char	*ret;
	char	spec;
	int		flag_skip;

	flag_skip = 0;
	ret = 0;
	spec = ft_strchr(str + ++(*p));
	ret = ft_see_format(&spec, var_args);
	ret = ft_flags(str + *p, ret, &flag_skip, spec);
	*p += flag_skip;
	count += ft_putstr(ret);
	*p += 1;
	free(ret);
	return (count);
}
