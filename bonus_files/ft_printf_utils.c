/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:10:26 by manmaria          #+#    #+#             */
/*   Updated: 2025/05/13 02:42:29 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strrchr_b(const char *s, int c)
{
	size_t	len;

	if (!s)
		return (0);
	len = ft_strlen(s);
	while (1)
	{
		if (s[len] == (char)c)
			return (1);
		if (len == 0)
			break ;
		len--;
	}
	return (0);
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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;
	size_t	mult;

	if (nmemb != 0 && size != 0 && (nmemb > ((size_t)-1 / size)))
		return (NULL);
	mult = nmemb * size;
	arr = malloc(nmemb * size);
	if (!arr)
		return (NULL);
	ft_bzero(arr, mult);
	return (arr);
}

char	*ft_dupchar(int n)
{
	char	*dup;

	if (n == 0)
	{
		dup = malloc(sizeof(char));
		dup[0] = 0;
		return (dup);
	}
	dup = malloc(sizeof(char) * 2);
	if (!dup)
		return (NULL);
	dup[0] = n;
	dup[1] = 0;
	return (dup);
}
