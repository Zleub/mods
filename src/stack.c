/*
* @Author: Zleub
* @Date:   2016-04-23 18:31:39
* @Last Modified by:   Zleub
* @Last Modified time: 2016-04-23 19:30:14
*/

#include <stack.h>

t_stack		*stack_init(t_value *v)
{
	t_stack	*s;

	if (!(s = malloc(sizeof(t_stack))))
		return (0);
	ft_bzero(s, sizeof(t_stack));
	if (v)
		s->value = v;
	return (s);
}

t_stack		*stack_push(t_stack *s, t_value *v)
{
	t_stack *ns = stack_init(v);
	ns->next = s;
	return (ns);
}

t_stack		*stack_pop(t_stack *s)
{
	t_stack *ns = s->next;
	free(s);
	return (ns);
}

void		stack_debug(t_stack *s)
{
	if (s) {
		ft_printf("%p: ", s);
		value_debug(s->value, 0);
		stack_debug(s->next);
	}
}
