/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:32:24 by mipinhei          #+#    #+#             */
/*   Updated: 2025/05/07 12:37:31 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_set_point(void *ptr, char *base)
{
	unsigned long	val;

	val = (unsigned long)ptr;
	if (!ptr)
		return (ft_strdup("(nil)"));
	return (ft_itoa_pt(val, base));
}
