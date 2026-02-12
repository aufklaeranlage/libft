/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 22:04:44 by abronner          #+#    #+#             */
/*   Updated: 2025/06/29 22:47:33 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

//	Returns a pointer to the first occurrence of the character 'c' in the string
//	's'. If 'c' is not found NULL is returned. The terminating NUL of a string
//	is considered part of the string, so it can be searched for.

char	*ft_strchr(const char *s, int c)
{
	c = c & 0xFF;
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		++s;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

//	Returns a pointer to the last occurrence of the character 'c' in the string
//	's'. If 'c' is not found NULL is returned. The terminating NUL of a string
//	is considered part of the string so it can be searched for.

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;

	c = c & 0xFF;
	ret = NULL;
	while (*s)
	{
		if (*s == c)
			ret = (char *)s;
		++s;
	}
	if (*s == c)
		ret = (char *)s;
	return (ret);
}

//	Returns a pointer to the first occurrence of the character 'c' in the string
//	's'. If 'c' is not found the terminating NUL of string 's' is returned.
//	The terminating NUL of a string is considered part of the string so it can
//	be searched for.

char	*ft_strchrnul(const char *s, int c)
{
	c = c & 0xFF;
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		++s;
	}
	return ((char *)s);
}

//	Returns a pointer to the last occurrence of the character 'c' in the string
//	's'. If 'c' is not found the terminating NUL of string 's' is returned.
//	The terminating NUL of a string is considered part of the string so it can
//	be searched for.

char	*ft_strrchrnul(const char *s, int c)
{
	char	*ret;

	c = c & 0xFF;
	ret = (char *)s;
	while (*s)
	{
		if (*s == c)
			ret = (char *)s;
		++s;
	}
	if (*s == c || !ret)
		ret = (char *)s;
	return (ret);
}

//	Searches for the first occurrence of string 's' in string 'b' where a
//	maximum of 'len' characters are searched. If 's' is an empty string
//	returns 'b', if 's' is not present in 'b' returns NULL, if 's' is found in
//	'b' returns a pointer to it's first occurence.

char	*ft_strnstr(const char *b, const char *s, size_t len)
{
	size_t	i;
	size_t	slen;

	slen = ft_strlen(s);
	if (!slen)
		return ((char *)b);
	i = 0;
	while (i + slen <= len && b[i])
	{
		if (!ft_strncmp(b + i, s, slen))
			return ((char *)(b + i));
		++i;
	}
	return (NULL);
}
