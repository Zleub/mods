/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 18:32:47 by adebray           #+#    #+#             */
/*   Updated: 2016/04/23 19:29:15 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALUE_H
# define VALUE_H

# include <libft.h>
# include <ft_printf.h>
# include <stdio.h>

# define OUTFUNCTION printf
# define PADD(size) while (i) { OUTFUNCTION("  "); i -= 1; }

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

typedef struct s_value	t_value;

struct					s_value
{
	char				*k;
	union u_value		u;
	enum e_type			e;
	struct s_value		*n;
};

t_value					*value(int e, union u_value u);
void					value_debug(t_value *t, int lvl);
char					*enum_to_string(int e);

#endif
