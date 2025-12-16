/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:57:23 by nlallema          #+#    #+#             */
/*   Updated: 2025/12/16 13:49:38 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include <stdio.h>

void	print_stack(t_stack *stack)
{
	t_node	*a_current;
	t_node	*b_current;
	int		i;

	i = -1;
	a_current = stack->a;
	b_current = stack->b;
	dprintf(2, "+-----------------------+\n");
	dprintf(2, "|      a    |     b     |\n");
	dprintf(2, "+-----------------------+\n");
	while (++i < stack->size)
	{
		if (a_current && (a_current != stack->a || i == 0))
		{
			printf("|%7d, ", a_current->value);
			printf("%3d|", a_current->index);
			a_current = a_current->next;
		}
		else
			dprintf(2, "|%11s|", " ");
		if (b_current && (b_current != stack->b || i == 0))
		{
			printf("|%7d, ", b_current->value);
			printf("%3d|", b_current->index);
			b_current = b_current->next;
		}
		else
			dprintf(2, "%11s|", " ");
		dprintf(2, "\n");
	}
	dprintf(2, "+-----------------------+\n");
}
