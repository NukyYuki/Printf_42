/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:02:39 by mipinhei          #+#    #+#             */
/*   Updated: 2025/05/06 22:03:25 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_setchar_ra(char *ret, size_t len, char set)
{
	char	*p_s;
	size_t	i;
	size_t	k;

	p_s = malloc((len + 1) * sizeof(char));
	if (!p_s)
		return (NULL);
	i = 0;
	k = 0;
	while (i < (len - ft_strlen(ret)))
		p_s[i++] = set;
	while (i < len)
		p_s[i++] = ret[k++];
	p_s[i] = '\0';
	free(ret);
	return (p_s);
}

void	hash_init(size_t **len, size_t *i, int *k, int *bow)
{
	**len += 2;
	*bow = 0;
	*i = 2;
	*k = 0;
}

char	*ft_sethash(char *ret, size_t *len, t_flags *fi, char spec)
{
	char	*p_s;
	size_t	i;
	int		k;
	int		bow;

	hash_init(&len, &i, &k, &bow);
	if (fi->width > *len && fi->zeros == 1)
		bow = fi->width;
	p_s = calloc((*len + bow + 1), sizeof(char));
	if (!p_s)
		return (NULL);
	p_s[0] = '0';
	if (spec == 'X')
		p_s[1] = 'X';
	else
		p_s[1] = 'x';
	if (bow > 0)
	{
		ret = ft_setchar_ra(ret, bow - 2, '0');
		*len = fi->width;
	}
	while (i < *len)
		p_s[i++] = ret[k++];
	free(ret);
	return (p_s);
}

char	*ft_setspace_la(char *ret, size_t width)
{
	char	*p_s;
	size_t	i;

	p_s = malloc((width + 1) * sizeof(char));
	if (!p_s)
		return (NULL);
	i = 0;
	while (i < ft_strlen(ret))
	{
		p_s[i] = ret[i];
		i++;
	}
	while (i < width)
		p_s[i++] = ' ';
	p_s[i] = '\0';
	free(ret);
	return (p_s);
}
