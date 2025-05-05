/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:22:25 by mipinhei          #+#    #+#             */
/*   Updated: 2025/04/30 17:18:19 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_flags
{
	size_t	width;
	size_t	precision;
	int		in_precision;
	int		in_value;
	int		minus;
	int		zeros;
	int		hash;
	int		space;
	int		plus;
}			t_flags;

int		ft_printf(const char *str, ...);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_putchar(int c);
int		ft_putstr(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_see_format(const char *s, va_list var_args);
char	*ft_strdup(const char *src);
char	ft_strchr(const char *s);
int		check_spec(char const c, char *spec_lst);
t_flags	*ft_flag_check(const char *s, int *count);
char	*ft_flags(const char *s, char *ret, int *p_fs, char spec);
char	*ft_itoa(int n);
char	*ft_itoa_base(unsigned long n, char *base);
char	*ft_setchar_ra(char *ret, size_t len, char set);
char	*ft_setspace_la(char *ret, size_t width);
char	*ft_sethash(char *ret, size_t *len, t_flags *fi, char spec);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif
