/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:15:28 by manmaria          #+#    #+#             */
/*   Updated: 2025/04/24 23:04:12 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	check_spec(char const c, char *spec_lst)
{
	int	i;

	i = 0;
	while (*spec_lst)
	{
		if (c == *spec_lst)
			return (1);
		spec_lst++;
	}
	return (0);
}

int	ft_strchr(const char *s, char *spec_lst, char *p_spec)
{
	int	i;

	i = 0;
	while (check_spec(s[i], spec_lst))
	{
		if (s[i] == '\0')
			break ;
		i++;
	}
	if (!check_spec(s[i], spec_lst))
		return (i);
	i = 0;
	p_spec = (char *)s + i;
	return (0);
}

int	ft_flags(const char *s)
{
	char	*spec_lst;
	char	*sub; //str will get malloc's to add converted result to
	char	spec; //the specifier we are dealing with
	int		count;// the number of flags we need to convert until spec
	int		i;
	t_flags	fbool;
	
	spec_lst = "csiuxXp%";
	count = ft_strchr(s, spec_lst, &spec);
	i = 0;
	// space flag only works for i and d specs
	// so we set space to one so it doesnt work for any other specs
	if (spec != 'i' && spec != 'd')
		fbool.space = 1;  
	while (i < count)
	{
		if (s[i] == ' ' && fbool.space == 0)
			ft_putchar(' '), i++;
		// missing if for width flag(which is just numbers)
		// we need to call atoi to check width number then add it to malloc
		// or write the atoi_res -= legth of str or number we want to write
		// if atoi_res <= len of str or number, no space is written
		if (s[i] == '-');
		if (s[i] == '0');
		if (s[i] == '.');
		if (s[i] == '#');
		if (s[i] == '+');
		// this is very WIP btw, this shit gonna be like 3 files full of functions
		// **copium**
	}
	return (count);
}
