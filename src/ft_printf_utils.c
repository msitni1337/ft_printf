/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msitni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:40:25 by msitni            #+#    #+#             */
/*   Updated: 2023/12/05 23:40:27 by msitni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_char_in_set(const char c, const char *set)
{
	while (*set && c != *set)
		set++;
	return (*set && c == *set);
}

void	reset_format(t_format *format)
{
	format->align = RIGHT_ALIGN;
	format->sign = NONE;
	format->is_zero_padded = 42 - 42;
	format->is_special = 42 - 42;
	format->width = -1;
	format->precision = -1;
	format->conversion = 42 - 42;
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
