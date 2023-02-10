/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <sel-maar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:36:38 by vmourtia          #+#    #+#             */
/*   Updated: 2023/02/10 14:40:37 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include "builtin/builtin.h"

int	main(int ac, char **av, char **env)
{
	char		*cmd;
	char		*ptrstart;
	t_lexer		*lexer;
	t_parser	*parser;
	t_env		*listenv;

	if (ac != 1)
		return (0);
	(void)av;
	(void)env;
	listenv = NULL;
	signal(SIGINT, handle_sigquit);
	signal(SIGQUIT, SIG_IGN);
	copyenv(&listenv, env);
	while (1)
	{
		cmd = readline("lexer ");
		if (!cmd)
			break ;
		ptrstart = cmd;
		lexer = NULL;
		while (*cmd)
			get_next_token(&cmd, &lexer);
		print_token(lexer);

		printf("\n\n--------------------------\n\n");

		parser = ft_parser(&lexer, &listenv);
		if (parser)
		{
		print_block(parser);
//		echo(&parser);
		freeblock(parser);
		free(ptrstart);
		}
	}
	return (0);
}
