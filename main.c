#include <stdio.h>
#include <stdlib.h>

#define E(t) t,
#define E_LIST E(CHAR) E(SHORT) E(INT) E(DOUBLE) E(E_TYPE_LEN)
enum e_types {
	E_LIST
};

#define A(t) ALLOCATOR(t)
#define ALLOCATOR_LIST A(char) A(short) A(int) A(double)
ALLOCATOR_LIST

#undef A
#define A(t) t __##t;
union u_value {
	ALLOCATOR_LIST
};

#define SET_TYPE(e, t) ((t)(e.__##t))
#define GET_TYPE(e, t) ((t)(e.__##t))

typedef union u_value t_value;

int main(void)
{
	t_value v;

	v.__int = 42;
	printf("%d\n", GET_TYPE(v, int));
	printf("%s -> ft_parse_1('1')\n", ft_parse_1('1') ? "true" : "false");
	printf("%s -> ft_parse_1('2')\n", ft_parse_1('2') ? "true" : "false");
	printf("%s -> ft_parse_a('a')\n", ft_parse_a('a') ? "true" : "false");
	return (0);
}
