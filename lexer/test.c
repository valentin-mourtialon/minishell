/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:36:38 by vmourtia          #+#    #+#             */
/*   Updated: 2023/01/11 16:07:56 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	main(int ac, char **av)
{
	char	*cmd;

	if (ac == 2)
	{
		cmd = av[1];
		while (*cmd)
		{
			while (is_separator(*cmd))
				cmd++;
			//if (is_special(*cmd))
				//hubspecial(&cmd);
			//printf("%s\n", retrieve_element(&cmd));
			get_next_token(&cmd);
		}
	}
	return (0);
}
