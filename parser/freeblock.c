/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeblock.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:48:32 by sel-maar          #+#    #+#             */
/*   Updated: 2023/01/25 14:17:40 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void	freeblock(t_parser *parser)
{
	t_parser	*tmpparser;
	t_lexer		*indexlexer;
	t_lexer		*tmplexer;
	while (parser)
	{
		tmpparser = parser;
		indexlexer = tmpparser->nexttoken;
		while (indexlexer)
		{
			tmplexer = indexlexer;
			indexlexer = indexlexer->next;
			free(tmplexer->str);
			free(tmplexer);
		}
		parser = parser->nextblock;
		free(tmpparser);
	}
}
