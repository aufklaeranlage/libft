/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 10:21:06 by abronner          #+#    #+#             */
/*   Updated: 2025/07/12 10:42:13 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include <stdint.h>

//	Allocates unused space for an array of 'nelem' elements, each of whose size
//	in bytes is 'elsize'. The space shall be initialized to all bits '\0'
//	Upon successful completion with both 'nelem' and 'elsize' non-zero, returns
//	a pointer to the allocated space. If either nelem or elsize is 0 then a
//	pointer to the allocated space is returned, The allocated shall ensure that
//	the pointer is not used to access an object. On failure to allocate returns
//	NULL.

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*ret;
	size_t	size;

	if (!nelem || SIZE_MAX / nelem < elsize)
		return (NULL);
	size = nelem * elsize;
	if (nelem == 0 || elsize == 0)
		size = 4;
	ret = malloc(size);
	if (ret)
		ft_bzero(ret, size);
	return (ret);
}
