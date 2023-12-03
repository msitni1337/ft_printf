#include "ft_printf.h"

void	write_formatted_number(t_format*format, int nb, int*print_c)
{	
	int digits_count;
	int formatted_char_count;
	
	digits_count = ft_get_digits_count(nb, ft_strlen(DECI_STR));
	formatted_char_count = ft_max(format->precision, digits_count);
	if (nb < 0 || format->sign > NONE)
		formatted_char_count++;
	STOPPED WORKING HERE (COPIED FROM PTR WRITTING WITH NO MODOFCATIONS):
	[
	if (format->align == RIGHT_ALIGN)
	{
		write_ptr_padding(format, formatted_char_count, print_c);
		write_sign(format, print_c);
		write_ptr(ptr, format->precision, print_c);
	}
	if (format->align == LEFT_ALIGN)
	{
		write_sign(format, print_c);
		write_ptr(ptr, format->precision, print_c);
		if (format->width > formatted_char_count)
			ft_repeat_char(' ', format->width - formatted_char_count, print_c);
	}
	]
	(*print_c) += digits_count;
}

void	write_converted(t_format*format, va_list ap, int*print_c)
{
	if (format->conversion == 'c')
		write_formatted_char(format, va_arg(ap, int), print_c);
	else if (format->conversion == 's')
		write_formatted_string(format, va_arg(ap, char *), print_c);
	else if (format->conversion == 'p')
		write_formatted_ptr(format, va_arg(ap, unsigned long), print_c);
	else if (format->conversion == 'd' || format->conversion == 'i')
		write_formatted_number(format, va_arg(ap, int), print_c);
/*	else if (format->conversion == 'u')
		write_formatted_unumber(format, va_arg(ap, unsigned int), print_c);
	else if (format->conversion == 'x' || format->conversion == 'X')
		write_formatted_hex(format, va_arg(ap, unsigned int), print_c);
	else if (format->conversion == '%')
	{
		write(1, &format->conversion, 1);
		(*print_c)++;
	}
*/
}

void write_formatted(t_format*format, va_list ap, int*print_c)
{
	if (format->conversion)
		write_converted(format, ap, print_c);
/*	else
		//Check if we reached end of fmt;
		print_signature(format, print_c);
*/
}

