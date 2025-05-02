/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:15:28 by manmaria          #+#    #+#             */
/*   Updated: 2025/05/02 11:16:45 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
*  WARNING: 
*  THESE FUNCTIONS HERE ARE OUTDATED!
*  NEW VERSIONS ARE IN bonus_files/ft_flags.c
*  WILL UPDATE THE ONES HERE WHEN THEIR NEWER COUNTERPARTS
*  ARE FULLY TESTED.
*  NEED TO UPDATE THE DECLARATIONS IN libftprintf.h 
*/

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
	while (check_spec(s[i], spec_lst) == 0)
	{
		if (s[i] == '\0')
			break ;
		i++;
	}
	if (check_spec(s[i], spec_lst) == 1)
		return (i);
	i = 0;
	p_spec = (char *)s + i;
	return (0);
}

t_flags	*flag_check(const char *s, int count)
{
	t_flags	*fbool;
	int		i;

	i = 0;
	fbool = ft_calloc(1, sizeof(t_flags)); //calloc to set all vars to 0
	while (i < count)
	{
		if (s[i] == '#')
			fbool->hash = 1;
		else if (s[i] == '.')
			fbool->in_precision = 1;
		else if (s[i] >= '1' && s[i] <= '9')
		{
			if (fbool->in_precision == 1)
				fbool->precision = fbool->precision * 10 + (s[i] - 48);
			else
				fbool->width = fbool->width * 10 + (s[i] - 48);
			fbool->in_value = 1;
		}
		else if (s[i] == ' ')
			fbool->space = 1;
		else if (s[i] == '-')
			fbool->minus = 1;
		else if (s[i] == '0')
		{
			if (!fbool->in_precision && !fbool->in_value && fbool->zeros == 0)
				fbool->zeros = 1;
			else if (fbool->in_precision)
				fbool->precision = fbool->precision * 10 + (s[i] - 48);
			else
				fbool->width = fbool->width * 10 + (s[i] - 48);
			fbool->in_value = 1;
		}
		else if (s[i] == '+')
			fbool->plus = 1;
		i++;
	}
	if (fbool->minus == 1 || fbool->in_precision == 1)
		fbool->zeros = 0;
	if (fbool->plus == 1)
		fbool->space = 0;
	return (fbool);
}

int	ft_flags(const char *s, va_list	varg)
{
	// %[flags][width][.precision]specifier
	t_flags	*fbool;
	char	*spec_lst;
	char	*sub; //str will get malloc's to add converted result to
	char	spec; //the specifier we are dealing with
	int		count;// the number of flags we need to convert until spec
	int		i;
	va_list	vcopy;
	
	spec_lst = "cspdiuxX%";
	va_copy(varg, vcopy);
	count = ft_strchr(s, spec_lst, &spec);
	fbool = flag_check(s, count);
	i = 0;

	va_end(vcopy);
	return (count);
}
