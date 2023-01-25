/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:36:38 by vmourtia          #+#    #+#             */
/*   Updated: 2023/01/25 16:08:40 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

int	main(int ac, char **av, char **env)
{
	char		*cmd;
	char		*ptrstart;
	t_lexer		*lexer;
	t_parser	*parser;

	if (ac != 1)
		return (0);
	(void)av;
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
		print_token(lexer);
		printf("\n\n");
		parser = ft_parser(&lexer);
		freeblock(parser);
		free(ptrstart);
	}
	return (0);
}
