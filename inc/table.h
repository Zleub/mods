/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 16:24:37 by adebray           #+#    #+#             */
/*   Updated: 2016/04/23 19:16:07 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_H
# define TABLE_H

# include <libft.h>
# include <ft_printf.h>
# include <value.h>

typedef struct s_value	t_value;
typedef struct s_table	t_table;

struct					s_table
{
	unsigned int		size;
	struct s_value		**array;
};

t_value					*value(int e, union u_value u);

unsigned int			hash(unsigned int size, char *line);

t_table					*table_init(int size);
t_value					*table_set(t_table *t, char *key, t_value *v);
t_value					*table_get(t_table *t, char *key);

void					table_debug(t_table *t);

#endif
