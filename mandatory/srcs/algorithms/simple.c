/* ************************************************************************** */
/*                                                                            */ /*                                                        :::      ::::::::   */ /*   simple.c                                           :+:      :+:    :+:   */ /*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:56:40 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/11 14:57:34 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

static void	target_min(t_stack *stack, t_node **target, bool *direction)
{
	t_node	*current;
	long	min;
	int		min_i;
	int		i;

	min = LONG_MAX;
	min_i = 0;
	i = 0;
	current = stack->a;
	while (current != stack->a || i == 0)
	{
		if ((long)current->value < min)
		{
			min_i = i;
			min = current->value;
			*target = current;
		}
		current = current->next;
		i++;
	}
	if (stack->size_a - min_i > min_i)
		*direction = RIGHT;
	else
		*direction = LEFT;
}

extern void	simple(t_stack *stack, t_info *info)
{
	t_node	*current;
	t_node	*target;
	bool	direction;

	current = stack->a;
	while (stack->size_a)
	{
		target_min(stack, &target, &direction);
		while (stack->a != target)
			if (direction == RIGHT)
				ra(stack, info);
			else if (direction == LEFT)
				rra(stack, info);
		pb(stack, info);
	}
	while (stack->b)
		pa(stack, info);
}
