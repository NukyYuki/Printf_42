/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 21:43:38 by manmaria          #+#    #+#             */
/*   Updated: 2025/05/13 02:28:18 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	if (!str1)
		return (-1);
	while (str1[i] == str2[i] && str1[i] && str2[i])
	{
		i++;
	}
	return (str1[i] - str2[i]);
}

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		i;

	dup = 0;
	i = 0;
	if (!src)
		return (ft_return_null());
	while (src[i])
		i++;
	dup = (char *)malloc(sizeof(char) *(i + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	ft_checkspec(char const c, char *spec_lst)
{
	while (*spec_lst)
	{
		if (c == *spec_lst)
			return (1);
		spec_lst++;
	}
	return (0);
}

char	ft_strchr(const char *s)
{
	int	i;

	i = 0;
	while (ft_checkspec(s[i], "cspdiuxX%") == 0)
	{
		if (s[i] == '\0')
			break ;
		i++;
	}
	if (ft_checkspec(s[i], "cspdiuxX%") == 1)
	{
		return ((char)s[i]);
	}
	return (0);
}
