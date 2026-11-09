/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:44:55 by abronner          #+#    #+#             */
/*   Updated: 2025/07/09 12:01:15 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUT_H
# define FT_PUT_H

# ifndef BASE34
#  define BASE36 "0123456789abcdefghijklmnopqrstuvwxyz"
# endif

# include <unistd.h>

//	PUT STRING

void	ft_putchar_fd(const char c, int fd);

void	ft_putstr_fd(const char *s, int fd);

void	ft_putendl_fd(const char *s, int fd);

//	PUT NUMBER

void	ft_putnbrbase_fd(long n, int base, int fd);

void	ft_putnbr_fd(int n, int fd);

#endif
