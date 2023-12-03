#include "ft_printf.h"

void write_zero_hex(t_format*format, int*print_c)
{
	int repeat_count;

	repeat_count = ft_max(1, format->precision);
	if (format->align == RIGHT_ALIGN)
	{
		if (format->is_zero_padded && format->precision == -1)
			ft_repeat_char('0', format->width - repeat_count, print_c);
		else
			ft_repeat_char(' ', format->width - repeat_count, print_c);
		ft_repeat_char('0', repeat_count, print_c);
	}
	if (format->align == LEFT_ALIGN)
	{
		ft_repeat_char('0', repeat_count, print_c);
		ft_repeat_char(' ', format->width - repeat_count, print_c);
	}	
}

void write_hex_padding(t_format*format, int hex_formatted_char_count, int*print_c)
{
	if (format->precision != -1 || (!format->is_zero_padded && format->width > hex_formatted_char_count))
		ft_repeat_char(' ', format->width - hex_formatted_char_count, print_c);
	if (format->is_zero_padded && format->precision == -1)
	{
		if (format->is_special)
			format->precision = format->width - ft_strlen(HEX_PREFIX);
		else
			format->precision = format->width;
	}
}

void write_hex(t_format*format, unsigned long nb, int*print_c)
{
	int digits_count;

	digits_count = ft_get_digits_ucount(nb, ft_strlen(LHEX_STR));
	if (format->is_special)
	{
		ft_repeat_char('0', 1, print_c);
		ft_repeat_char(format->conversion, 1, print_c);
	}
	if (format->precision > digits_count)
		ft_repeat_char('0', format->precision - digits_count, print_c);
	if (format->conversion == 'x')
		ft_putnbr_base(nb, LHEX_STR, ft_strlen(LHEX_STR));
	if (format->conversion == 'X')
		ft_putnbr_base(nb, UHEX_STR, ft_strlen(UHEX_STR));
	*print_c += digits_count;
}

void write_formatted_hex_(t_format*format, unsigned int nb, int*print_c)
{
	int digits_count;
	int formatted_char_count;

	if (!nb)
		return (write_zero_hex(format, print_c));
	digits_count = ft_get_digits_ucount(nb, ft_strlen(LHEX_STR));
	formatted_char_count = 0;
	if (format->is_special)
		formatted_char_count = ft_strlen(HEX_PREFIX);
	formatted_char_count += ft_max(digits_count, format->precision);
	if (format->align == RIGHT_ALIGN)
	{
		write_hex_padding(format, formatted_char_count, print_c);
		write_hex(format, nb, print_c);
	}
	if (format->align == LEFT_ALIGN)
	{
		write_hex(format, nb, print_c);
		if (format->width > formatted_char_count)
			ft_repeat_char(' ', format->width - formatted_char_count, print_c);
	}
}

void write_formatted_hex(t_format*format, unsigned int nb, int*print_c)
{
	if (!format->precision && !nb)
		ft_repeat_char(' ', format->width, print_c);
	else
		write_formatted_hex_(format, nb, print_c);
}
