/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:50:48 by manmaria          #+#    #+#             */
/*   Updated: 2025/04/22 18:21:12 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>

typedef struct s_type
{
	int	width;
	int	minus;
	int	zeros;
	int	precision;
	int	hash;
	int	space;
	int	plus;
}			t_type;

size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
char	**ft_nsplit(const char *s, char *sep);
int		ft_printf(const char *s, ...);

#endif
