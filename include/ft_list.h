/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:13:20 by abronner          #+#    #+#             */
/*   Updated: 2025/09/17 10:42:15 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

//	content:	Data in the node.
//	next:		Pointer to the next node, if this is the last node is NULL.

typedef struct s_node	t_node;

struct s_node
{
	void	*content;
	t_node	*next;
};

typedef struct s_list
{
	t_node	*front;
	t_node	*back;
	int		size;
}	t_list;

//	LIST NEW & ADD

t_node	*ft_nodenew(void *content);

int		ft_lstadd_front(t_list *lst, t_node *new);

int		ft_lstadd_back(t_list *lst, t_node *new);

//	LIST UTILS

int		ft_lstsize(t_list *lst);

t_node	*ft_lstlast(t_list *lst);

//	LIST DELETE

void	ft_lstdelone(t_node *lst, void (*del)(void *));

int		ft_lstrmvone(t_list *lst, t_node *node, void (*del)(void *));

void	ft_lstclear(t_list *lst, void (*del)(void *));

//	STACK

typedef struct s_stack
{
	t_node	*front;
	int		size;
}	t_stack;

//	STACK OPERATIONS

int		push(t_stack *stack, t_node *new);

void	*pop(t_stack *stack);

void	*peak(t_stack *stack);

void	stack_clear(t_stack *s, void (*del)(void *));

//	QUEUE

typedef struct t_queue
{
	t_node	*front;
	t_node	*back;
	int		size;
}	t_queue;

//	QUEUE OPERATIONS

int		enqueue(t_queue *q, t_node *new);

void	*dequeue(t_queue *q);

void	queue_clear(t_queue *q, void (*del)(void *));

#endif
