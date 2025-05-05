/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:48:43 by mipinhei          #+#    #+#             */
/*   Updated: 2025/05/05 17:10:32 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_decimal(long nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		nb = -nb;
		count += ft_putchar('-');
	}
	if (nb > 9)
	{
		count += ft_putnbr_decimal(nb / 10);
		count += ft_putnbr_decimal(nb % 10);
	}
	else
		count += ft_putchar(nb + '0');
	return (count);
}
