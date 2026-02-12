/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 05:31:08 by abronner          #+#    #+#             */
/*   Updated: 2025/07/08 18:59:29 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_std.h"

//	Returns a pointer to a new string, which is a duplicate of string 's'.
//	Memory for the new string is obtained with malloc and can be freed with
//	free.
//	Returns NULL if insufficient memory was available.

char	*ft_strdup(const char *s)
{
	char	*ret;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s) + 1;
	ret = malloc(slen * sizeof(*ret));
	if (!ret)
		return (NULL);
	return (ft_memcpy(ret, s, slen));
}

//	Returns a pointer to a new string, which is a duplicate of string 's', but
//	copies at most 'n' bytes. If 's' is longer than 'n' only 'n' bytes are
//	copied, and a terminating NUL byte is added.
//	Memory for the new string is obtained with malloc
//	and can be freed with free.
//	Returns NULL if insufficient memory was available.

char	*ft_strndup(const char *s, size_t n)
{
	char	*ret;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = 0;
	while (s[slen] && slen < n)
		++slen;
	ret = malloc(++slen * sizeof(*ret));
	if (!ret)
		return (NULL);
	ret[--slen] = '\0';
	return (ft_memcpy(ret, s, slen));
}

//	Returns a substring from the string 's' that starts at index 'start' and
//	has a maximum length of 'len'.
//	Returns NULL on failure.

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	slen;

	if (!s)
		return (NULL);
	slen = 0;
	while (slen < start + len && s[slen])
		++slen;
	if (slen < start)
		return (ft_strdup(""));
	return (ft_strndup(s + start, len));
}

//	Allocated memory using malloc(3) and returns a new string, which is the
//	result of concatenating 'pre' and 'suf'.
//	Returns the new string on success and NULL on failure to allocate.

char	*ft_strjoin(const char *pre, const char *suf)
{
	char	*ret;
	size_t	plen;
	size_t	slen;

	plen = 0;
	if (pre)
		while (pre[plen])
			++plen;
	slen = 0;
	if (suf)
		while (suf[slen])
			++slen;
	ret = malloc((plen + slen + 1) * sizeof(*ret));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret + plen, suf, slen + 1);
	ft_strncpy(ret, pre, plen);
	return (ret);
}

//	Allocates memory using malloc(3) and returns a copy of 'str' with characters
//	from 'set' removed from the beginning and the end.
//	Returns the trimmed string on success and NULL on failure to allocte.

char	*ft_strtrim(const char *str, const char *set)
{
	size_t	start;
	size_t	end;

	if (!str)
		return (NULL);
	if (!set)
		return (ft_strdup(str));
	start = 0;
	while (str[start] && ft_strchr(set, str[start]))
		++start;
	end = ft_strlen(str + start);
	while (end && ft_strchr(set, str[start + end - 1]))
		--end;
	return (ft_strndup(str + start, end));
}
