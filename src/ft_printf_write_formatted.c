/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write_formatted.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msitni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:40:55 by msitni            #+#    #+#             */
/*   Updated: 2023/12/05 23:40:57 by msitni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_converted(t_format *format, va_list ap, int *print_c)
{
	if (format->conversion == 'c')
		write_formatted_char(format, va_arg(ap, int), print_c);
	else if (format->conversion == 's')
		write_formatted_string(format, va_arg(ap, char *), print_c);
	else if (format->conversion == 'p')
		write_formatted_ptr(format, va_arg(ap, unsigned long), print_c);
	else if (format->conversion == 'd' || format->conversion == 'i')
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
}

void	print_signature(t_format *format, int *print_c)
{
	ft_repeat_char('%', 1, print_c);
	if (format->is_special)
		ft_repeat_char('#', 1, print_c);
	if (format->sign == SPACE)
		ft_repeat_char(' ', 1, print_c);
	if (format->sign == PLUS)
		ft_repeat_char('+', 1, print_c);
	if (format->align == LEFT_ALIGN)
		ft_repeat_char('-', 1, print_c);
	else if (format->is_zero_padded)
		ft_repeat_char('0', 1, print_c);
	if (format->width != -1)
	{
		ft_putnbr_base_s(format->width, DECI_STR, ft_strlen(DECI_STR));
		*print_c += ft_get_digits_ucount(format->width, ft_strlen(DECI_STR));
	}
	if (format->precision != -1)
	{
		ft_repeat_char('.', 1, print_c);
		ft_putnbr_base_s(format->precision, DECI_STR, ft_strlen(DECI_STR));
		*print_c += ft_get_digits_ucount(format->precision,
				ft_strlen(DECI_STR));
	}
}

void	write_formatted(t_format *format, va_list ap, int *print_c)
{
	if (format->conversion)
		write_converted(format, ap, print_c);
	else
		print_signature(format, print_c);
}
