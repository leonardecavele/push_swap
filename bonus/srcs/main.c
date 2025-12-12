/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:17:19 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/12 14:17:21 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parser.h"
#include "utils.h"

int	main(int ac, char **av)
{
	t_info	info;
	t_stack	stack;

	parse(ac, av, &info, &stack);

	list_clear(&stack.a);
	list_clear(&stack.b);
	return (0);
}
