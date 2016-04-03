#ifndef TABLE_H
# define TABLE_H

#include <libft.h>

enum e_type {
	NIL,
	DOUBLE,
	FLOAT,
	STRING,
	POINTER
};

union u_value {
	double	d;
	float	f;
	void	*p;
};

struct s_value {
	char			*k;
	union u_value	u;
	enum e_type		e;
	struct s_value	*n;
};

struct s_table {
	unsigned int	size;
	struct s_value	**array;
};

typedef struct s_value t_value;
typedef struct s_table t_table;

unsigned int	hash(unsigned int size, char *line);
t_table			*table_init(int size);
t_value			*table_set(t_table *t, char *key, t_value *v);
t_value 		*table_get(t_table *t, char *key);
t_value			*table_value(int e, union u_value u);


#endif
