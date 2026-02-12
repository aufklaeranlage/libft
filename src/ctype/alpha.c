/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 15:50:53 by abronner          #+#    #+#             */
/*   Updated: 2025/06/29 16:28:52 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Checks whether the passed character 'int c' is a lowercase letter.

int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

//	Checks whether the passed character 'int c' is a uppercase letter.

int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

//	Checks whether the passed character 'int c' is a letter.

int	ft_isalpha(int c)
{
	return (ft_isupper(c) || ft_islower(c));
}
