#include <libft.h>
#include <mods.h>

t_value	*value(int e, union u_value u)
{
	t_value *val = malloc(sizeof(t_value));
	ft_bzero(val, sizeof(t_value));

	val->e = e;
	val->u = u;
	return val;
}

unsigned int hash(unsigned int size, char *line)
{
	unsigned int	hashich;
	int				c;

	hashich = 5381;
	while ((c = *line++))
		hashich = ((hashich << 5) + hashich) ^ c;
	if (hashich > size)
		return (hashich % size);
	return (hashich);
}

t_value *assign(t_value **v, t_value *nv)
{
	if (*v) {
		if (!ft_strcmp((*v)->k, nv->k))
		{
			free(*v);
			*v = nv;
		}
		else if (!((*v)->n))
			(*v)->n = nv;
		else
			return assign(&((*v)->n), nv);
	}
	else {
		(*v) = nv;
	}
	return (*v);
}

t_value	*set(t_table *t, char *key, t_value *v)
{
	unsigned int h;

	h = hash(t->size, key);

	v->k = assign(&t->hash_array[h], value(STRING, (union u_value)(void *)key))->u.p;
	// ass
	// v->k = key;

	return (assign(&t->array[h], v));
}

t_value NILL = {
	.k = "nil",
	.u = {
		.p = NULL
	},
	.e = NIL,
	.n = NULL
};

t_value *solve_collision(t_value *v, char *key)
{
	if (!v)
		return (&NILL);
	else if (!ft_strcmp(v->k, key))
		return (v);
	else if (v->n)
		return (solve_collision(v->n, key));
	else
		return (&NILL);
}

t_value *get(t_table *t, char *key)
{
	unsigned int h;

	h = hash(t->size, key);
	return (solve_collision(t->array[h], key));
}

t_table	*init(int size)
{
	t_table *t;

	if (!(t = malloc(sizeof(t_table))))
		return (NULL);
	else if (!(t->array = malloc(sizeof(t_value *) * size)))
		return (NULL);
	else if (!(t->hash_array = malloc(sizeof(char *) * size)))
		return (NULL);

	t->size = size;
	int i = 0;
	while (i < size)
	{
		t->array[i] = NULL;
		t->hash_array[i] = NULL;
		i += 1;
	}
	// ft_bzero(t->array, sizeof(t_value) * size);
	return (t);
}
