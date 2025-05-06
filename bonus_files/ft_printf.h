/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:22:25 by mipinhei          #+#    #+#             */
/*   Updated: 2025/05/06 21:45:00 by manmaria         ###   ########.fr       */
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
	char	in_precision;
	char	in_value;
	char	minus;
	char	zeros;
	char	hash;
	char	space;
	char	plus;
}			t_flags;

void	ft_flag_check_helper(const char *s, t_flags **fb);

int		ft_printf(const char *str, ...);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_putchar(int c);
int		ft_putstr(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_see_format(const char *s, va_list var_args);
char	*ft_strdup(const char *src);
char	*ft_dupchar(int n);
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
int		ft_setpercent(va_list var_args, const char *str, int *p, int count);
char	*ft_width_bigger_len(t_flags *flag_info, char *ret);
char	*ft_has_precision(t_flags *flag_info, char *ret, size_t *len,
			char spec);

#endif
