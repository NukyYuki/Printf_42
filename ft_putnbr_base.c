/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:49:48 by mipinhei          #+#    #+#             */
/*   Updated: 2025/04/23 20:04:19 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <limits.h>
int	ft_putnbr_base(long nb, char *base, int neg)
{
	int count;

	count = 0;
	if (neg)
		nb += 4294967295 + 1;
	neg = 0;
	if (nb > 15)
			count += ft_putnbr_base(nb / 16, base, neg);
	count += ft_putchar(base[nb % 16]);
	return (count);
}

int main(void)
{
		int ret;
		//int i = -154;
		int i = 42;
		printf("%x\n", i);
		ret = ft_putnbr_base(i, "0123456789abcdef", (i < 0));
//4294967295 + i + 1
		printf("\n%d", ret);
}
