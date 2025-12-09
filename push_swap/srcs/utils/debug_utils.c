/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:57:23 by nlallema          #+#    #+#             */
/*   Updated: 2025/12/09 19:28:22 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *stack)
{
	int	i;

	i = -1;
	printf("+-----------------------+\n");
	printf("|      a    |     b     |\n");
	printf("+-----------------------+\n");
	while (++i < stack->capacity)
	{
		if (i < stack->size_a)
			printf("|%11d|", stack->a[i]);
		else
			printf("|%11s|", " ");
		if (i < stack->size_b)
			printf("%11d|", stack->b[i]);
		else
			printf("%11s|", " ");
		printf("\n");
	}
	printf("+-----------------------+\n");
}
