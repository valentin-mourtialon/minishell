/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:02:44 by sel-maar          #+#    #+#             */
/*   Updated: 2023/01/27 15:16:19 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static void	init_tab_parser(int	(**tab)(t_lexer **, t_parser **,t_env **))
{
	//tab[2] = &pipe;
	//tab[3] = &assignement;
	tab[4] = &sep;
	tab[6] = &simplequote;
	//tab[7] = &doublequote;
	tab[8] = &word;
}

t_parser	*ft_parser(t_lexer **lexer, t_env **env)
{
	t_parser	*parser;
	t_parser	*index;
	int			(*functions[9])(t_lexer **, t_parser **, t_env **);	

	(void)env;
	parser = NULL;
	init_tab_parser(functions);
	while (*lexer)
	{
		index = newblock(B_SIMPLE, lexer);
		addbackblock(&parser, index);	
		while (*lexer)
		{
			/* enlever le pipe du pointeurs sur fonctions */
			if (!functions[(*lexer)->token](lexer, &parser, env))
				return (NULL);//erreur
		}
	}
	print_block(parser);
	return(parser);
}
