#include "ft_printf.h"

void write_sign(t_format*format, int is_negative, int*print_c)
{
	if (is_negative)
		ft_repeat_char('-', 1, print_c);
	else if (format->sign == SPACE)
		ft_repeat_char(' ', 1, print_c);
	else if (format->sign == PLUS)
		ft_repeat_char('+', 1, print_c);
}

unsigned int ft_get_digits_ucount(unsigned long n, unsigned int base_count)
{
	unsigned int count;

	count = 1;
	while (n >= base_count)
	{
		n /= base_count;
		count++;
	}
	return count;
}

unsigned int ft_get_digits_count(long n, unsigned int base_count)
{
	unsigned int count;
	
	if (n < 0)
		n = -n;
	count = 1;
	while (n >= base_count)
	{
		n /= base_count;
		count++;
	}
	return count;
}

int ft_strlen(const char*str)
{
	int i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}
