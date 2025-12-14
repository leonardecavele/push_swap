/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 18:32:55 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/14 16:46:48 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

#include "debug.h" // to remove

static int	ft_abs(int x) // utils
{
	return (x < 0 ? -x : x);
}

static int	min(int a, int b) // utils
{
	if (a < b)
		return (a);
	return (b);
}

static int	max(int a, int b) // utils
{
	if (a > b)
		return (a);
	return (b);
}









static void	get_target(t_stack *stack, t_node **target, int b_index)
{
	t_node	*a;
	int		min;

	min = INT_MAX;
	a = stack->a;
	while (a)
	{
		if (a->index < min)
		{
			min = a->index;
			*target = a;
		}
		a = a->next;
		if (a == stack->a)
			break ;
	}
	a = stack->a;
	while (a)
	{
		if (a->index > b_index && a->index < (*target)->index)
			*target = a;
		a = a->next;
		if (a == stack->a)
			break ;
	}
}

static int	target_rotation(t_node *stack, int size, int target_index)
{
	t_node	*current;
	int		r;

	r = 0;
	current = stack;
	while (current->index != target_index)
	{
		current = current->next;
		r++;
	}
	if (size - r > r)
		return (r);
	else
		return (0 - (size - r));
}

static int	alternative_score(int size, int *r, int r2, int score)
{
	int	tmp;
	int	alternative_score;

	tmp = *r;
	if (*r > 0)
		tmp -= size;
	else if (*r < 0)
		tmp += size;
	if ((tmp <= 0 && r2 <= 0) || (tmp >= 0 && r2 >= 0))
		alternative_score = (max(ft_abs(tmp), ft_abs(r2)) - min(ft_abs(tmp), ft_abs(r2)));
	else
		alternative_score = (ft_abs(tmp) + ft_abs(r2));
	if (alternative_score < score)
	{
		*r = tmp;
		return (alternative_score);
	}
	return (score);
}

static int	get_score(t_stack *stack, int b_index, int *rta, int *rtb)
{
	t_node	*target;
	int		score;

	get_target(stack, &target, b_index);
	*rta = target_rotation(stack->a, stack->size_a, target->index);
	*rtb = target_rotation(stack->b, stack->size_b, b_index);
	if ((*rta <= 0 && *rtb <= 0) || (*rta >= 0 && *rtb >= 0))
		score = (max(ft_abs(*rta), ft_abs(*rtb)) - min(ft_abs(*rta), ft_abs(*rtb)));
	else
		score = (ft_abs(*rta) + ft_abs(*rtb));
	score = alternative_score(stack->size_a, rta, *rtb, score);
	score = alternative_score(stack->size_b, rtb, *rta, score);
	return (score);
}

static void rotate(t_stack *stack, t_info *info, int rta, int rtb)
{
	if (rta > 0 && rtb > 0)
		while (rta-- > 0 && rtb-- > 0)
			rr(stack, info);
	if (rta < 0 && rtb < 0)
		while (rta++ < 0 && rtb++ < 0)
			rrr(stack, info);
	if (rta > 0)
		while (rta-- > 0)
			ra(stack, info);
	if (rta < 0)
		while (rta++ < 0)
			rra(stack, info);
	if (rtb > 0)
		while (rtb-- > 0)
			rb(stack, info);
	if (rtb < 0)
		while (rtb++ < 0)
			rrb(stack, info);
}

static void	target(t_stack *stack, int *rta, int *rtb)
{
	t_node	*current;
	int		score;
	int		min;

	min = INT_MAX;
	current = stack->b;
	while (current)
	{
		score = get_score(stack, current->index, rta, rtb);
		if (score < min)
			min = score;
		current = current->next;
		if (current == stack->b)
			break ;
	}
	get_score(stack, current->index, rta, rtb);
}

extern void	simple(t_stack *stack, t_info *info)
{
	int	n;
	int	rta;
	int	rtb;

	n = stack->size_a;
	while (n-- > 2)
	{
		pb(stack, info);
		if (stack->b->index <= stack->size / 2)
			rb(stack, info);
	}
	if (stack->a->index > stack->a->next->index)
		ra(stack, info);
	while (stack->size_b)
	{
		target(stack, &rta, &rtb);
		rotate(stack, info, rta, rtb);
		pa(stack, info);
		print_stack(stack);
	}
}
