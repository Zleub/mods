/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 18:36:48 by adebray           #+#    #+#             */
/*   Updated: 2016/04/23 19:22:19 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <value.h>

t_value			*value(int e, union u_value u)
{
	t_value *val;

	val = malloc(sizeof(t_value));
	ft_bzero(val, sizeof(t_value));
	val->e = e;
	val->u = u;
	return (val);
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

void			value_debug(t_value *v, int lvl)
{
	int		i;

	i = lvl;
	PADD(i);
	OUTFUNCTION("%s, %s -> ", v->k, enum_to_string(v->e));
	if (v->e == DOUBLE)
		OUTFUNCTION("%f", v->u.d);
	else if (v->e == FLOAT)
		OUTFUNCTION("%f", v->u.f);
	else if (v->e == POINTER)
		OUTFUNCTION("%p", v->u.p);
	else if (v->e == STRING)
		OUTFUNCTION("%s", v->u.p);
	OUTFUNCTION("\n");
	if (v->n)
		value_debug(v->n, lvl + 1);
}
