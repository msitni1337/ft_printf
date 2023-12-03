#include "ft_printf.h"

void write_formatted_char(t_format*format, char c, int*print_c)
{
	if (format->align == RIGHT_ALIGN)
		ft_repeat_char(' ', format->width - 1, print_c);
	ft_repeat_char(c, 1, print_c);
	if (format->align == LEFT_ALIGN)
		ft_repeat_char(' ', format->width - 1, print_c);
}

void write_formatted_string(t_format*format, char*str, int*print_c)
{
	int str_s;
	
	if (!str && (format->precision >= ft_strlen(NULL_STR) || format->precision == -1))
		str = NULL_STR;
	str_s = ft_strlen(str);
	if (format->precision != -1)
		str_s = ft_min(format->precision, str_s);
	if (format->align == RIGHT_ALIGN)
	{
		if (format->width > str_s)
			ft_repeat_char(' ', format->width - str_s, print_c);
		ft_putnstr(str, str_s, print_c);
	}
	if (format->align == LEFT_ALIGN)
	{
		ft_putnstr(str, str_s, print_c);
		if (format->width > str_s)
			ft_repeat_char(' ', format->width - str_s, print_c);
	}
}

void print_converted(t_format*format, va_list ap, int*print_c)
{
	if (format->conversion == 'c')
		write_formatted_char(format, va_arg(ap, int), print_c);
	else if (format->conversion == 's')
		write_formatted_string(format, va_arg(ap, char *), print_c);
	else if (format->conversion == 'p')
		write_formatted_ptr(format, va_arg(ap, unsigned long), print_c);
/*	else if (format->conversion == 'd' || format->conversion == 'i')
		write_formatted_number(format, va_arg(ap, int), print_c);
	else if (format->conversion == 'u')
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

void write_formatted(/*const char*fmt, */t_format*format, va_list ap, int*print_c)
{
	if (format->conversion)
		print_converted(format, ap, print_c);
/*	else
		//Check if we reached end of fmt;
		print_signature(format, print_c);
*/
}

