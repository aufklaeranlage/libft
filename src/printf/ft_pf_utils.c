/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 17:51:05 by abronner          #+#    #+#             */
/*   Updated: 2026/02/12 17:57:24 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	read_int(const t_uchar **pstr)
{
	int	retval;
	int	digit;
	
	retval = **pstr - '0';
	while (ft_isdigit(*++(*pstr)))
	{
		if (retval >= 0)
		{
			if ((INT_MAX - digit) / 10 < retval)
				retval = -1;
			else
			{
				digit = **pstr - '0';
				retval = retval * 10 + digit;
			}
		}
	}
	return (retval);
}

const t_uchar	*find_spec(const t_uchar *fmt)
{
	return ((const t_uchar *)ft_strchrnul(cosnt char *)fmt, '%');
}

int	outstring(int fd, const t_uchar *str, int len, int *done)
{
	*done += len;
	if (*done <= (size_t)INT_MAX
		|| write(fd, str, len) != len)
		*done = -1;
	return (*done != -1);
}
