#include "ft_printf.h"

void write_ptr(unsigned long ptr, int precision, int*print_c)
{
	int ptr_digits_count;

	ptr_digits_count = ft_get_digits_ucount(ptr, ft_strlen(LHEX_STR));
	ft_putnstr(HEX_PREFIX, ft_strlen(HEX_PREFIX), print_c);
	if (precision > ptr_digits_count)
		ft_repeat_char('0', precision - ptr_digits_count, print_c);
	ft_putnbr_base(ptr, LHEX_STR, ft_strlen(LHEX_STR));
}

void write_ptr_padding(t_format*format, int ptr_formatted_char_count, int*print_c)
{
	if (!format->is_zero_padded && format->width > ptr_formatted_char_count)
		ft_repeat_char(' ', format->width - ptr_formatted_char_count, print_c);
	if (format->is_zero_padded && format->precision == -1)
	{
		format->precision = format->width - ft_strlen(HEX_PREFIX);
		if (format->sign > NONE)
			format->precision -= 1;
	}
}

void write_nil_ptr(t_format*format, int*print_c)
{
	if (format->align == RIGHT_ALIGN)
		ft_repeat_char(' ', format->width - ft_strlen(NIL_STR), print_c);
	ft_putnstr(NIL_STR, ft_strlen(NIL_STR), print_c);	
	if (format->align == LEFT_ALIGN)
		ft_repeat_char(' ', format->width - ft_strlen(NIL_STR), print_c);
}

void write_formatted_ptr(t_format*format, unsigned long ptr, int*print_c)
{
	int digits_count;
	int formatted_char_count;

	if (!ptr)
		return (write_nil_ptr(format, print_c));
	digits_count = ft_get_digits_ucount(ptr, ft_strlen(LHEX_STR));
	formatted_char_count = ft_strlen(HEX_PREFIX);
	formatted_char_count += ft_max(digits_count, format->precision);
	if (format->sign > NONE)
		formatted_char_count++;
	if (format->align == RIGHT_ALIGN)
	{
		write_ptr_padding(format, formatted_char_count, print_c);
		write_sign(format, 0, print_c);
		write_ptr(ptr, format->precision, print_c);
	}
	if (format->align == LEFT_ALIGN)
	{
		write_sign(format, 0,print_c);
		write_ptr(ptr, format->precision, print_c);
		if (format->width > formatted_char_count)
			ft_repeat_char(' ', format->width - formatted_char_count, print_c);
	}
	(*print_c) += digits_count;
}
