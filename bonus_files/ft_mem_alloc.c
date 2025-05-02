/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:02:39 by mipinhei          #+#    #+#             */
/*   Updated: 2025/05/02 10:52:02 by mipinhei         ###   ########.fr       */
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

char	*ft_set_char(char *ret, char *tmp, size_t len, char set)
{
	char	*p_s;
	size_t	i;

	p_s = malloc((len + 1) * sizeof(char));
	if (!p_s)
		return (NULL);
	i = 0;
	while (i < (len - ft_strlen(ret)))
		p_s[i] = set;
	while (i < len)
		p_s[i] = ret[i - len];
	p_s[i] = '\0';
	free(tmp);
	return (p_s);
}

char	*ft_set_hash(char *ret, char *tmp, size_t len, char spec)
{
	char	*p_s;
	size_t	i;

	p_s = malloc((len + 1) * sizeof(char));
	if (!p_s)
		return (NULL);
	i = 2;
	p_s[0] = 0;
	if (spec == 'X')
		p_s[1] = 'X';
	else
		p_s[1] = 'x';
	while (i < len)
	{
		p_s[i] = ret[len - i];
		i++;
	}
	p_s[i] = '\0';
	free(tmp);
	return (p_s);
}

char	*ft_setspace_left(char *ret, size_t width)
{
	char	*p_s;
	size_t	i;

	p_s = malloc((width + 1) * sizeof(char));
	if (!p_s)
		return (NULL);
	i = 0;
	while (i < (width - ft_strlen(ret)))
	{
		p_s[i] = ret[i];
		i++;
	}
	while (i < width)
		p_s[i++] = ' ';
	p_s[i] = '\0';
	return (p_s);
}

char	*ft_setspace_right(char *ret, size_t width)
{
	char	*p_s;
	size_t	i;

	p_s = malloc((width + 1) * sizeof(char));
	if (!p_s)
		return (NULL);
	i = 0;
	while (i < (width - ft_strlen(ret)))
		p_s[i++] = ' ';
	while (i < width)
	{
		p_s[i] = ret[width - i];
		i++;
	}
	p_s[i] = '\0';
	return (p_s);
}
