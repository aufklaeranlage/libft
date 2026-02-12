/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scratch_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 17:40:52 by abronner          #+#    #+#             */
/*   Updated: 2026/02/12 17:41:09 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scratch_buffer.h"

#include <stdlib.h>
#include "ft_std.h"

bool	scratch_buffer_grow(struct s_scratch_buffer *buffer)
{
	void			*new_ptr;
	const size_t	new_length = buffer->length * 2;

	scratch_buffer_free(buffer);
	if (new_length >= buffer->length)
		new_ptr = malloc(new_length);
	else
	{
		new_ptr = NULL;
		scratch_buffer_init(buffer);
		return (false);
	}
	buffer->data = new_ptr;
	buffer->length = new_length;
	return (true);
}

bool	scratch_buffer_grow_preserve(struct s_scratch_buffer *buffer)
{
	void			*new_ptr;
	const size_t	new_length = buffer->length * 2;

	if (new_length < buffer->length)
		return (false);
	new_ptr = malloc(new_length);
	if (new_ptr == NULL)
		return (false);
	ft_memcpy(new_ptr, buffer->data, buffer->length);
	if (buffer->data != buffer->u__space.__c)
		free(buffer->data);
	buffer->data = new_ptr;
	buffer->length = new_length;
	return (true);
}

bool	scratch_buffer_set_array_size(struct s_scratch_buffer *buffer,
	size_t nelem, size_t size)
{
	void			*new_ptr;
	const size_t	new_length = nelem * size;

	scratch_buffer_free(buffer);
	if (new_length >= buffer->length)
		new_ptr = malloc(new_length);
	else
	{
		new_ptr = NULL;
		scratch_buffer_init(buffer);
		return (false);
	}
	buffer->data = new_ptr;
	buffer->length = new_length;
	return (true);
}
