/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listdel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:33:59 by abronner          #+#    #+#             */
/*   Updated: 2025/07/09 12:40:33 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

#include <stdlib.h>

//	Takes a node as parameter 'node' and frees its content using the function
//	'del'. Then frees the node itself but not the next node. does not connect
//	nodes.
//	If 'del' is a NULL pointer it just frees the node but not the content.

void	ft_lstdelone(t_node *node, void (*del)(void *))
{
	if (!node)
		return ;
	if (del)
		(*del)(node->content);
	free(node);
	return ;
}

//	Takes a node as parameter 'node' and looks in the list 'lst' for that node.
//	If found it removes the node, connects the list, applys the function 'del'
//	to the nodes content and frees the node.
//	If 'del' is a NULL pointer it just frees the node but not the content.

int	ft_lstrmvone(t_list *lst, t_node *node, void (*del)(void *))
{
	t_node	*cur;
	t_node	*prev;

	prev = NULL;
	cur = lst->front;
	while (cur && cur != node)
	{
		prev = cur;
		cur = cur->next;
	}
	if (!cur)
		return (1);
	if (!prev)
		lst->front = cur->next;
	else
		prev->next = cur->next;
	if (cur == lst->back)
		lst->back = prev;
	if (del)
		(*del)(cur->content);
	free(cur);
	--lst->size;
	return (0);
}

//	Deletes and frees the given node and all its successors, using the function
//	’del’ and free(3). Finally, set the pointer to the list to NULL.

void	ft_lstclear(t_list *lst, void (*del)(void *))
{
	t_node	*node;
	t_node	*next;

	if (!lst)
		return ;
	node = lst->front;
	while (node)
	{
		next = node->next;
		ft_lstdelone(node, del);
		node = next;
	}
	lst->front = NULL;
	lst->back = NULL;
	lst->size = 0;
	return ;
}
