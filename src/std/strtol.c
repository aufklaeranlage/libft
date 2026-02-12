/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 05:57:43 by abronner          #+#    #+#             */
/*   Updated: 2025/07/09 12:05:22 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_std.h"
#include "ft_ctype.h"

#include <limits.h>

static long	base_zero(const char *s, char **endptr, const char *sbase);

static long	calculate_value(const char *s, char **endptr, const char *sbase, \
							int base);

//	Converts the inital portion of string 's' into a long integer value
//	according to the given base, which must be between 2 and 36 inclusive, or
//	be the special value 0.
//	The string may begin with an arbitrary amount of whitespace (as determined
//	by ft_isspace()) followed by a single optional '+' or '-' sign. If base is
//	0 or 16, the string may include a '0x' or '0X' prefix, and the nmber will be
//	read in base 16; otherwise, a zero base is taken as 10 unless the next
//	character is 0, in which case i  is taken as 8 (octal).
//	The remainder of the string is converted to a long value, stopping at the
//	first character that is not a valid digit in the given base. (The bases use
//	the digits 0 - 9 as their first 10 digits and then the alphabet until their
//	size is reached).
//	If 'endptr' is not NULL, the address of the first invalid digit is stored in
//	endptr. If there were no valid digit it stores the original value and
//	returns 0.
//	Returns the result of the conversion, unless the value would under- or over-
//	flow. If and underflow occurs, returns LONG_MIN; if an overflow occurs
//	returns LONG_MAX.

long	ft_strtol(const char *s, char **endptr, int base)
{
	const char	sbase[37] = BASE36;
	size_t		i;
	long		sign;

	if (!s || base < 0 || base == 1 || base > 36)
		return (0);
	i = 0;
	while (ft_isspace(s[i]))
		++i;
	sign = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		++i;
	}
	if (endptr)
		*endptr = (char *)s + i;
	if (base == 0)
		return (base_zero(s + i, endptr, sbase));
	return (sign * calculate_value(s + i, endptr, sbase, base));
}

static long	base_zero(const char *s, char **endptr, const char *sbase)
{
	size_t	i;

	i = 0;
	if (s[i] != '0')
		return (calculate_value(s + i, endptr, sbase, 10));
	++i;
	if (endptr)
		++(*endptr);
	if (s[i] != 'x' && s[i] != 'X')
		return (calculate_value(s + i, endptr, sbase, 8));
	++i;
	if (endptr)
		++(*endptr);
	return (calculate_value(s + i, endptr, sbase, 16));
}

//	dig small zero check needs to be before overflow check because LONG_MAX will
//	overflow if dig is -1.

static long	calculate_value(const char *s, char **endptr, const char *sbase,
							int base)
{
	size_t	i;
	long	val;
	long	dig;

	i = 0;
	val = 0;
	dig = 0;
	while (dig >= 0)
	{
		dig = (long)ft_basechr(sbase, base, s[i]);
		if (dig < 0)
			break ;
		if ((LONG_MAX - dig) / base < val)
			return (LONG_MAX);
		val *= base;
		val += dig;
		++i;
	}
	if (endptr)
		*endptr += i;
	return (val);
}
