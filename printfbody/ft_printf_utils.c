/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:43:24 by manmaria          #+#    #+#             */
/*   Updated: 2025/04/24 20:49:09 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(char c)
{
	int	count;

	count = 1;
	write(1, &c, 1);
	return (count);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p_s;
	size_t			i;

	i = 0;
	p_s = s;
	while (i < n)
		p_s[i++] = '\0';
}

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	while (s[count])
		count += ft_putchar(s[count]);
	return (count);
}
