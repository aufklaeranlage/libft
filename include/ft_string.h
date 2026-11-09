/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:53:13 by abronner          #+#    #+#             */
/*   Updated: 2025/07/12 10:25:02 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stddef.h>
# include <stdlib.h>

//	CHECK

size_t	ft_strlen(const char *s);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

//	SEARCH

char	*ft_strchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c);

char	*ft_strchrnul(const char *s, int c);

char	*ft_strrchrnul(const char *s, int c);

char	*ft_strnstr(const char *b, const char *s, size_t len);

//	COPY

//	These don't protect against NULL being given as an argument since the output
//	couldn't properly protrait these cases. Always check for NULL being passed
//	to these functions beforehand. All causes segfaults if NULL is being passed.

size_t	ft_strncpy(char *dst, const char *src, size_t size);

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

size_t	ft_strncat(char *dst, const char *src, size_t size);

size_t	ft_strlcat(char *dst, const char *src, size_t size);

void	ft_bzero(void *s, size_t n);
//	CREATE

char	*ft_strdup(const char *s);

char	*ft_strndup(const char *s, size_t n);

char	*ft_substr(const char *s, unsigned int start, size_t len);

char	*ft_strjoin(const char *pre, const char *suf);

char	*ft_strtrim(const char *str, const char *set);

//	STRITER

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

#endif
