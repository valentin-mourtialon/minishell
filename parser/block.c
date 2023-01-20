/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:35:03 by sel-maar          #+#    #+#             */
/*   Updated: 2023/01/20 11:46:41 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

t_parser	*newblock(int block, t_lexer *token)
{
	t_parser	*newblock;

	newblock = malloc(sizeof(t_parser *));
	if (newblock == NULL)
		return (NULL);
	newblock->block = block; //type de cmd (redirection cmd simple ect.....)
	newblock->nexttoken = token;i//ici les nouveau token "raffiner" exemple: QUOTE WORD SEP SEP WORD -> WORD
	newblock->nextblock = NULL; //le block suivant
	return (newblock);
}

t_parser	*ft_parserlast(t_parser *block)
{
	if (!block)
		return (NULL);
	while (block->nextblock)
		block = block->nextblock;
	return (block);
}

void	addback(t_parser **block, t_parser *new)
{
	if (block)
	{
		if (*block)
			(*ft_parserlast(*block)).nextblock = new;
		else
			*block = new;
	}
}

void	print_block(t_parser *parser)
{
	while (parser)
	{
		printf("%d\t%s\n", parser->block, parser->str);
		parser = parser->nextblock;
	}
}

void	cut_lexer(t_lexer *lexer)
{
	lexer->next = NULL; 
	// sert a couper le lexer a la fin dune commande simple par exemple:
	// WORD WORD QUOTE SEP QUOTE PIPE WORD WORD END devient:
	// WORD WORD QUOTE SEP QUOTE END
	// PIPE WORD WORD END
}
