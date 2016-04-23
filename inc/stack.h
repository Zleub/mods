/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 18:31:51 by adebray           #+#    #+#             */
/*   Updated: 2016/04/23 19:30:28 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <libft.h>
# include <ft_printf.h>
# include <value.h>

typedef struct s_value	t_value;
typedef struct s_stack	t_stack;

struct s_stack
{
	t_value				*value;
	struct s_stack		*next;
};

struct s_stack		*stack_init(t_value *v);
void				stack_debug(t_stack *s);
struct s_stack		*stack_push(t_stack *s, t_value *v);
struct s_stack		*stack_pop(t_stack *s);

#endif
