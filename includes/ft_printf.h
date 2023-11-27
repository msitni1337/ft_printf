#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FFLAGS " #+-0"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_align
{
	LEFT = 0,
	ZERO,
	RIGHT
}			t_align;

typedef enum e_sign
{
	NONE = 0,
	SPACE,
	PLUS
}			t_sign;

typedef enum e_conv
{
	NONE = 0,
	num,
	chr,
	str,
	hex,
	ptr
}			t_conv;

typedef struct s_format
{
	int		is_valid;
	t_conv	conversion;
	t_align	align;
	t_sign	sign;
	int		padding;
	int		is_zero_padded;
	int		is_special;
	int		width;
}			t_format;

int			ft_printf(const char *fmt, ...);
int	is_char_in_set(const char c, const char*set)
int check_fmt_is_valid(char c, t_format*format)
void	reset_format(t_format*format);
void	write_char(const char**fmt, int*print_c);

#endif
