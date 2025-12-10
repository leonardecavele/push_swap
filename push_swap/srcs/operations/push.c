/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:46:09 by nlallema          #+#    #+#             */
/*   Updated: 2025/12/10 10:47:47 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"
#include "operations.h"

void	pa(t_stack *stack)
{
	int	i;

	ft_printf("pa\n");
	if (stack->size_b == 0)
		return ;
	i = stack->size_a;
	while (--i >= 0)
		stack->a[i + 1] = stack->a[i];
	stack->a[0] = stack->b[0];
	stack->size_a++;
	i = -1;
	while (++i < stack->size_b)
		stack->b[i] = stack->b[i + 1];
	stack->size_b--;
}

void	pb(t_stack *stack)
{
	int	i;

	ft_printf("pb\n");
	if (stack->size_a == 0)
		return ;
	i = stack->size_b;
	while (--i >= 0)
		stack->b[i + 1] = stack->b[i];
	stack->b[0] = stack->a[0];
	stack->size_b++;
	i = -1;
	while (++i < stack->size_a)
		stack->a[i] = stack->a[i + 1];
	stack->size_a--;
}
