/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium-helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:58:34 by nlallema          #+#    #+#             */
/*   Updated: 2025/12/30 22:22:11 by nlallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

static int	target_max(t_node *root, int sz)
{
	int	max;
	int	index;
	int	distance;

	if (!sz)
		return (0);
	index = -1;
	max = INT_MIN;
	while (++index < sz)
	{
		if (root->value > max)
		{
			if (index <= sz / 2)
				distance = index;
			else
				distance = -(sz - index);
			max = root->value;
		}
		root = root->next;
	}
	return (distance);
}

extern int	target_bucket(t_node *root, int sz, int bi, int nb)
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

extern void	pusha_max(t_stack *stack, t_info *info)
{
	int		rt;

	rt = target_max(stack->b, stack->size_b);
	while (rt)
	{
		if (rt > 0)
		{
			if (rt == 1 && stack->b->index < stack->b->next->index)
			{
				sb(stack, info);
				break ;
			}
			rb(stack, info);
			rt--;
		}
		else
		{
			rrb(stack, info);
			rt++;
		}
	}
	pa(stack, info);
}

extern t_node	*get_node_at(t_node *root, int distance)
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
