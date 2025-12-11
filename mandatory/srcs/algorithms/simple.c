/* ************************************************************************** */
/*                                                                            */ /*                                                        :::      ::::::::   */ /*   simple.c                                           :+:      :+:    :+:   */ /*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:56:40 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/11 14:57:34 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

#include "debug.h" // to remove
#include <limits.h> // to remove

#define LEFT	0
#define RIGHT	1

static void	target_min(t_node *stack_a, int size_a, t_node **target, bool *direction)
{
	t_node	*current;
	long	min;
	int		i;
	int		min_index;

	min = (long)INT_MAX + 1;
	min_index = 0;
	i = 0;
	current = stack_a;
	while (current)
	{
		if ((long)current->value < min)
		{
			min_index = i;
			min = current->value;
			*target = current;
		}
		current = current->next;
		i++;
		if (current == stack_a)
			break ;
	}
	if (size_a - min_index > min_index)
		*direction = RIGHT;
	else
		*direction = LEFT;
}

//static void	target_max(t_node *stack_a, int size_a, t_node **target, bool *direction)
//{
//	t_node	*current;
//	int		max;
//	int		i;
//	int		max_index;
//
//	max = 0;
//	max_index = 0;
//	i = 0;
//	current = stack_a;
//	while (current)
//	{
//		if (current->value > max)
//		{
//			max_index = i;
//			max = current->value;
//			*target = current;
//		}
//		current = current->next;
//		i++;
//		if (current == stack_a)
//			break ;
//	}
//	if (size_a - max_index > max_index)
//		*direction = RIGHT;
//	else
//		*direction = LEFT;
//}

extern void	simple(t_stack *stack, t_info *info)
{
	t_node	*current;
	t_node	*target;
	bool	direction;

	current = stack->a;
	int	i = 0;
	while (stack->size_a)
	{
		target_min(stack->a, stack->size_a, &target, &direction);
		while (stack->a != target)
			if (direction == RIGHT)
				ra(stack, info);
			else if (direction == LEFT)
				rra(stack, info);
		pb(stack, info);
		i++;
		if (!stack->size_a)
			break ;
		i++;
	}
	while (stack->b)
		pa(stack, info);
}
