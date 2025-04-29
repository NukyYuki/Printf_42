/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:29:33 by mipinhei          #+#    #+#             */
/*   Updated: 2025/04/29 17:27:19 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *s, ...)
{
	va_list	vargs;
	int		count;
	int		i;

	va_start(vargs, s);
	i = 0;
	count = 0;
	print(s)
	count += ft_flags(*s)
	va_end(vargs);
	return (count);
}
