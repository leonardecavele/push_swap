/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 21:09:29 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/13 17:58:36 by nlallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include <stddef.h>
# include <stdbool.h>
# include <limits.h>
# include "push_swap.h"

typedef struct s_dprintf
{
	va_list	param;
	int		n;
	int		current;
}			t_dprintf;

int		ft_approximate_sqrt(int value);
int		ft_ceil(double value);
int		ft_dprintf(int fd, const char *s, ...);
long	ft_atol(const char *s);
bool	ft_isdigit(int c);
bool	ft_issign(int c);
bool	ft_isspace(int c);
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_memset(void *s, int c, size_t n);

void	target_max(t_node *root, int size, t_node **target, bool *direction);
void	pusha_max(t_stack *stack, t_info *info);
#endif
