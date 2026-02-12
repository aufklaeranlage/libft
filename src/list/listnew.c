/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listnew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:15:48 by abronner          #+#    #+#             */
/*   Updated: 2025/09/17 10:37:11 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

#include <stdlib.h>

//	Allocates memory using malloc(3) and returns a new node. The ’content’
//	member variable is initialized with the given parameter ’content’. The
//	variable ’next’ is initialized to NULL.
//	Returns the new node on success and NULL if the allocation fails.

t_node	*ft_nodenew(void *content)
{
	t_node	*ret;

	ret = malloc(sizeof(*ret));
	if (!ret)
		return (NULL);
	ret->content = content;
	ret->next = NULL;
	return (ret);
}

//	Adds the node ’new’ at the beginning of the list pointed to by 'lst'.

int	ft_lstadd_front(t_list *lst, t_node *new)
{
	if (!lst)
		return (1);
	if (!new)
		return (2);
	if (!lst->back)
		lst->back = new;
	new->next = lst->front;
	lst->front = new;
	++lst->size;
	return (0);
}

//	Adds the node 'new' to the end of the list pointed to by 'lst'.

int	ft_lstadd_back(t_list *lst, t_node *new)
{
	if (!lst)
		return (1);
	if (!new)
		return (2);
	if (!lst->back)
		lst->front = new;
	else
		lst->back->next = new;
	lst->back = new;
	++lst->size;
	return (0);
}
