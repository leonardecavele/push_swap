/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:57:23 by nlallema          #+#    #+#             */
/*   Updated: 2025/12/10 10:52:16 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

void	print_stack(t_stack *stack)
{
	int	i;

	i = -1;
	ft_printf("+-----------------------+\n");
	ft_printf("|      a    |     b     |\n");
	ft_printf("+-----------------------+\n");
	while (++i < stack->capacity)
	{
		if (i < stack->size_a)
			ft_printf("|%11d|", stack->a[i]);
		else
			ft_printf("|%11s|", " ");
		if (i < stack->size_b)
			ft_printf("%11d|", stack->b[i]);
		else
			ft_printf("%11s|", " ");
		ft_printf("\n");
	}
	ft_printf("+-----------------------+\n");
}
