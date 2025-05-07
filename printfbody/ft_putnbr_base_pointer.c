/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_pointer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:49:48 by mipinhei          #+#    #+#             */
/*   Updated: 2025/05/07 12:15:38 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_pt(unsigned long nb, char *base)
{
	int		count;

	count = 0;
	if (nb > ((unsigned long)ft_strlen(base) - 1))
		count += ft_putnbr_pt(nb / (ft_strlen(base)), base);
	count += ft_putchar(base[nb % (ft_strlen(base))]);
	return (count);
}
