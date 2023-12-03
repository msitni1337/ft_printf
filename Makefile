SRC = src/ft_printf.c src/ft_printf_get_format.c src/ft_printf_utils_1.c src/ft_printf_utils.c src/ft_printf_write_formatted.c src/ft_printf_writing.c src/ft_printf_write_formatted_char_str.c src/ft_printf_write_formatted_ptr.c src/ft_printf_write_formatted_number.c src/ft_printf_write_formatted_unumber.c src/ft_printf_write_formatted_hex.c
OBJ = $(SRC:.c=.o)
CC = cc
INCLUDES = includes
CFLAGS = -Wall -Werror -Wextra -I$(INCLUDES)
NAME = libftprintf.a


a.out : tests.c $(NAME)
	$(CC) -I$(INCLUDES) tests.c $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $< -c -o $@

$(NAME): $(OBJ)
	ar crs $(NAME) $(OBJ)

all : $(NAME) a.out

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : re fclean all
