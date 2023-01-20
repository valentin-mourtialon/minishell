/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:36:38 by vmourtia          #+#    #+#             */
/*   Updated: 2023/01/19 15:08:38 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

int	main(void)
{
	char	*cmd;
	char	*ptrstart;
	t_lexer	*lexer;

	signal(SIGINT, handle_sigquit);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		cmd = readline("lexer ");
		if (!cmd)
			break ;
		ptrstart = cmd;
		lexer = NULL;
		while (*cmd)
			get_next_token(&cmd, &lexer);
		free(ptrstart);
		print_token(lexer);
	}
	return (0);
}
