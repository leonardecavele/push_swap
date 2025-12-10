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

typedef enum e_errcode
{
	ERR_USAGE,
}	t_errcode;

void	handle_error(int errcode)
{
	exit(errcode);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		handle_error(ERR_USAGE);
		//error
	
}
