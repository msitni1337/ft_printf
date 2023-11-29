#include "ft_printf.h"

void ft_repeat_char(char c, int count, int*print_c)
{
	int i;

	i = 0;
	while (i < count)
	{
		write(1, &c, 1);
		(*print_c)++;
		i++;
	}
}
