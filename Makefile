NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

SRC = 	src/ft_printf.c \
		src/do_check.c \
		src/handle_put.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

comp: re
	$(MAKE) clean
	clear

test: comp
	$(CC) $(CFLAGS) -I src -o teste.o main.c $(NAME)
	clear
	./teste.o

.PHONY: all clean fclean re comp