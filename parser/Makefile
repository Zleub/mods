NAME = parser
LIBNAME = libparser.a

SRC = $(shell find src -name '*\.c')
OBJ = $(subst .c,.o, $(SRC))

CC = clang
HEADDIR ?= -I$(PWD)/inc -I$(PWD)/libft/inc
CFLAGS ?= -Wall -Werror -Wextra -xcpp-output $(HEADDIR)
LDFLAGS ?= -lft -Llibft -lparser -L.

all: libft $(LIBNAME) $(NAME) main.c inc/parse.h
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME) main.c

$(LIBNAME): $(OBJ)
	ar rc $@ $^
	ranlib $@

libft:
	make -C libft

clean:
	make -C libft clean
	rm -rf test
	rm -rf $(OBJ)

fclean:
	make -C libft fclean
	rm -rf test
	rm -rf $(OBJ)
	rm -rf $(NAME)

re: fclean libft
	make all

.PHONY: all $(LIBNAME) $(NAME) clean fclean re libft
all:
