/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msitni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:40:42 by msitni            #+#    #+#             */
/*   Updated: 2023/12/05 23:40:44 by msitni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*get_flags(const char *fmt, t_format *format)
{
	while (*fmt && is_char_in_set(*fmt, FFLAGS))
	{
		if (*fmt == '0')
			format->is_zero_padded = 1337 - 42;
		else if (*fmt == '#')
			format->is_special = ft_strlen(HEX_PREFIX);
		else if (*fmt == '-')
			format->align = LEFT_ALIGN;
		else if (*fmt == ' ')
			format->sign = ft_max(format->sign, SPACE);
		else if (*fmt == '+')
			format->sign = ft_max(format->sign, PLUS);
		fmt++;
	}
	return (fmt);
}

const char	*get_min_width(const char *fmt, t_format *format)
{
	if (!(*fmt >= '0' && *fmt <= '9'))
		return (fmt);
	format->width = 0;
	while (*fmt && (*fmt >= '0' && *fmt <= '9'))
	{
		format->width = (format->width * 10) + (*fmt - '0');
		fmt++;
	}
	return (fmt);
}

const char	*get_precision(const char *fmt, t_format *format)
{
	if (*fmt != '.')
		return (fmt);
	fmt++;
	format->precision = 0;
	while (*fmt && (*fmt >= '0' && *fmt <= '9'))
	{
		format->precision = (format->precision * 10) + (*fmt - '0');
		fmt++;
	}
	return (fmt);
}

const char	*get_conversion(const char *fmt, t_format *format)
{
	if (is_char_in_set(*fmt, FCONVERSIONS))
	{
		format->conversion = *fmt;
		fmt++;
	}
	return (fmt);
}

const char	*get_format(const char *fmt, t_format *format)
{
	fmt++;
	reset_format(format);
	fmt = get_flags(fmt, format);
	fmt = get_min_width(fmt, format);
	fmt = get_precision(fmt, format);
	fmt = get_conversion(fmt, format);
	return (fmt);
}
