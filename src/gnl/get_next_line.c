/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 09:37:27 by abronner          #+#    #+#             */
/*   Updated: 2025/09/17 14:38:34 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gnl.h"
#include "ft_list.h"
#include "ft_string.h"

#include <stdlib.h>
#include <unistd.h>

static int	fill_list(t_list *lst, int fd);

static int	read_to_node(t_list *lst, int fd);

static int	store_str(t_list *lst, size_t size, char *str);

char	*get_next_line(int fd)
{
	static t_list	remain[MAXFDS];
	char			*out;

	if (fd < 0 || fd >= MAXFDS)
		return (NULL);
	if (read(fd, NULL, 0) == -1)
		return (ft_lstclear(remain + fd, strclear), NULL);
	if (!fill_list(remain + fd, fd))
		return (ft_lstclear(remain + fd, strclear), NULL);
	out = create_line(remain + fd);
	if (!out)
		return (ft_lstclear(remain + fd, strclear), NULL);
	return (out);
}

//	Either the list has a finished node in the first position and we return
//	or it needs to be filled.

static int	fill_list(t_list *lst, int fd)
{
	t_node	*node;
	t_str	*str;

	if (!lst->front)
		if (!read_to_node(lst, fd))
			return (0);
	node = lst->front;
	str = node->content;
	while (str->size > 0 && str->data[str->size - 1] != '\n')
	{
		if (!read_to_node(lst, fd))
			return (0);
		node = node->next;
		str = node->content;
	}
	return (1);
}

/*! @brief Fills the list at `lst` from `fd` until a `\n` character is found.
 *
 *  @param `lst` The list to be filled.
 *  @param `fd` The file descriptor from which input is read.
 *
 *  Reads from `fd` into the list pointed to by `lst` until a newline
 *  character was found.
 *
 *  @return Returns 1 on success; 0 on failure.
 */

static int	read_to_node(t_list *lst, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	size_t	size;
	char	*tmp[2];

	size = read(fd, buf, BUFFER_SIZE);
	if (size <= 0)
		return (0);
	buf[size] = '\0';
	tmp[0] = buf;
	tmp[1] = ft_strchr(tmp[0], '\n');
	while (tmp[1])
	{
		if (!store_str(lst, tmp[1] - tmp[0] + 1, tmp[0]))
			return (0);
		tmp[0] = tmp[1] + 1;
		tmp[1] = ft_strchr(tmp[0], '\n');
	}
	tmp[1] = buf + size;
	if (!store_str(lst, tmp[1] - tmp[0], tmp[0]))
		return (0);
	return (1);
}

/*!	@brief Adds a string from `str` to `str` + `size` to the back of `lst`.
 *	@param `lst` The list to append the new substring to.
 *	@param `size` The size of the string to be appended to `lst`.
 *	@param `str` The beginning of the string to be appended to `lst`.
 *
 *	Creates a new `t_node`, `t_str` and substring and adds the node that
 *	contains the `t_str` as a payload to the end of `lst`.
 *
 *	@return Returns 1 on success; 0 on failure to allocate or being provided
 *	a size of 0.
 */

static int	store_str(t_list *lst, size_t size, char *str)
{
	char	*substr;
	t_str	*content;
	t_node	*node;

	if (size == 0)
		return (0);
	content = malloc(sizeof(*content));
	node = ft_nodenew(NULL);
	substr = ft_substr(str, 0, size);
	if (!content || !node || !substr) {
		free(content);
		free(node);
		free(substr);
		return (0);
	}
	content->size = size;
	content->data = substr;
	node->content = content;
	ft_lstadd_back(lst, node);
	return (1);
}
