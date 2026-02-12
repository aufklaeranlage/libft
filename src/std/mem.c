/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 22:36:43 by abronner          #+#    #+#             */
/*   Updated: 2025/07/12 10:32:06 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_std.h"

//	Fills the first 'n' bytes of section 's' with the constant byte 'c'.
//	Returns a pointer to the memory section 's'.

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = c;
		++i;
	}
	return (s);
}

//	Copies 'n' bytes from the memory area 'src' to the memory area 'dst'. The
//	memory areas must not overlap.
//	Returns a pointer to 'dst'.

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	while (n--)
		((char *)dst)[n] = ((char *)src)[n];
	return (dst);
}

//	Copies 'n' bytes from the memory area 'src' to the memory area 'dst'. The
//	memory areas may overlap. Depending on relative positioning copies from
//	front to back or back to front to ensure integrity and make 'n' bytes of
//	'dst' the same as 'src' was.
//	Returns a pointer to 'dst'.

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst > src)
		return (ft_memcpy(dst, src, n));
	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		++i;
	}
	return (dst);
}

//	Scans the inital 'n' bytes of memory area 's' for the first appearence of
//	byte 'c'. Both 'c' and the bytes of 's' are interpreted as unsigned char.
//	Returns a pointer to the first appearence of 'c' in 's'. If 'c' is not found
//	in the first 'n' bytes of 's', returns NULL.

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	uc;

	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == uc)
			return ((void *)(s + i));
		++i;
	}
	return (NULL);
}

//	Compares the first 'n' bytes of 's1' and 's2' (each interpreted as unsigned
//	char).
//	Returns the difference etween the first mismatch in byte value between 's1'
//	and 's2' in the first 'n' bytes. A positive return value means that 's1' had
//	the bigger value, a negative return value means that 's2' had the bigger
//	value. If the first 'n' bytes in 's1' and 's2' were identical returns 0.

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		ret;

	i = 0;
	while (i < n)
	{
		ret = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
		if (ret)
			return (ret);
		++i;
	}
	return (0);
}
