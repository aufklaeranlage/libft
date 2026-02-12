/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ltostr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 10:38:46 by abronner          #+#    #+#             */
/*   Updated: 2025/09/25 10:51:33 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_std.h"
#include "ft_ctype.h"

#include <stdint.h>
#include <stdlib.h>

static uint64_t	get_length(long num, int base);

static void		write_digits(char *str, uint64_t len, long num, int base);

//	Converts the long 'num' int a string with base 'base' that must be between
//	2 and 36.
//	Returns a string that was malloced and must be freed by the caller. Or NULL
//	on error.
//	If the allocation fails or the base is lower than 2 or higher than 36,
//	returns NULL.

char	*ft_ltostr(long num, int base)
{
	char		*ret;
	uint64_t	len;
	int			sign;

	if (base < 2 || base > 36)
		return (NULL);
	sign = num < 0;
	len = get_length(num, base) + sign;
	ret = malloc((len + 1) * sizeof(*ret));
	if (!ret)
		return (NULL);
	ret[len--] = '\0';
	write_digits(ret, len, num, base);
	if (ret && sign)
		ret[0] = '-';
	return (ret);
}

static uint64_t	get_length(long num, int base)
{
	uint64_t	len;

	len = 1;
	num = num / base;
	while (num)
	{
		len++;
		num = num / base;
	}
	return (len);
}

static void	write_digits(char *str, uint64_t len, long num, int base)
{
	const char	sbase[37] = BASE36;
	int			digit;

	digit = num % base;
	num = num / base;
	if (num < 0)
	{
		digit *= -1;
		num *= -1;
	}
	str[len--] = sbase[digit];
	while (num)
	{
		digit = num % base;
		num = num / base;
		str[len--] = sbase[digit];
	}
}
