/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:13:17 by abronner          #+#    #+#             */
/*   Updated: 2025/06/29 22:47:06 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

//	Checks whether the passed character 'int c' is a space.

int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

//	Checks whether the passed character 'int c' is printable.

int	ft_isprint(int c)
{
	return (ft_isspace(c) || ft_isgraph(c));
}
