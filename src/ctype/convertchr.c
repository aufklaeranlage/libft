/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:23:57 by abronner          #+#    #+#             */
/*   Updated: 2025/06/29 22:46:51 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

//	Checks whether the passed character 'int c' is an uppercase character. If it
//	is it returns it's lowercase equivalent else it returns c.

int	ft_tolower(int c)
{
	if (ft_isupper(c))
		return (c + 'a' - 'A');
	return (c);
}

//	Checks whether the passed character 'int c' is an lowercase character. If it
//	is it returns it's uppercase equivalent else it returns c.

int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c - 'a' - 'A');
	return (c);
}
