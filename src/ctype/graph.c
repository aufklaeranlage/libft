/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:04:02 by abronner          #+#    #+#             */
/*   Updated: 2025/06/29 22:47:01 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

//	Checks whether the passed character 'int c' is a punctuation character.

int	ft_ispunct(int c)
{
	return (c >= '!' && c <= '~' && !ft_isalnum(c));
}

//	Checks whether the passed character 'int c' is a graphical character.

int	ft_isgraph(int c)
{
	return (c >= '!' && c <= '~');
}
