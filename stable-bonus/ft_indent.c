/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 01:47:58 by manmaria          #+#    #+#             */
/*   Updated: 2025/05/13 02:29:53 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_setchar_ra(char *ret, size_t len, char set)
{
	char	*p_s;
	size_t	i;
	size_t	k;

	p_s = calloc((len + 1), sizeof(char));
	if (!p_s)
		return (NULL);
	i = 0;
	k = 0;
	while (i < (len - ft_strlen(ret)))
		p_s[i++] = set;
	while (i < len)
		p_s[i++] = ret[k++];
	free(ret);
	return (p_s);
}

int	hash_init(size_t *len, size_t *i, int *k, t_flags *fi)
{
	int	bow;

	*len += 2;
	bow = 0;
	if (fi->width > *len && fi->zeros == 1)
		bow = fi->width;
	*i = 2;
	*k = 0;
	return (bow);
}

	//if (ft_strcmp(ret, "0") == 0)
	//	return (ret);

char	*sethash_helper(char *ret)
{
	if (ft_strcmp(ret, "(nil)") == 0)
		return (ret);
	else
		return (ret);
}

char	*ft_sethash(char *ret, size_t *len, t_flags *fi, char spec)
{
	char	*p_s;
	size_t	i;
	int		k;
	int		bow;

	if (ft_strcmp(ret, "0") == 0 || ft_strcmp(ret, "(nil)") == 0)
		return (sethash_helper(ret));
	bow = hash_init(len, &i, &k, fi);
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
