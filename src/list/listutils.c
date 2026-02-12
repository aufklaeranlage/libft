/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:24:51 by abronner          #+#    #+#             */
/*   Updated: 2025/07/09 12:29:49 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

#include <stdlib.h>

//	Counts the number of nodes in the list 'lst'.

int	ft_lstsize(t_list *lst)
{
	return (lst->size);
}

//	Returns the last node of the list 'lst'.

t_node	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	return (lst->back);
}
