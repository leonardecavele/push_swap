/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:28:01 by nlallema          #+#    #+#             */
/*   Updated: 2025/12/10 10:43:04 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

typedef struct s_printf
{
	va_list	param;
	int		n;
	int		current;
}			t_printf;

int		ft_printf(const char *s, ...) __attribute__((format(printf, 1, 2)));
void	print_stack(t_stack *stack);

#endif
