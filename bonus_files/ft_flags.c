/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:15:28 by manmaria          #+#    #+#             */
/*   Updated: 2025/04/26 23:38:54 by manmaria         ###   ########.fr       */
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

int	ft_atoi(const char *nptr, int *p_i)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - 48);
		i++;
	}
	*p_i = i;
	return (res * sign);
}

t_flags	*flag_check(const char *s, int count)
{
	//init aqui a struct com toda a info sobre flags
	//pre parsing
	t_flags	*fbool;
	int		i;

	i = 0;
	fbool = calloc(1, sizeof(t_flags));
	while (i < count)
	{
		if (s[i] == ' ')
			fbool.
		if (s[i] == '-');
		if (s[i] == '0');
		if (s[i] == '.');
		if (s[i] == '#');
		if (s[i] == '+');
	}
	return (fbool);
}

int	ft_flags(const char *s, va_list	varg)
{
	// %[flags][width][.precision]specifier
	char	*spec_lst;
	char	*sub; //str will get malloc's to add converted result to
	char	spec; //the specifier we are dealing with
	int		count;// the number of flags we need to convert until spec
	int		i;
	int		space;
	
	// quando passar as flags, tenho que checkar se tou num numero
	// para ler e calcular a width com a atoi
	// a atoi provavelmente vai me retornar a posix da string
	spec_lst = "cspdiuxX%";
	count = ft_strchr(s, spec_lst, &spec);
	i = 0;
	while (i < count)
	{
		if (s[i] == ' ' && (spec == 'i' || spec == 'd'))
			//mete se um espaco na string pra ser impressa;
			//
		if (s[i] == '-' && fbool->minus == 0);
			//identa-se para a esquerda
			fbool->minus == 1;
		if (s[i] == '0' && fbool->minus == 0);
		if (s[i] == '.');
		if (s[i] == '#');
		if (s[i] == '+');
		i++;

		// this is very WIP btw, this shit gonna be like 3 files full of functions
		// **copium**
	}
	return (count);
}
