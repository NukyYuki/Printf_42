/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:39:48 by mipinhei          #+#    #+#             */
/*   Updated: 2025/04/29 19:10:15 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	lengths(int n, int base_len)
{
	long		nb;
	size_t		len;

	len = 0;
	nb = n;
	if (nb == 0)
		len++;
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / base_len;
		len++;
	}
	return (len);
}

static char	*putnbr_str(int n, char *str, char *base, int base_len)
{
	long	nb;
	size_t	i;
	size_t	len;

	nb = n;
	len = lengths(n, base_len);
	i = 0;
	str[len] = '\0';
	len--;
	if (nb < 0)
	{
		nb = -nb;
		str[i] = '-';
		i++;
	}
	while (nb >= base_len)
	{
		str[len] = base[nb % base_len];
		nb /= base_len;
		len--;
	}
	str[i] = base[nb];
	return (str);
}

char	*ft_itoa_base(int n, char *base)
{
	char	*itoa;
	int		base_len;

	base_len = ft_strlen(base);
	itoa = malloc(sizeof(char) * (lengths(n, base_len) + 1));
	if (!itoa)
		return (NULL);
	putnbr_str(n, itoa, base, base_len);
	return (itoa);
}
#include <stdio.h>
int	main(void)
{
		char	*s;

		s = ft_itoa_base(42, "0123456789abcdef");
		printf("%s", s);
		free(s);
		return 0;
}
