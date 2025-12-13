/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:01:27 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/13 17:01:15 by nlallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"
#include "debug.h" // to remove

static void	target_max(t_node *root, int size, t_node **target, bool *direction)
{
	long	max;
	int		stack_size;

	max = INT_MIN;
	stack_size = size;
	while (stack_size--)
	{
		if ((long)root->value > max)
		{
			if (size - stack_size < size / 2)
				*direction = RIGHT;
			else
				*direction = LEFT;
			max = root->value;
			*target = root;
		}
		root = root->next;
	}
}

static int	get_min_greater_than(t_node *root, int size, int gt)
{
	int		min;

	min = INT_MAX;
	while (size--)
	{
		if (root->value < min && root->value > gt)
			min = root->value;
		root = root->next;
	}
	return (min);
}

static void	next_bucket_range(t_stack *stack, int item_count, int *min, int *max)
{
	t_node	*current;
	int		value;

	if (stack->size == 0)
		return ;
	value = get_min_greater_than(stack->a, stack->size_a, INT_MIN);
	*min = value;
	current = stack->a;
	while (--item_count)
	{
		value = get_min_greater_than(stack->a, stack->size_a, value);
		current = current->next;
		if (current == stack->a)
			break;
	}
	*max = value;
}

static void	pushb_next_bucket(t_stack *stack, t_info *info, int item_per_bucket)
{
	int		range_min;
	int		range_max;
	int		stack_size;

	next_bucket_range(stack, item_per_bucket, &range_min, &range_max);
	stack_size = stack->size_a;
	while (stack_size--)
	{
		if (stack->a->value >= range_min && stack->a->value <= range_max)
			pb(stack, info);
		else
			ra(stack, info);
	}
}

static void	pusha_max(t_stack *stack, t_info *info)
{
	t_node	*max_node;
	bool	direction;

	target_max(stack->b, stack->size_b, &max_node, &direction);
	while (stack->b != max_node)
		if (direction == RIGHT)
			rb(stack, info);
		else if (direction == LEFT)
			rrb(stack, info);
	pa(stack, info);
}

extern void	medium(t_stack *stack, t_info *info)
{
	int		num_buckets;
	int		item_per_bucket;

	num_buckets = ft_approximate_sqrt(stack->size);
	item_per_bucket = ft_ceil((double)stack->size / num_buckets);
	while (num_buckets--)
		pushb_next_bucket(stack, info, item_per_bucket);
	while (stack->size_b)
		pusha_max(stack, info);
	print_stack(stack);
}
