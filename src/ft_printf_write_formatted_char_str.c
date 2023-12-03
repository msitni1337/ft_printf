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

