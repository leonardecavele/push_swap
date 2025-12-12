/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:01:27 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/12 19:06:31 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"
#include "debug.h" // to remove

static int	ft_approximate_sqrt(int value)
{
	long long	n;

	n = 1;
	while (n * n < value)
		n = n << 1;
	while (n * n > value)
		n--;
	return (n);
}

static void	target_max(t_stack *stack, t_node **target, bool *direction)
{
	t_node	*current;
	long	max;
	int		target_index;
	int		index;

	max = LONG_MIN;
	target_index = 0;
	index = 0;
	current = stack->b;
	while (current != stack->b || index == 0)
	{
		if ((long)current->value > max)
		{
			target_index = index;
			max = current->value;
			*target = current;
		}
		current = current->next;
		index++;
	}
	if (stack->size_b - target_index > target_index)
		*direction = RIGHT;
	else
		*direction = LEFT;
}

//static void	target_value(t_stack *stack, int value, t_node **target, bool *dir)
//{
//	t_node	*current;
//	int		target_index;
//
//	target_index = 0;
//	current = stack->a;
//	*target = NULL;
//	while (current != stack->a || target_index == 0)
//	{
//		if ((long)current->value == value)
//		{
//			*target = current;
//			break ;
//		}
//		current = current->next;
//		target_index++;
//	}
//	if (stack->size_a - target_index > target_index)
//		*dir = RIGHT;
//	else
//		*dir = LEFT;
//}

static int	find_min(t_stack *stack, int gt)
{
	t_node	*current;
	int		min;

	min = INT_MAX;
	current = stack->a;
	while (true)
	{
		if (current->value < min && current->value > gt)
			min = current->value;
		current = current->next;
		if (current == stack->a)
			break;
	}
	return (min);
}

static void	find_minmax(t_stack *stack, t_node **min_node, t_node **max_node)
{
	t_node	*current;

	if (stack->size == 0)
		return ;
	current = stack->a;
	while (true)
	{
		if (*max_node == NULL || current->value > (*max_node)->value)
			*max_node = current;
		if (*min_node == NULL || current->value < (*min_node)->value)
			*min_node = current;
		current = current->next;
		if (current == stack->a)
			break;
	}
}

static void	next_bucket_range(t_stack *stack, int item_count, int *min, int *max)
{
	t_node	*current;
	int		count;
	int		last_min;

	if (stack->size == 0)
		return ;
	*min = find_min(stack, INT_MIN);
	last_min = *min;
	current = stack->a;
	count = 1;
	while (count < item_count)
	{
		last_min = find_min(stack, last_min);
		count++;
		current = current->next;
		if (current == stack->a)
			break;
	}
	*max = last_min;
}

typedef struct	s_bucket_iterator
{
	int	index;
}				t_bucket_iterator;

typedef struct	s_buckets
{
	t_bucket_iterator	iterator;
	int					count;
	int					item_per_bucket;
}				t_buckets;


extern void	medium(t_stack *stack, t_info *info)
{
	t_node		*min_node;
	t_node		*max_node;
	t_buckets	buckets;

	(void)info;
	buckets = (t_buckets){0};
	min_node = NULL;
	max_node = NULL;
	find_minmax(stack, &min_node, &max_node);
	__builtin_printf("[stack] min: %d\n", min_node->value);
	__builtin_printf("[stack] max: %d\n", max_node->value);
	
	buckets.count = ft_approximate_sqrt(stack->size);
	buckets.item_per_bucket = stack->size / buckets.count;
	if (buckets.item_per_bucket * buckets.count < stack->size)
		buckets.item_per_bucket++;

	__builtin_printf("[bucket] count: %d\n", buckets.count);
	__builtin_printf("[bucket] item per bucket: %d\n", buckets.item_per_bucket);
	
	print_stack(stack);
	int	index = 0;
	while (index < buckets.count)
	{
		int range_min;
		int range_max;
		next_bucket_range(stack, buckets.item_per_bucket, &range_min, &range_max);
		__builtin_printf("[bucket] current range: [%d; %d]\n", range_min, range_max);
		t_node *last = stack->a->previous;
		while (true)
		{
			if (stack->a->value >= range_min && stack->a->value <= range_max)
				pb(stack, info);
			else
				ra(stack, info);
			if (stack->a == last || !stack->size_a)
			{
				if (stack->a->value >= range_min && stack->a->value <= range_max)
					pb(stack, info);
				else
					ra(stack, info);
				break ;
			}
		}
		index++;
	}
	print_stack(stack);
	while (stack->size_b)
	{
		bool	direction;
		target_max(stack, &max_node, &direction);
		while (stack->b != max_node)
			if (direction == RIGHT)
				rb(stack, info);
			else if (direction == LEFT)
				rrb(stack, info);
		pa(stack, info);
	}
	print_stack(stack);
}
