/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 02:39:47 by manmaria          #+#    #+#             */
/*   Updated: 2025/05/13 02:39:48 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	lengths(int n)
{
	long		nb;
	size_t		len;

	len = 1;
	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb >= 10)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static char	*putnbr_str(int n, char *str)
{
	long	nb;
	size_t	len;

	nb = n;
	len = lengths(n);
	str[len] = '\0';
	if (nb < 0)
	{
		nb = -nb;
		str[0] = '-';
	}
	while (nb > 9)
	{
		str[len-- - 1] = (nb % 10) + '0';
		nb /= 10;
	}
	str[len - 1] = nb + '0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*itoa;

	itoa = malloc(sizeof(char) * (lengths(n) + 1));
	if (!itoa)
		return (NULL);
	putnbr_str(n, itoa);
	return (itoa);
}
