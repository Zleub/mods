#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <libft.h>
#include <types.h>

unsigned int	hash(char *line)
{
	unsigned int	h;
	int				c;

	h = 5381;
	while ((c = *line++))
		h = ((h << 5) + h) ^ c;
	return (h);
}

t_table *table(t_uint64 size) {
	t_table *t;

	t = table_alloc();
	t->size = size;
	t->table = malloc(sizeof(t_value) * size);
	ft_bzero(t->table, sizeof(t_value) * size);
	t->array = malloc(sizeof(t_value) * size);
	ft_bzero(t->array, sizeof(t_value) * size);
	return t;
}

void debug_table(t_table *t) {
	printf("%p\n", t);

	t_uint64 i = 0;
 	while (i < t->size) {
		printf("%lu: %lx\n", i, t->table[i].int64);
		i += 1;
	}

	i = 0;
	while (i < t->size) {
		printf("%lu: %p\n", i, t->array[i]);
		i += 1;
	}
}

void table_set(t_table *t, char *key, t_value value) {
	t_uint32 h = hash(key) % t->size;
	t->table[h] = value;
	t_uint64 i = 0;
	while (i < t->size)
	{
		if (t->array[i] == &t->table[h])
			printf("got a collision %s\n", key);
		if (!t->array[i]) {
			t->array[i] = &t->table[h];
			break ;
		}
		i += 1;
	}
}

int main(void)
{
	debug_types();

	t_table *t = table(12);
	table_set(t, "arno", (t_value)1);
	table_set(t, "arnaud", (t_value)2);
	table_set(t, "arnault", (t_value)3);
	table_set(t, "tluanra", (t_value)4);
	table_set(t, "duanra", (t_value)5);
	table_set(t, "onra", (t_value)6);

	t_uint8 huit = 8;
	table_set(t, "huit", (t_value)(void*)&huit);

	debug_table(t);
	return (0);
}
