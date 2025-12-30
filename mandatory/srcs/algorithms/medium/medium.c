/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:01:27 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/30 17:51:25 by nlallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

static int	get_rotations_to_bucket(t_node *root, int sz, int bi, int nb)
{
	int	index;
	int	distance;

	index = -1;
	distance = INT_MAX;
	while (++index < sz)
	{
		if (root->index / nb == bi)
		{
			if (index <= sz / 2 && distance > index)
					distance = index;
			else if (index > sz / 2 && ft_abs(distance) > sz - index)
				distance = -(sz - index);
		}
		root = root->next;
	}
	return (distance);
}

static t_node	*get_node_at(t_node *root, int distance)
{
	while (distance > 0)
	{
		root = root->next;
		distance--;
	}
	while (distance < 0)
	{
		root = root->previous;
		distance++;
	}
	return (root);
}

static void	pushb_next_bucket(t_stack *stack, t_info *info, int bi, int nb)
{
	t_node	*target;
	int		rt;

	while (stack->size_a)
	{
		rt = get_rotations_to_bucket(stack->a, stack->size_a, bi, nb);
		if (rt == INT_MAX)
			break ;
		target = get_node_at(stack->a, rt);
		while (rt > 0)
		{
			
			if (stack->size_b > 1
					&& stack->b->index < stack->b->next->index
					&& stack->b->next->index / nb == bi)
			{
				ss(stack, info);
				if (rt > 1 && stack->size_b > 1 && target->index < stack->b->index
					&& stack->b->next->index / nb == bi)
					rr(stack, info);
				else if (rt > 1)
					ra(stack, info);
			}
			else if (stack->size_b > 1 && target->index < stack->b->index
					&& stack->b->next->index / nb == bi)
				rr(stack, info);
			else
				ra(stack, info);
			rt--;
		}
		while (rt < 0)
		{
			
			if (stack->size_b > 1
					&& stack->b->index < stack->b->next->index
					&& stack->b->next->index / nb == bi)
			{
				if (stack->a->index < stack->a->next->index)
					ss(stack,  info);
				else
					sb(stack, info);
				if (stack->size_b > 1 && target->index > stack->b->previous->index
					&& stack->b->previous->index / nb == bi)
					rrr(stack, info);
				else
					rra(stack, info);
			}
			else if (stack->size_b > 1 && target->index > stack->b->previous->index
					&& stack->b->previous->index / nb == bi)
				rrr(stack, info);
			else
				rra(stack, info);
			rt++;
		}
		pb(stack, info);
	}
}

extern void	medium(t_stack *stack, t_info *info)
{
	int	num_buckets;
	int	current_bucket;

	num_buckets = stack->size / ((double)approximate_sqrt(stack->size) * 1.8);
	current_bucket = -1;
	while (++current_bucket <= num_buckets)
		pushb_next_bucket(stack, info, current_bucket, stack->size / num_buckets);
	while (stack->size_b)
		pusha_max(stack, info);
}
