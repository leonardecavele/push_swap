/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:49:17 by nlallema          #+#    #+#             */
/*   Updated: 2025/12/16 21:45:53 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

static void	push_to_a(t_stack *stack, t_info *info, int bit)
{
	int	stack_size;

	stack_size = stack->size_b;
	while (stack_size-- && stack->size_b && stack->size_a)
	{
		if (stack->b->index & bit)
			pa(stack, info);
		else
			rb(stack, info);
	}
}

static void	push_to_b(t_stack *stack, t_info *info, int bit)
{
	int	stack_size;

	stack_size = stack->size_a;
	while (stack_size-- && stack->size_a)
	{
		if (!(stack->a->index & bit))
			pb(stack, info);
		else
			ra(stack, info);
	}
}

extern void	complex(t_stack *stack, t_info *info)
{
	int	bit;
	int	tmp;

	tmp = 0;
	bit = 0x1;
	while (bit && stack->size_a && tmp != stack->size_a)
	{
		push_to_b(stack, info, bit);
		bit <<= 1;
		tmp = stack->size_a;
		push_to_a(stack, info, bit);
	}
	while (stack->size_b)
		pa(stack, info);
}
