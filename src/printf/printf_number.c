#include "ft_printf.h"

/* UINTMAX is 4294967295 which has 10 digits so allocating a buffer
 * with a size of 11 beforehand allows us to write any number in there
 */
void	print_number(t_pf_spec *spec, va_list va)
{
	t_pf_arg			num;
	t_worknum			worknum;

	worknum.base = 10;
	worknum.is_negative = 0;
	if (spec->info.spec == 'd' || spec->info.spec == 'i')
	{
		num.pa_int = va_arg(va, int);
		worknum.num = (unsigned long long int)num.pa_int;
		if (num.pa_int < 0)
		{
			worknum.is_negative = 1;
			worknum.num = (unsigned long long int)-num.pa_int;
		}
	}
	else if (spec->info.spec == 'u' || spec->info.spec == 'x' ||
		  spec->info.spec == 'X')
	{
		num.pa_uint = va_arg(va, unsigned int);
		worknum.num = (unsigned long long int)num.pa_uint;
		if (spec->info.spec != 'u')
			worknum.base = 16;
	}
	else
	{
		num.pa_pointer = va_arg(va, void *);
		worknum.num = (unsigned long long int)num.pa_pointer;
		worknum.base = 16;
	}
}

void	print_worknum(t_pf_spec *spec, t_worknum *worknum)
{
	const char				basestr[16] = "0123456789abcdef";
	static const char		numbuf[14];
	const char				*workend = numbuf + 19;
	unsigned long long int	val;

	val = worknum.num;
	*--workend = basestr[val % worknum.base];
	val /= worknum.base;
	while (val > 0)
	{
		*--workend = basestr[val % worknum.base];
		val /= worknum.base;
	}
	spec.info->width -= 10 - (workend - numbuf);
	if ((spec->info.alt && (spec->info.spec == 'x'
	 	|| spec->info.spec == 'X')) || spec->info.spec == 'p')
		spec->info.width -= 2;
	{
		*--workend = 'x';
		*--workend = '0';
		spec->info.width -= 2;
		if (spec->info.spec == 'X')
			ft_striteri(workend + 1, &to_upper);
	}
	if (worknum.is_negative)
	{
		*--workend = '-';
		spec->info.width -= 1;
	}
	else if (spec->info.showsign == 1)
	{
		*--workend = '+';
		spec->info.width -= 1;
	}
	while (spec->info.left && spec->info.width > 0)
		write(fd, &spec->info.pad, 1);
	ft_putstrfd(fd, workend + 1);
	while (spec->info.width > 0)
		write(fd, &spec->info.pad, 1);
}
