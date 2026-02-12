/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 15:56:09 by abronner          #+#    #+#             */
/*   Updated: 2025/06/29 22:46:56 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

//	Checks whether the passed character 'int c' is a decimal digit.

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

//	Checks whether the passed character 'int c' is a hexadecimal digit.

int	ft_isxdigit(int c)
{
	return (ft_islowxdigit(c) || ft_isupxdigit(c));
}

//	Checks whether the passed character 'int c' is a lowercase hexadecimal
//	digit.

int	ft_islowxdigit(int c)
{
	return ((c >= 'a' && c <= 'f') || ft_isdigit(c));
}

//	Checks whether the passed character 'int c' is a uppercase hexadecimal
//	digit.

int	ft_isupxdigit(int c)
{
	return ((c >= 'a' && c <= 'f') || ft_isdigit(c));
}
