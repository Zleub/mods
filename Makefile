NAME = libmods.a
SRC = $(shell find ./src -name '*\.c')
OBJ = $(subst .c,.o, $(SRC))

HEADDIR	?= -I$(PWD)/inc -I$(PWD)/libft/inc -I$(PWD)/ft_printf/inc
CC		?= clang
CFLAGS	?= $(HEADDIR) -Wall -Werror -Wextra -O3

all: $(NAME) test

test: libmods.a test.c
	$(CC) $(CFLAGS) -lmods -L. -Llibft -lft -Lft_printf -lftprintf -o test test.c

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $@

clean:
	rm -rf test
	rm -rf $(OBJ)

fclean:
	rm -rf test
	rm -rf $(OBJ)
	rm -rf $(NAME)

re: fclean all
