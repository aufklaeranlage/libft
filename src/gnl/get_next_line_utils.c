/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:20:07 by abronner          #+#    #+#             */
/*   Updated: 2025/09/17 14:37:52 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gnl.h"
#include "ft_list.h"
#include "ft_string.h"

#include <stdlib.h>

static size_t	get_line_size(t_list *lst);

static void		cpy_substrings(t_list *lst, char *line);

void	strclear(void *ptr)
{
	t_str	*s;

	s = (t_str *)ptr;
	free(s->data);
	free(s);
}

char	*create_line(t_list *lst)
{
	char	*line;
	size_t	size;

	size = get_line_size(lst);
	if (!size)
		return (NULL);
	line = malloc(sizeof(*line) * (size + 1));
	if (!line)
		return (NULL);
	line[size] = 0;
	cpy_substrings(lst, line);
	return (line);
}

/*! @brief Returns the length of the line stored in `lst`.
 *  @param `lst` The list containing the line which's size will be returned.
 *
 *  Iterates over the nodes in the list `lst` until a node with a `\n` character
 *  as it's last character is found, summing up the length of all nodes
 *  encountered.
 *
 *  @return returns the length on success; 0 if the list is unpopulated.
 *
 *  We expect the list to be properly populated and don't perform safety checks
 *  on the node's payload.
 */

static size_t	get_line_size(t_list *lst)
{
	size_t	total;
	t_node	*node;
	t_str	*str;

	total = 0;
	node = lst->front;
	if (!node)
		return (0);
	str = (t_str *)node->content;
	while (1)
	{
		total += ((t_str *)node->content)->size;
		node = node->next;
		if (!node || str->data[str->size - 1] == '\n')
			return (total);
		str = (t_str *)node->content;
	}
	return (total);
}

/*! @brief Creates a string from the nodes in `lst` until a `\n` character is
 *  @brief found as the last character of a node.
 *  @param `lst` The list from which the string should be built.
 *  @param `line` The preallocated buffer of an appropriate size.
 *
 *  Iterates over the list of nodes in `lst` copying their contents into
 *  `line` until a `\n` character is found or the last node was copied.
 */

static void	cpy_substrings(t_list *lst, char *line)
{
	size_t	total;
	t_node	*node;
	t_node	*tmp;
	t_str	*str;

	total = 0;
	node = lst->front;
	str = (t_str *)node->content;
	while (1)
	{
		ft_strncpy(line + total, str->data, str->size);
		total += str->size;
		tmp = node->next;
		ft_lstrmvone(lst, node, strclear);
		node = tmp;
		if (!node || line[total - 1] == '\n')
			break ;
		str = (t_str *)node->content;
	}
}
