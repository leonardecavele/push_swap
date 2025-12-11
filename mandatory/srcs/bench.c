/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:34:04 by nlallema          #+#    #+#             */
/*   Updated: 2025/12/11 11:54:21 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"

static void	_print_disorder(t_info info)
{
	double	disorder;
	int		decimal;

	disorder = 100. - (info.disorder * 100.);
	decimal = (int)((disorder - (int)disorder) * 100);
	ft_dprintf(2, "[bench] disorder: %d.", (int)disorder);
	if (decimal < 10)
		ft_dprintf(2, "0");
	ft_dprintf(2, "%d%%\n", decimal);
}

static void	_print_strategy(t_info info)
{
	ft_dprintf(2, "[bench] strategy: ");
	if (info.flags & ADAPTIVE && info.flags & SIMPLE)
		ft_dprintf(2, "Adaptive / O(n²)");
	else if (info.flags & ADAPTIVE && info.flags & MEDIUM)
		ft_dprintf(2, "Adaptive / O(n√n)");
	else if (info.flags & ADAPTIVE && info.flags & COMPLEX)
		ft_dprintf(2, "Adaptive / O(n log n)");
	else if (info.flags & SIMPLE)
		ft_dprintf(2, "Simple / O(n²)");
	else if (info.flags & MEDIUM)
		ft_dprintf(2, "Medium / O(n√n)");
	else if (info.flags & COMPLEX)
		ft_dprintf(2, "Complex / O(n log n)");
	ft_dprintf(2, "\n");
}

extern void	bench(t_stack stack, t_info info)
{
	(void)stack;
	_print_disorder(info);
	_print_strategy(info);
	ft_dprintf(2, "[bench] total_ops: == ?? ==\n");
	ft_dprintf(2, "[bench] == list op counter part 1 ==\n");
	ft_dprintf(2, "[bench] == list op counter part 2 ==\n");
}
