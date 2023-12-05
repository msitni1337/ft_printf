/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_writing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msitni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:41:19 by msitni            #+#    #+#             */
/*   Updated: 2023/12/05 23:41:20 by msitni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_repeat_char(char c, int count, int *print_c)
{
	int	i;

	i = 0;
	while (i < count)
	{
		write(1, &c, 1);
		(*print_c)++;
		i++;
	}
}

void	ft_putnstr(char *s, int count, int *print_c)
{
	int	i;

	i = 0;
	while (i < count)
	{
		write(1, s + i, 1);
		(*print_c)++;
		i++;
	}
}

void	ft_putnbr_base(unsigned long n, char *base, int base_count)
{
	if (n < (unsigned long)base_count)
	{
		write(1, base + n, 1);
		return ;
	}
	ft_putnbr_base(n / base_count, base, base_count);
	ft_putnbr_base(n % base_count, base, base_count);
}

void	ft_putnbr_base_s(long n, char *base, int base_count)
{
	if (n < 0)
		n = -n;
	if (n < base_count)
	{
		write(1, base + n, 1);
		return ;
	}
	ft_putnbr_base(n / base_count, base, base_count);
	ft_putnbr_base(n % base_count, base, base_count);
}
