/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_approximate_sqrt.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:16:54 by nlallema          #+#    #+#             */
/*   Updated: 2025/12/12 19:17:16 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

extern int	ft_approximate_sqrt(int value)
{
	long long	n;

	n = 1;
	while (n * n < value)
		n = n << 1;
	while (n * n > value)
		n--;
	return (n);
}
