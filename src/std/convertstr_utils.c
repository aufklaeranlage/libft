/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertstr_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 23:05:52 by abronner          #+#    #+#             */
/*   Updated: 2025/07/09 12:05:39 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_std.h"
#include "ft_ctype.h"

//	Returns the position of 'c' in 'sbase' if c is present in the first 'base'
//	characters of 'sbase'. If 'c' is not present returns '-1'..

int	ft_basechr(const char *sbase, int base, char c)
{
	int	i;

	i = 0;
	while (sbase[i] && i < base)
	{
		if (ft_tolower(sbase[i]) == ft_tolower(c))
			return (i);
		++i;
	}
	return (-1);
}
