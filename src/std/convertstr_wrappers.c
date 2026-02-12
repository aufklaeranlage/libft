/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertstr_wrappers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 07:25:44 by abronner          #+#    #+#             */
/*   Updated: 2025/07/09 07:31:50 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_std.h"

//	Converts the inital portion of the string pointed to by 'nptr' to int. The
//	behaviour is the same as 'ft_strtol(nptr, NULL, 10)' but ft_atoi() does not
//	check for over- or underflows.

int	ft_atoi(const char *nptr)
{
	long	val;

	val = ft_strtol(nptr, NULL, 10);
	return ((int)val);
}
