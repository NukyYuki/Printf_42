/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:39:48 by mipinhei          #+#    #+#             */
/*   Updated: 2025/04/29 20:04:19 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	lengths(unsigned long n, int base_len)
{
	size_t		len;
	unsigned long nu;

	len = 0;
	nu = n; //TESTING solution for conditional jump
	if (n == 0)
		len++;
	/*if (n < 0)
	{
		n = -n;
		len++;
	}*/
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
	/*if (n < 0)
	{
		n = -n;
		str[i] = '-';
		i++;
	}*/
	while (n >= (unsigned long)base_len)
	{
		str[len] = base[n % base_len];
		n /= base_len;
		len--;
	}
	str[i] = base[n];
	return (str);
}

char	*ft_itoa_base(unsigned long n, char *base)
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
/*#include <stdio.h>
int	main(void)
{
		char	*s;

		s = ft_itoa_base(-42, "0123456789abcdef");
		printf("%s", s);
		free(s);
		return 0;
}*/
