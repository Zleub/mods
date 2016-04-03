/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 16:24:37 by adebray           #+#    #+#             */
/*   Updated: 2016/04/03 16:42:39 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_H
# define TABLE_H

# include <libft.h>

enum	e_type
{
	NIL,
	DOUBLE,
	FLOAT,
	STRING,
	POINTER
};

union					u_value
{
	double				d;
	float				f;
	void				*p;
};

struct					s_value
{
	char				*k;
	union u_value		u;
	enum e_type			e;
	struct s_value		*n;
};

struct					s_table
{
	unsigned int		size;
	struct s_value		**array;
};

typedef struct s_value	t_value;
typedef struct s_table	t_table;

t_value					*value(int e, union u_value u);

unsigned int			hash(unsigned int size, char *line);
char					*enum_to_string(int e);

t_table					*table_init(int size);
t_value					*table_set(t_table *t, char *key, t_value *v);
t_value					*table_get(t_table *t, char *key);
t_value					*table_value(int e, union u_value u);

void					table_debug(t_table *t);

#endif
