/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_std.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 05:54:48 by abronner          #+#    #+#             */
/*   Updated: 2025/09/25 10:51:50 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STD_H
# define FT_STD_H

# ifndef BASE34
#  define BASE36 "0123456789abcdefghijklmnopqrstuvwxyz"
# endif

# include <stddef.h>

//	MEM

void	*ft_memset(void *s, int c, size_t n);

void	*ft_memcpy(void *dst, const void *src, size_t n);

void	*ft_memmove(void *dst, const void *src, size_t n);

void	*ft_memchr(const void *s, int c, size_t n);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

//	MEM CREATE

void	*ft_calloc(size_t nelem, size_t elsize);

//	CONVERTER

long	ft_strtol(const char *s, char **endptr, int base);

char	*ft_ltostr(long num, int base);

//	CONVERTER UTILITIES

int		ft_basechr(const char *sbase, int base, char c);

//	CONVERTER WRAPPERS

int		ft_atoi(const char *nptr);

#endif
