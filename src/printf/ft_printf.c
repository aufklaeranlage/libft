/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 09:20:14 by abronner          #+#    #+#             */
/*   Updated: 2026/02/26 10:43:50 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_fprintf(int fd, const char *fmt, va_list ap)
{
	int				done;
	const t_uchar	*f;
	const t_uchar	*lead_str_end;
	const t_uchar	*end_of_spec;
	va_list			ap_save;

	done = 0;
	ap_save = va_copy(ap);
	f = find_spec((const t_uchar *)fmt);
	lead_str_end = f;
	if (!outstring(fd, (const t_uchar *)fmt, lead_str_end - fmt, &done))
		return (-1);
	if (*f == '\0')
		return (done);
}

void	process_format()
{
	
}

t_pf_info	read_info(const t_uchar **f)
{
	t_pf_info	info;

	init_info(&info);
	while (1)
	{
		++*f;
		if (**f == ' ')
			info.space = 1;
		else if (**f == '+')
			info.showsign = 1;
		else if (**f == '-')
		{
			info.left = 1;
			info.pad = ' '
		}
		else if (**f == '#')
			info.alt == 1;
		else if (**f == '0' && !info.left)
			info.pad == '0';
		else if (ft_isdigit(**f))
			info.width = read_int(f);
		else if (**f == '.')
		{
			++*f;
			info.prec = read_int(f);
		}
	}
	info.spec = **f;
}

void	init_info(t_pf_info *info)
{
	info->prec = -1;
	info->width = 0;
	info->pad = ' ';
	info->alt = 0;
	info->space = 0;
	info->left = 0;
	info->showsign = 0;
}

void	process_arg(t_pf_spec *spec)
{

}

void	get_number(t_pf_spec *spec, va_list ap)
{
	spec->number.is_negative = 0;
	spec->number.base = 10 + (spec->info.spec == 'x' || spec->info.spec == 'X') * 6;
	if (spec->info.spec == 'd' || spec->info.spec == 'i')
		spec->number.num = va_arg(ap, int);
	else
		spec->number.num = va_arg(ap, unsigned int);
	if (spec->number.num < 0)
	{
		spec->number.abs = (unsigned int)(-num);
		spec->info.is_negative = 1;
	}
	else
		spec->number.abs = (unsigned int)spec->number.num;
}
