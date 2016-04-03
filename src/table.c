#include <mods.h>

t_value NILL = {
	.k = "nil",
	.u = {
		.p = NULL
	},
	.e = NIL,
	.n = NULL
};

static t_value *assign(t_value **v, t_value *nv)
{
	if (*v) {
		if (!ft_strcmp((*v)->k, nv->k))
		{
			nv->n = (*v)->n;
			free((*v)->k);
			free(*v);
			*v = nv;
		}
		else
			return assign(&((*v)->n), nv);
	}
	else
		(*v) = nv;
	return (*v);
}

t_value	*set(t_table *t, char *key, t_value *v)
{
	unsigned int h;

	h = hash(t->size, key);
	v->k = ft_strdup(key);
	return (assign(&t->array[h], v));
}

static t_value *solve_collision(t_value *v, char *key)
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

	t->size = size;
	int i = 0;
	while (i < size)
	{
		t->array[i] = NULL;
		i += 1;
	}
	return (t);
}
