/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msitni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:41:47 by msitni            #+#    #+#             */
/*   Updated: 2023/12/05 23:42:23 by msitni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FFLAGS " #+-0"
# define FCONVERSIONS "cspdiuxX%"
# define HEX_PREFIX "0x"
# define DECI_STR "0123456789"
# define LHEX_STR "0123456789abcdef"
# define UHEX_STR "0123456789ABCDEF"
# define NULL_STR "(null)"
# define NIL_STR "(nil)"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_align
{
	RIGHT_ALIGN = 0,
	LEFT_ALIGN
}				t_align;

typedef enum e_sign
{
	NONE = 0,
	SPACE,
	PLUS
}				t_sign;

typedef struct s_format
{
	t_align		align;
	t_sign		sign;
	int			is_zero_padded;
	int			is_special;
	int			width;
	int			precision;
	char		conversion;
}				t_format;

int				ft_printf(const char *fmt, ...);
int				is_char_in_set(const char c, const char *set);
int				check_fmt_is_valid(char c, t_format *format);
void			reset_format(t_format *format);
int				ft_max(int a, int b);
int				ft_min(int a, int b);
const char		*get_format(const char *fmt, t_format *format);
void			write_formatted(t_format *format, va_list ap, int *print_c);
void			ft_repeat_char(char c, int count, int *print_c);
int				ft_strlen(const char *str);
void			ft_putnstr(char *s, int count, int *print_c);
void			ft_putnbr_base(unsigned long n, char *base, int base_count);
void			ft_putnbr_base_s(long n, char *base, int base_count);
unsigned int	ft_get_digits_count(long n, unsigned int base_count);
unsigned int	ft_get_digits_ucount(unsigned long n, unsigned int base_count);
void			write_formatted_char(t_format *format, char c, int *print_c);
void			write_formatted_string(t_format *format, char *str,
					int *print_c);
void			write_formatted_ptr(t_format *format, unsigned long ptr,
					int *print_c);
void			write_formatted_number(t_format *format, int nb, int *print_c);
void			write_formatted_unumber(t_format *format, unsigned int nb,
					int *print_c);
void			write_formatted_hex(t_format *format, unsigned int nb,
					int *print_c);
void			write_sign(t_format *format, int is_negative, int *print_c);

#endif
