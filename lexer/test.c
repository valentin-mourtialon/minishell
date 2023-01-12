/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:36:38 by vmourtia          #+#    #+#             */
/*   Updated: 2023/01/12 16:39:43 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

int	main()
{
	char	*cmd;
	char	*ptrstart;
	
	cmd = readline("lexer ");
	ptrstart = cmd;
	while (*cmd)
		get_next_token(&cmd);
	free(ptrstart);
	return (0);
}
