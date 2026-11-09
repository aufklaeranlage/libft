/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 09:36:34 by abronner          #+#    #+#             */
/*   Updated: 2025/09/17 14:35:00 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GNL_H
# define FT_GNL_H

# include "ft_list.h"

# include <stddef.h>

# ifndef MAXFDS
#  define MAXFDS 64
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

typedef struct s_str
{
	char	*data;
	size_t	size;
}	t_str;

char	*get_next_line(int fd);

//	UTILS

void	strclear(void *ptr);

char	*create_line(t_list *lst);

#endif
