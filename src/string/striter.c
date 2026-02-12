/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   striter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:14:30 by abronner          #+#    #+#             */
/*   Updated: 2025/07/09 11:19:38 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

//	Applies the function 'f' to each character of the string 's', passing its
//	index as the first argument and the character itself as the second. A new
//	string is created using malloc(3) to store the results from the successive
//	applications of 'f'.
//	Returns the created string on success and NULL if the allocation fails.

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s) + 1;
	ret = malloc(len-- * sizeof(*ret));
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	while (len--)
		ret[len] = (*f)(len, s[len]);
	return (ret);
}

//	Applies the function 'f' to each character of the string 's', passing its
//	index as the first argument. Each character is passed by assress to 'f' so
//	it can be modified if necessary.

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, s + i);
		++i;
	}
}
