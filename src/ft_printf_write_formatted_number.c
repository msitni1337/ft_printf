#include "ft_printf.h"

void	write_padding_and_sign(t_format*format, int nb, int formatted_char_count, int*print_c)
{
	if (!format->is_zero_padded || format->precision != -1)
		ft_repeat_char(' ', format->width - formatted_char_count, print_c);
	write_sign(format, nb < 0, print_c);
	if (format->is_zero_padded && format->precision == -1)
		ft_repeat_char('0', format->width - formatted_char_count, print_c);
}

void	write_formatted_number_(t_format*format, int nb, int*print_c)
{	
	int digits_count;
	int formatted_char_count;
	
	digits_count = ft_get_digits_count(nb, ft_strlen(DECI_STR));
	formatted_char_count = ft_max(format->precision, digits_count);
	if (nb < 0 || format->sign > NONE)
		formatted_char_count++;
	if (format->align == RIGHT_ALIGN)
	{
		write_padding_and_sign(format, nb, formatted_char_count, print_c);
		if (format->precision > digits_count)
			ft_repeat_char('0', format->precision - digits_count, print_c);
		ft_putnbr_base_s(nb, DECI_STR, ft_strlen(DECI_STR));
	}
	if (format->align == LEFT_ALIGN)
	{
		write_sign(format, nb < 0, print_c);
		if (format->precision > digits_count)
			ft_repeat_char('0', format->precision - digits_count, print_c);
		ft_putnbr_base_s(nb, DECI_STR, ft_strlen(DECI_STR));
		if (format->width > formatted_char_count)
			ft_repeat_char(' ', format->width - formatted_char_count, print_c);
	}
	(*print_c) += digits_count;
}

void	write_formatted_number(t_format*format, int nb, int*print_c)
{
	if (!format->precision && !nb)
		ft_repeat_char(' ', format->width, print_c);
	else
		write_formatted_number_(format, nb, print_c);
}
