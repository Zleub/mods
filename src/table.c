/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 16:21:55 by adebray           #+#    #+#             */
/*   Updated: 2016/04/08 14:43:41 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mods.h>

t_value g_nill = {
	.k = "nil",
	.u = {
		.p = NULL
	},
	.e = NIL,
	.n = NULL
};

static t_value	*assign(t_value **v, t_value *nv)
{
	if (*v)
	{
		if (!ft_strcmp((*v)->k, nv->k))
		{
			nv->n = (*v)->n;
			free((*v)->k);
			free(*v);
			*v = nv;
		}
		else
			return (assign(&((*v)->n), nv));
	}
	else
		(*v) = nv;
	return (*v);
}

t_value			*table_set(t_table *t, char *key, t_value *v)
{
	unsigned int h;

	h = hash(t->size, key);
	v->k = ft_strdup(key);
	return (assign(&t->array[h], v));
}

static t_value	*solve_collision(t_value *v, char *key)
{
	if (!v)
		return (&g_nill);
	else if (!ft_strcmp(v->k, key))
		return (v);
	else if (v->n)
		return (solve_collision(v->n, key));
	else
		return (&g_nill);
}

t_value			*table_get(t_table *t, char *key)
{
	unsigned int h;

	h = hash(t->size, key);
	return (solve_collision(t->array[h], key));
}

t_table			*table_init(int size)
{
	int			i;
	t_table		*t;

	if (!(t = malloc(sizeof(t_table))))
		return (NULL);
	else if (!(t->array = malloc(sizeof(t_value *) * size)))
		return (NULL);
	t->size = size;
	i = 0;
	while (i < size)
	{
		t->array[i] = NULL;
		i += 1;
	}
	return (t);
}
