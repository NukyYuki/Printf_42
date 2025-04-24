/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_hexa.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:49:48 by mipinhei          #+#    #+#             */
/*   Updated: 2025/04/24 13:35:51 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr_base_hexa(long nb, char *base)
{
	int	count;

	count = 0;
	if (nb < 0)
		nb += 4294967295 + 1;
	if (nb > (ft_strlen(base) - 1))
		count += ft_putnbr_base_hexa(nb / (ft_strlen(base)), base);
	count += ft_putchar(base[nb % (ft_strlen(base))]);
	return (count);
}
