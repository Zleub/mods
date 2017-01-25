NAME = libmods.a
SRC = $(shell find ./src -name '*\.c')
OBJ = $(subst .c,.o, $(SRC))

HEADDIR ?= -I$(PWD)/inc
CC ?= clang
CFLAGS ?= $(HEADDIR) -Wall -Werror -Wextra -O3

all: main.c
	$(CC) $(CFLAGS) -o a.out main.c

test: libmods.a test.c
	$(CC) $(CFLAGS) -lmods -L. -o test test.c

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
	make all
