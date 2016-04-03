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
