/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:22:25 by mipinhei          #+#    #+#             */
/*   Updated: 2025/04/24 20:48:20 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_flags
{
	int	width;
	int	precision;
	int	in_precision;
	int	in_value;
	int	minus;
	int	zeros;
	int	hash;
	int	space;
	int	plus;
}			t_flags;

void	ft_bzero(void *s, size_t n);
int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr_base_hexa(long nb, char *base);
int		ft_putnbr_decimal(long nb);
int		ft_print_mem(void *p);
size_t	ft_strlen(const char *s);
int		ft_see_format(const char *s, va_list var_args);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strrchr(const char *s, int c);

#endif
