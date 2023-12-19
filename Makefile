CC = cc
NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra
SRC = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_tohex.c ft_ptohex.c ft_unsignednbr.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re