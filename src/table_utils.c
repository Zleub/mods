/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 16:24:09 by adebray           #+#    #+#             */
/*   Updated: 2016/04/25 18:11:13 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <table.h>

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

void			table_debug(t_table *t)
{
	unsigned int	i;

	i = 0;
	while (i < t->size)
	{
		if (t->array[i])
			value_debug(t->array[i], 0);
		i += 1;
	}
}

void			table_iter(t_table *t, int (*f)())
{
	unsigned int i = 0;
	while (i < t->size)
	{
		if (t->array[i])
			call(t->array[i], f);
		i += 1;
	}
}
