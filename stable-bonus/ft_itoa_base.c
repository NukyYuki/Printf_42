/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 02:41:59 by manmaria          #+#    #+#             */
/*   Updated: 2025/05/13 02:42:01 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	lengths(unsigned int n, int base_len)
{
	size_t		len;

	len = 0;
	if (n == 0)
		len++;
	while (n > 0)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

static char	*putnbr_str(unsigned int n, char *str, char *base, int base_len)
{
	size_t	len;

	len = lengths(n, base_len);
	str[len] = '\0';
	while (n >= (unsigned int)base_len)
	{
		str[len-- - 1] = base[n % base_len];
		n /= base_len;
	}
	str[len - 1] = base[n];
	return (str);
}

char	*ft_itoa_base(unsigned int n, char *base)
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
