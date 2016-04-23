#include <mods.h>

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

char *random_string(int size)
{
	char *str = malloc(size + 1);
	ft_bzero(str, size + 1);

	while (size)
	{
		str[size - 1] = arc4random_uniform(26) + 65;
		size -= 1;
	}
	return str;
}


#define Double(x) value(DOUBLE, (union u_value)(double)x)
#define Pointer(x) value(POINTER, (union u_value)(void *)x)
#define String(x) value(STRING, (union u_value)(void *)x)

typedef char *(*t_f)(int);

#define VAR(...) __VA_ARGS__

// int main(void)
// {
// 	srand(time(NULL));

// 	t_table *t = table_init(8);

// 	table_set(t, "Arno", Double(4242));
// 	table_set(t, "arno", Pointer(&random_string));
// 	table_set(t, "arnaud", Double(4242));
// 	table_set(t, "adebray", String("Hello World"));

// 	printf("%f\n", table_get(t, "Arno")->u.d);
// 	printf("%s\n", ( (char *(*)(int)) (table_get(t, "arno")->u.p) )(4));

// 	int i = 0;
// 	while (i < 10)
// 	{
// 		table_set(t, random_string(10), Double(i));
// 		i += 1;
// 	}

// 	table_debug(t);
// 	return (0);
// }

int main(void)
{
	t_stack *s = stack_init( Double(1) );

	s = stack_push(s, Double(2) );
	s = stack_push(s, Double(3) );

	stack_debug(s);
	printf("\n");

	s = stack_push(s, Double(4) );
	s = stack_push(s, Double(5) );

	s = stack_pop(s);

	s = stack_push(s, Double(6) );
	s = stack_push(s, Double(7) );

	stack_debug(s);
	printf("\n");
	return (0);
}
