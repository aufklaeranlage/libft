/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alnum.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:01:49 by abronner          #+#    #+#             */
/*   Updated: 2025/06/29 22:46:45 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

//	Checks whether the passed character 'int c' is alphanumeric.

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

//	Checks whether the passed character 'int c' is lowercase alphanumeric.

int	ft_islowalnum(int c)
{
	return (ft_islower(c) || ft_isdigit(c));
}

//	Checks whether the passed character 'int c' is uppercase alphanumeric.

int	ft_isupalnum(int c)
{
	return (ft_isupper(c) || ft_isdigit(c));
}
