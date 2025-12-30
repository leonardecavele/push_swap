/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:01:27 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/30 22:26:06 by nlallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

static void	apply_rot_step(t_stack *stack, t_info *info, int bi, int nb, int rt)
{
	t_node	*target;

	target = get_node_at(stack->a, rt);
	if (stack->size_b > 1 && target->index > stack->b->index \
&& stack->b->index < stack->b->next->index \
&& stack->b->next->index / nb == bi)
		rr(stack, info);
	else if (stack->size_b > 1 && target->index < stack->b->next->index \
&& stack->b->index < stack->b->previous->index \
&& stack->b->next->index / nb == bi)
		rr(stack, info);
	else
		ra(stack, info);
}

static void	pushb_bucket(t_stack *stack, t_info *info, int bi, int nb)
{
	int		rt;

	while (stack->size_a)
	{
		rt = target_bucket(stack->a, stack->size_a, bi, nb);
		if (rt == INT_MAX)
			break ;
		else if (rt > 0)
			apply_rot_step(stack, info, bi, nb, rt);
		else if (rt < 0)
			rra(stack, info);
		else
			pb(stack, info);
	}
}

extern void	medium(t_stack *stack, t_info *info)
{
	int	num_buckets;
	int	current_bucket;

	num_buckets = stack->size / ((double)approximate_sqrt(stack->size) * 1.8);
	if (num_buckets == 0)
		num_buckets = 1;
	current_bucket = -1;
	while (++current_bucket <= num_buckets)
		pushb_bucket(stack, info, current_bucket, stack->size / num_buckets);
	while (stack->size_b)
		pusha_max(stack, info);
}
