/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:16:02 by abronner          #+#    #+#             */
/*   Updated: 2025/06/29 17:52:19 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Checks whether the passed character 'int c' is a control character.

int	ft_iscntrl(int c)
{
	return ((c >= 0 && c <= 31) || c == 127);
}

//	Checks whether the passed character 'int c' is a blank character.

int	ft_isblank(int c)
{
	return (c == ' ' || c == '\t' || c == '\v');
}

//	Checks whether the passed character 'int c' is part of regular ASCII.

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
