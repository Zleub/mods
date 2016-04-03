#include <mods.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <libft.h>

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

char *enum_to_string(int e) {
	if (e == NIL)
		return ("nil");
	else if (e == DOUBLE)
		return ("double");
	else if (e == FLOAT)
		return ("float");
	else if (e == STRING)
		return ("string");
	else if (e == POINTER)
		return ("pointer");
	else
		return ("Error");
}

void print_value(t_value *v, int lvl)
{
	int i = lvl;
	while (i) {
		printf("  ");
		i -= 1;
	}

	printf("%s, %s -> ", v->k, enum_to_string(v->e));
	if (v->e == DOUBLE)
		printf("%f", v->u.d);
	else if (v->e == FLOAT)
		printf("%f", v->u.f);
	else if (v->e == POINTER)
		printf("%p", v->u.p);
	else if (v->e == STRING)
		printf("%s", v->u.p);

	printf("\n");
	if (v->n)
		print_value(v->n, lvl + 1);
}

void debug(t_table *t)
{
	unsigned int i = 0;

	while (i < t->size) {
		if (t->array[i])
			print_value(t->array[i], 0);
		i += 1;
	}
}

#define Double(x) value(DOUBLE, (union u_value)(double)x)
#define Pointer(x) value(POINTER, (union u_value)(void *)x)
#define String(x) value(STRING, (union u_value)(void *)x)

int main(void)
{
	srand(time(NULL));

	t_table *t = init(8);

	set(t, "Arno", Double(4242));
	set(t, "arno", Pointer(&random_string));
	set(t, "arnaud", Double(4242));
	set(t, "adebray", String("Hello World"));

	printf("%f\n", get(t, "Arno")->u.d);
	printf("%s\n", ((char *(*)(int))(get(t, "arno")->u.p))(4));

	return (0);
}
