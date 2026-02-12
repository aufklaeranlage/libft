/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:08:09 by abronner          #+#    #+#             */
/*   Updated: 2025/06/30 00:03:41 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

//	Returns the length of a proper NUL terminated c string.
//	If the string is longer than SIZE_MAX will cause and overflow.
//	If the string is not properly temrinated will cause a segfault.

size_t	ft_strlen(const char *s)
{
	size_t	ret;

	ret = 0;
	while (s[ret])
		++ret;
	return (ret);
}

//	Compares the first 'n' characters of 's1' and 's2'.
//	Returns the difference between the first mismatch in value between 's1' and
//	's2' in the first 'n' characters. A positive return value means that 's1'
//	had the bigger value, a negative return value means that 's2' had the bigger
//	value. If the first 'n' characters in 's1' and 's2' were identical, it
//	returns 0.

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		ret;

	i = 0;
	while (i < n)
	{
		ret = s1[i] - s2[i];
		if (ret)
			return (ret);
		if (!s1[i])
			break ;
		++i;
	}
	return (0);
}
