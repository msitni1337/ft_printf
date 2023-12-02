#include "ft_printf.h"

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
