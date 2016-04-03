/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 16:24:09 by adebray           #+#    #+#             */
/*   Updated: 2016/04/03 16:36:26 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mods.h>

t_value			*value(int e, union u_value u)
{
	t_value *val;

	val = malloc(sizeof(t_value));
	ft_bzero(val, sizeof(t_value));
	val->e = e;
	val->u = u;
	return (val);
}

unsigned int	hash(unsigned int size, char *line)
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

char			*enum_to_string(int e)
{
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

#define PADD(size) while (i) { printf("  "); i -= 1; }

static void		print_value(t_value *v, int lvl)
{
	int		i;

	i = lvl;
	PADD(i);
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

void			table_debug(t_table *t)
{
	unsigned int	i;

	i = 0;
	while (i < t->size)
	{
		if (t->array[i])
			print_value(t->array[i], 0);
		i += 1;
	}
}
