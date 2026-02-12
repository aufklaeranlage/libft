/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:11:53 by abronner          #+#    #+#             */
/*   Updated: 2025/07/12 10:24:42 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

//	Copies up to 'size' bytes from 'src' to 'dst'. If 'src' is less than 'size'
//	bytes long it will fill up the difference in 'dst' with '\0' characters
//	to ensure it writes 'size' characters.
//	Does not NUL terminate.
//	Returns the total length of 'src'.

size_t	ft_strncpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size && src[i])
	{
		dst[i] = src[i];
		++i;
	}
	if (i < size)
		dst[i] = '\0';
	while (src[i])
		++i;
	return (i);
}

//	Copies up to 'size' - 1 bytes from 'src' to 'dst'. If 'src' is less than
//	'size' - 1 bytes long it will fill up the difference in 'dst' with '\0'
//	characters to ensure it writes 'size' - 1 characters and NUL terminates the
//	string in 'dst.
//	Returns the total length of 'src'.

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	if (!size)
		return (ft_strlen(src));
	dst[size - 1] = '\0';
	return (ft_strncpy(dst, src, size - 1));
}

//	Appends the string 'src' to the end of string 'dst' till 'dst' is 'size'
//	characters long and NUL terminates the result. If the total length of 'dst'
//	and 'src' combined is less than 'size' it fills 'dst' with '\0' till a
//	length of 'size' is reached.
//	Returns the total length of the new string that was created (excluding the
//	NUL terminator)

size_t	ft_strncat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < size && dst[j])
		++j;
	if (dst[j])
		return (size + ft_strlen(src));
	i = 0;
	while (j + i < size && src[i])
	{
		dst[j + i] = src[i];
		++i;
	}
	if (j + i < size)
		dst[j + i] = '\0';
	while (src[i])
		++i;
	return (j + i);
}

//	Appends the string 'src' to the end of string 'dst' till 'dst' is 'size' - 1
//	characters long and NUL terminates the result. If the total length of 'dst'
//	and 'src' combined is less than 'size' - 1 it fills 'dst' with '\0' till a
//	length of 'size' - 1 is reached.
//	Returns the total length of the new string that was created (excluding the
//	NUL terminator)

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (!size)
		return (ft_strlen(src));
	j = 0;
	while (j < size && dst[j])
		++j;
	if (dst[j])
		return (size + ft_strlen(src));
	i = 0;
	while (j + i + 1 < size && src[i])
	{
		dst[j + i] = src[i];
		++i;
	}
	dst[j + i] = '\0';
	while (src[i])
		++i;
	return (j + i);
}

//	Ereases the data in the 'n' bytes of the memory starting at the location
//	pointed to by 's', by writing zeros (Bytes containiong '0') to that area.

void	ft_bzero(void *s, size_t n)
{
	while (n--)
		((char *)s)[n] = '\0';
}
