NAME = libmods.a
SRC = $(shell find src -name '*\.c')
OBJ = $(subst .c,.o, $(SRC))

HEADDIR ?= -I$(PWD)/inc
CC = clang
CFLAGS ?= $(HEADDIR) -Wall -Werror -Wextra -O3

all: $(NAME) libft printf out test

out: main.c
	$(CC) $(CFLAGS) -o a.out main.c

cpp: main.c
	$(CC) -E main.c

test: $(NAME) test.c
	$(CC) $(CFLAGS) -lmods -L. -o test test.c

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
