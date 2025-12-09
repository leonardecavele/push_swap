/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:46:09 by nlallema          #+#    #+#             */
/*   Updated: 2025/12/09 20:24:55 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operations.h"

void	pa(t_stack *stack)
{
	int	i;

	printf("pa\n");
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
