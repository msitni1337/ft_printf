#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FFLAGS " #+-0"
# define FCONVERSIONS "cspdiuxX%"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_align
{
	RIGHT_ALIGN = 0,
	LEFT_ALIGN
}			t_align;

typedef enum e_sign
{
	NONE = 0,
	SPACE,
	PLUS
}			t_sign;

/*
typedef enum e_conv
{
	NONE = 0,
	num,
	chr,
	str,
	hex,
	ptr
}			t_conv;
*/

typedef struct s_format
{
	//int		is_valid;
	t_align	align;
	t_sign	sign;
	int		is_zero_padded;
	int		is_special;
	int		width;
	int		precision;
	char	conversion;
}			t_format;

int			ft_printf(const char *fmt, ...);
int	is_char_in_set(const char c, const char*set);
int check_fmt_is_valid(char c, t_format*format);
void	reset_format(t_format*format);
int ft_max(int a, int b);
int ft_min(int a, int b);
const char* get_format(const char *fmt, t_format*format);
void write_formatted(/*const char*fmt, */t_format*format, va_list ap, int*print_c);
void ft_repeat_char(char c, int count, int*print_c);
int ft_strlen(const char*str);
void ft_putnstr(char *s, int count, int*print_c);

#endif
