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
	t->array[0] = (t_value){ .value = (union u_value)(t_uptr)t, .tag = POINTER };
	return t;
}

void debug_table(t_table *t) {
	printf("debug_table %p\n", t);

	t_uint64 i = 0;
	printf("              %-36s| ", "Array");
	printf("              %-18s\n", "Table");
	printf("--------------------------");
	printf("--------------------------");
	printf("--------------------------");
	printf("--------------------------\n");
 	while (i < t->size) {
		printf("%-4lu { \e[38;5;%dm%p\e[38;5;7m }: %-24d |\t",
			i, ((char)&t->array[i]) + 127, &t->array[i], t->array[i].tag);
		printf("%-4lu: \e[38;5;%dm%p\e[38;5;7m\n",
			i, ((char)t->table[i]) + 127, t->table[i]);
		i += 1;
	}
}

// void table_set(t_table *t, char *key, union u_value value) {
// 	t_uint32 h = hash(key) % t->size;
	// t->table[h] = value;
	// t_uint64 i = 0;
	// while (i < t->size)
	// {
		// if (t->array[i] == &t->table[h])
		// 	printf("got a collision %s\n", key);
		// if (!t->array[i].ptr) {
		// 	printf("assigning t[%lu]: %lx\n", i, value.int64);
		// 	t->array[i] = value;
		// 	while(t->table[h])
		// 		h += 1;
		// 	t->table[h] = &t->array[i];
		// 	break ;
		// }
// 		i += 1;
// 	}
// }

// t_value *table_get(char *key)
// {
// 	printf("table_get %s");
// }

int main(void) {
	// debug_types();

	t_table *t = table(16);
	table_set(t, "arno", (t_value)1);
	table_set(t, "arnaud", (t_value)2);
	table_set(t, "arnault", (t_value)3);
	table_set(t, "tluanra", (t_value)4);
	table_set(t, "duanra", (t_value)5);
	table_set(t, "onra", (t_value)6);
	table_set(t, "sept", (t_value)7);

	t_uint8 huit = 8;
	table_set(t, "huit", (t_value)(void*)&huit);

	char s1[] = "neuf";
	table_set(t, "neuf", (t_value)(void*)s1);

	char *s2 = malloc(4);
	bzero(s2, 4);
	strcpy(s2, "dix");
	table_set(t, "dix", (t_value)(void*)s2);

	debug_table(t);
	return (0);
}
