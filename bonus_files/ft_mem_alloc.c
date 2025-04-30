/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:02:39 by mipinhei          #+#    #+#             */
/*   Updated: 2025/04/30 17:01:15 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p_s;
	size_t			i;

	i = 0;
	p_s = s;
	while (i < n)
		p_s[i++] = '\0';
}

char	*ft_setzero(char *ret, size_t width)
{
	char	*p_s;
	size_t			i;

	p_s = malloc((width + 1) * sizeof(char));
	if (!p_s)
		return (NULL);
	i = 0;
	while (i < (width - ft_strlen(ret)))
		p_s[i] = '0';
	while ( i < width)
		p_s[i] = ret[i - width];
	s[i] = '\0';
	return (p_s);
}

char	*ft_setspace(char *ret, size_t width)
{
	char	*p_s;
	size_t			i;

	p_s = malloc((width + 1) * sizeof(char));
	if (!p_s)
		return (NULL);
	i = 0;
	while (i < (width - ft_strlen(ret)))
		p_s[i] = ' ';
	while ( i < width)
		p_s[i] = ret[i - width];
	s[i] = '\0';
	return (p_s);
}
