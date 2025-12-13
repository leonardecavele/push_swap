/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:07:54 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/13 18:02:37 by nlallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	struct s_node	*previous;
	struct s_node	*next;
	int				value;
}					t_node;

void	list_push_front(t_node *node, t_node **root);
void	list_push_back(t_node *node, t_node **root);
short	list_push_back_new(int value, t_node **root);
t_node	*list_pop(t_node **node);
void	list_clear(t_node **root);

int		list_get_min_greater_than(t_node *root, int size, int gt);

#endif
