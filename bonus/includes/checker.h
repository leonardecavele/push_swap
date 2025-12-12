/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:24:46 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/12 17:58:56 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>

# define BUFFER_SIZE	4

typedef void (*t_operation)(t_stack *, t_info *);

typedef enum e_errcode
{
	NOERR = 1,
	ERR_INSTRUCTION = 2,
	ERR_ALLOC = 3,
}	t_errcode;

#endif
