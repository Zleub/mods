NAME = libmods.a
SRC = $(shell find src -name '*\.c')
OBJ = $(subst .c,.o, $(SRC))

HEADDIR ?= -I$(PWD)/inc -I$(PWD)/libft/inc
CC ?= clang
CFLAGS ?= $(HEADDIR) -Wall -Werror -Wextra -O3
LDFLAGS ?= -lft -Llibft -lmods -L.

all: $(NAME) libft printf out test

out: main.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o a.out main.c

test: $(NAME) test.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o test test.c

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $@

libft:
	make -C libft

printf:
	make -C ft_printf

clean:
	make -C libft clean
	make -C ft_printf clean
	rm -rf test
	rm -rf $(OBJ)

fclean:
	make -C libft fclean
	make -C ft_printf fclean
	rm -rf test
	rm -rf $(OBJ)
	rm -rf $(NAME)

re: fclean
	make all

.PHONY: all out test $(NAME) clean fclean re libft printf cpp
