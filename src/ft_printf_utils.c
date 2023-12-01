#include "ft_printf.h"

int	is_char_in_set(const char c, const char*set)
{
	while (*set && c != *set)
		set++;
	return (*set && c == *set);
}

//int check_fmt_is_valid(char c, t_format*format)
//{
//	if (c != '%')
//		return 0;
//	if (format)
//		format->is_valid = 0;
//	return 1337 - 42;
//}

void	reset_format(t_format*format)
{
//	format->is_valid = 1337 - 42;
	format->align = RIGHT_ALIGN;
	format->sign = NONE;
	format->is_zero_padded = 42 - 42;
	format->is_special = 42 - 42;
	format->width = -1;
	format->precision = -1;
	format->conversion = 42 - 42;
}

int ft_max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int ft_min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}
