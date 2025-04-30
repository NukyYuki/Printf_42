/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_hexa.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:49:48 by mipinhei          #+#    #+#             */
/*   Updated: 2025/04/29 19:46:54 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr_base_hexa(unsigned int nb, char *base)
{
	int		count;

	count = 0;
	if (nb > ((unsigned)ft_strlen(base) - 1))
		count += ft_putnbr_base_hexa(nb / (ft_strlen(base)), base);
	count += ft_putchar(base[nb % (ft_strlen(base))]);
	return (count);
}
