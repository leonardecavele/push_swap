/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:56:40 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/11 14:57:34 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

#include "debug.h" // to remove

#define LEFT	0
#define RIGHT	1

static void	target_max(t_node *stack_a, int size_a, t_node **target, bool *direction)
{
	t_node	*current;
	int		max;
	int		i;

	max = 0;
	i = 0;
	current = stack->a;
	while (current)
	{
		if (current->value > max)
			*target_max = current;
		current = current->next;
		i++;
		if (current == stack->a)
			break ;
	}
	if (size_a - i > i)
		*direction = RIGHT;
	*direction = LEFT;
}

extern void	simple(t_stack *stack, t_info *info)
{
	t_node	*current;
	t_node	*target;
	t_node	*start;
	t_node	*end;
	bool	direction;

	current = stack->a;
	print_stack(stack);
	int	i = 0;
	while (i < 10)
	{
		target_max(stack->a, stack->size_a, &target, &direction);
		while (stack->a != target)
			if (direction == RIGHT)
				ra(stack);
			else
				rra(stack);
		i++;
		print_stack(stack);

		if (i < 10)
			break ;
		target_min(stack->a, stack->size_a, &target, &direction);
		while (stack->a != target)
			if (direction == RIGHT)
				ra(stack);
			else
				rra(stack);
		i++;
		print_stack(stack);
	}
	(void)info;
}
