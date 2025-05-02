/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:42:18 by mipinhei          #+#    #+#             */
/*   Updated: 2025/05/02 11:42:52 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putstr(char *s)
{
	int	count;

	if (!s)
		return (ft_putstr("(null)"));
	count = 0;
	while (s[count])
		count += ft_putchar(s[count]);
	return (count);
}
