/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write_formatted_unumber.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msitni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:41:25 by msitni            #+#    #+#             */
/*   Updated: 2023/12/05 23:41:27 by msitni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_unumber_padding(t_format *format, int formatted_char_count,
		int *print_c)
{
	if (!format->is_zero_padded || format->precision != -1)
		ft_repeat_char(' ', format->width - formatted_char_count, print_c);
	if (format->is_zero_padded && format->precision == -1)
		ft_repeat_char('0', format->width - formatted_char_count, print_c);
}

void	write_formatted_unumber_(t_format *format, unsigned int nb,
		int *print_c)
{
	int	digits_count;
	int	formatted_char_count;

	digits_count = ft_get_digits_ucount(nb, ft_strlen(DECI_STR));
	formatted_char_count = ft_max(format->precision, digits_count);
	if (format->align == RIGHT_ALIGN)
	{
		write_unumber_padding(format, formatted_char_count, print_c);
		if (format->precision > digits_count)
			ft_repeat_char('0', format->precision - digits_count, print_c);
		ft_putnbr_base(nb, DECI_STR, ft_strlen(DECI_STR));
	}
	if (format->align == LEFT_ALIGN)
	{
		if (format->precision > digits_count)
			ft_repeat_char('0', format->precision - digits_count, print_c);
		ft_putnbr_base(nb, DECI_STR, ft_strlen(DECI_STR));
		if (format->width > formatted_char_count)
			ft_repeat_char(' ', format->width - formatted_char_count, print_c);
	}
	(*print_c) += digits_count;
}

void	write_formatted_unumber(t_format *format, unsigned int nb, int *print_c)
{
	if (!format->precision && !nb)
		ft_repeat_char(' ', format->width, print_c);
	else
		write_formatted_unumber_(format, nb, print_c);
}
