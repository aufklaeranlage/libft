/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 19:57:24 by abronner          #+#    #+#             */
/*   Updated: 2025/09/17 10:31:22 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_list.h"

int	push(t_stack *stack, t_node *new)
{
	if (!stack)
		return (1);
	if (!new)
		return (2);
	if (stack->front)
		new->next = stack->front;
	stack->front = new;
	++stack->size;
	return (0);
}

void	*pop(t_stack *stack)
{
	void	*ret;
	t_node	*del;

	if (stack->size == 0)
		return (NULL);
	del = stack->front;
	ret = del->content;
	stack->front = del->next;
	free(del);
	--stack->size;
	return (ret);
}

void	*peak(t_stack *stack)
{
	if (stack->size == 0)
		return (NULL);
	return (stack->front);
}

void	stack_clear(t_stack *s, void (*del)(void *))
{
	t_node	*node;
	t_node	*next;

	if (!s)
		return ;
	node = s->front;
	while (node)
	{
		next = node->next;
		if (del)
			(*del)(node->content);
		free(node);
		node = next;
	}
	s->front = NULL;
	s->size = 0;
	return ;
}
