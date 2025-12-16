/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:50:38 by nlallema          #+#    #+#             */
/*   Updated: 2025/12/13 19:30:07 by nlallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "operations.h"

extern void	target_max(t_node *root, int size, t_node **target, bool *direction)
{
	long	max;
	int		stack_size;

	max = INT_MIN;
	stack_size = size;
	while (stack_size--)
	{
		if ((long)root->value > max)
		{
			if (size - stack_size <= size / 2)
				*direction = RIGHT;
			else
				*direction = LEFT;
			max = root->value;
			*target = root;
		}
		root = root->next;
	}
}

extern void	pusha_max(t_stack *stack, t_info *info)
{
	t_node	*max_node;
	bool	direction;

	target_max(stack->b, stack->size_b, &max_node, &direction);
	while (stack->b != max_node)
	{
		if (direction == RIGHT)
			rb(stack, info);
		else if (direction == LEFT)
			rrb(stack, info);
	}
	pa(stack, info);
}
