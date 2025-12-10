/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:11:51 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/10 10:22:57 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

typedef enum e_errcode
{
	ERR_AC,
}	t_errcode;

static void	handle_error(int errcode)
{
	exit(errcode);
}

static short	get_mode(char *s)
{
	if (!ft_strcmp(s, "--simple"))
		return (SIMPLE);
	else if (!ft_strcmp(s, "--medium"))
		return (MEDIUM);
	else if (!ft_strcmp(s, "--complex"))
		return (COMPLEX);
	else if (!ft_strcmp(s, "--adaptive"))
		return (ADAPTIVE);
	else if (!ft_strcmp(s, "--bench"))
		return (BENCH);
	return (0);
}

int	main(int ac, char **av)
{
	int		i;
	t_info	info;

	info = {0};
	if (ac < 2)
		handle_error(ERR_AC);
	i = 1;
	while (i < ac && i < 3)
		info.flags |= get_mode(av[i++])
	
}
