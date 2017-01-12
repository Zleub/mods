NAME = libmods.a
SRC = $(shell find ./src -name '*\.c')
OBJ = $(subst .c,.o, $(SRC))

HEADDIR	?= -I$(PWD)/inc -I$(PWD)/libft/inc -I$(PWD)/ft_printf/inc
CC		?= clang
CFLAGS	?= $(HEADDIR) -Wall -Werror -Wextra -O3

all: dep $(NAME) test main.c
	$(CC) $(CFLAGS) -include test.adebray -lmods -L. -Llibft -lft -Lft_printf -lftprintf -o a.out main.c

test: libmods.a test.c
	$(CC) $(CFLAGS) -lmods -L. -Llibft -lft -Lft_printf -lftprintf -o test test.c

dep:
	make -C libft
	make -C ft_printf

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

re: fclean
	make -C libft re
	make -C ft_printf re
	make all
