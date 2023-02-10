/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <sel-maar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:02:44 by sel-maar          #+#    #+#             */
/*   Updated: 2023/02/08 12:31:52 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static void	init_tab_parser(int	(**tab)(t_lexer **, t_parser **,t_env **))
{
	tab[0] = &inf;
	tab[1] = &sup;
	tab[2] = NULL;
	tab[3] = &assignement;
	tab[4] = &sep;
	tab[5] = &dollar;
	tab[6] = &simplequote;
	tab[7] = &doublequote;
	tab[8] = &word;
}

t_parser	*ft_parser(t_lexer **lexer, t_env **env)
{
	t_parser	*parser;
	t_parser	*index;
	int			(*functions[8])(t_lexer **, t_parser **, t_env **);	

	parser = NULL;
	init_tab_parser(functions);
	while (*lexer)
	{
		index = newblock(B_CMD, lexer);
		addbackblock(&parser, index);
		while (*lexer)
		{
			if ((*lexer)->token == T_PIPE)
			{
				if (!ft_pipe(lexer))
					return (NULL);
				break;
			}
			else if (!functions[(*lexer)->token](lexer, &index, env))
				return (NULL);//erreur
		}
	}
	return(parser);
}
