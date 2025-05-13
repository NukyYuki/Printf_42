/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_pt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 02:42:13 by manmaria          #+#    #+#             */
/*   Updated: 2025/05/13 02:42:14 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	lengths(unsigned long n, int base_len)
{
	size_t		len;

	len = 0;
	if (n == 0)
		len++;
	while (n > 0)
	{
		n = n / base_len;
		len++;
	}
	return (len);
}

static char	*putnbr_str(unsigned long n, char *str, char *base, int base_len)
{
	size_t	i;
	size_t	len;

	len = lengths(n, base_len);
	i = 0;
	str[len] = '\0';
	len--;
	while (n >= (unsigned long)base_len)
	{
		str[len] = base[n % base_len];
		n /= base_len;
		len--;
	}
	str[i] = base[n];
	return (str);
}

char	*ft_itoa_pt(unsigned long n, char *base)
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
