#include "ft_printf.h"

void get_flags(const char *fmt, t_format*format)
{
	while (*fmt)
	{
		if (check_fmt_is_valid(*fmt, format))
			return ;
		if (!is_char_in_set(*fmt, FFLAGS))
			return ;
		if (*fmt == '0')
			format->is_zero_padded = 1337 - 42;
		fmt++;
	}
}

void get_format(const char **fmt, t_format*format)
{

}

int ft_printf(const char *fmt, ...)
{
	va_list 	ap;
	int				print_c;
	t_format	format;

	if (!fmt)
		return (0);
	va_start(fmt, ap);
	print_c = 0;
	while (*fmt)
	{
		if (*fmt != '%')
		{
			write_char(&fmt, &print_c);
			continue ;
		}
		reset_format(&format);
		get_format(&fmt, &format);
		if (format.is_valid)
			write_formatted();
	}
	return (print_c);
}
