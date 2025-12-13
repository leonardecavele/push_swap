/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:55:03 by nlallema          #+#    #+#             */
/*   Updated: 2025/12/13 18:02:45 by nlallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

extern int	list_get_min_greater_than(t_node *root, int size, int gt)
{
	int		min;

	min = INT_MAX;
	while (size--)
	{
		if (root->value < min && root->value > gt)
			min = root->value;
		root = root->next;
	}
	return (min);
}
