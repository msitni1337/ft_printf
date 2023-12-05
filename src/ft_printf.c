/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msitni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:40:35 by msitni            #+#    #+#             */
/*   Updated: 2023/12/05 23:40:40 by msitni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			print_c;
	t_format	format;

	if (!fmt)
		return (-1);
	va_start(ap, fmt);
	print_c = 0;
	while (*fmt)
	{
		if (*fmt != '%')
		{
			ft_repeat_char(*fmt, 1, &print_c);
			fmt++;
			continue ;
		}
		fmt = get_format(fmt, &format);
		if (!format.conversion && !*fmt)
			return (-1);
		write_formatted(&format, ap, &print_c);
	}
	va_end(ap);
	return (print_c);
}
