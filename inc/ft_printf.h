/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 17:38:36 by abronner          #+#    #+#             */
/*   Updated: 2026/02/26 10:41:59 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndnef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>

typedef unsigned char t_uchar;
typedef unsigned char t_uint;

typedef struct s_pf_info {
	int			prec;
	int			width;
	t_uchar		spec;
	t_uchar		pad;
	t_uint		alt:1;
	t_uint		space:1;
	t_uint		left:1;
	t_uint		showsign:1;
}	t_pf_info;

typedef struct s_worknum{
	unsigned long long int	num;
	int						base;
	int						is_negative;
}	t_worknum;

typedef struct s_pf_spec {
	t_pf_info		info;
	const t_uchar	*end_of_fmt;
	const t_uchar	*next_fmt;
}	t_pf_spec;

typedef union u_pf_arg {
	int				pa_int;
	unsigned int	pa_uint;
	const char		*pa_string;
	void			*pa_pointer;
}	t_pf_arg

/* * UTILS ****************************************************************** */

int	read_int(const t_uchar **pstr);

#endif
