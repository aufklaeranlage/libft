/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 10:28:35 by abronner          #+#    #+#             */
/*   Updated: 2025/09/17 10:42:05 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

#include <stddef.h>
#include <stdlib.h>

int	enqueue(t_queue *q, t_node *new)
{
	if (!q)
		return (1);
	if (!new)
		return (2);
	if (!q->back)
		q->front = new;
	else
		q->back->next = new;
	q->back = new;
	++q->size;
	return (0);
}

void	*dequeue(t_queue *q)
{
	void	*ret;
	t_node	*del;

	if (!q || !q->front)
		return (NULL);
	del = q->front;
	ret = del->content;
	q->front = del->next;
	if (q->front == NULL)
		q->back = NULL;
	free(del);
	--q->size;
	return (ret);
}

void	queue_clear(t_queue *q, void (*del)(void *))
{
	t_node	*node;
	t_node	*next;

	if (!q)
		return ;
	node = q->front;
	while (node)
	{
		next = node->next;
		if (del)
			(*del)(node->content);
		free(node);
		node = next;
	}
	q->front = NULL;
	q->back = NULL;
	q->size = 0;
	return ;
}
