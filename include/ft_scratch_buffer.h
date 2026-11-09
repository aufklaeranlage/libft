/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scratch_buffer.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:55:06 by abronner          #+#    #+#             */
/*   Updated: 2026/02/12 17:40:28 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCRATCH_BUFFER_H
# define FT_SCRATCH_BUFFER_H

# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>

struct s_scratch_buffer {
	void	*data;
	size_t	length;
	union {
		max_align_t	__align;
		char		__c[1024];
	} u__space;
};

inline void
	scratch_buffer_init(struct s_scratch_buffer *buffer)
{
	buffer->data = buffer->u__space.__c;
	buffer->length = sizeof(buffer->u__space);
}

inline void
	scratch_buffer_free(struct s_scratch_buffer *buffer)
{
	if (buffer->data != buffer->u__space.__c)
		free(buffer->data);
}

bool	scratch_buffer_grow(struct s_scratch_buffer *buffer);

bool	scratch_buffer_grow_preserve(struct s_scratch_buffer *buffer);

bool	scratch_buffer_set_array_size(struct s_scratch_buffer *buffer,
		size_t nelem, size_t size);

#endif
