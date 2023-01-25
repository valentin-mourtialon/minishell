/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:02:44 by sel-maar          #+#    #+#             */
/*   Updated: 2023/01/25 14:04:33 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void	init_tab_parser(int	(**tab)(t_lexer **, t_parser **))
{
	//tab[2] = &pipe;
	tab[4] = &sep;
	tab[6] = &simplequote;
	//tab[7] = &doublequote;
	tab[8] = &word;
}

t_parser	*ft_parser(t_lexer **lexer)
{
	t_parser	*parser;
	t_parser	*index;
	int		(*functions[9])(t_lexer **, t_parser **);	

	parser = NULL;
	init_tab_parser(functions);
	while (*lexer)
	{
		index = newblock(B_SIMPLE, lexer);
		addbackblock(&parser, index);	
		while (*lexer)
		{
			if (!functions[(*lexer)->token](lexer, &parser))
				return (NULL);//erreur
		}
	}
	print_block(parser);
	return(parser);
}
