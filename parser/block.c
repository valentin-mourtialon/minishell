/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:35:03 by sel-maar          #+#    #+#             */
/*   Updated: 2023/01/24 15:43:59 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

t_parser	*newblock(int block, t_lexer **token)
{
	t_parser	*newblock;

	newblock = malloc(sizeof(t_parser *));
	if (newblock == NULL)
		return (NULL);
	newblock->block = block; //type de cmd (redirection cmd simple ect.....)
	newblock->nexttoken = *token;//ici les nouveau token "raffiner" exemple: QUOTE WORD SEP SEP WORD -> WORD
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

void	addbackblock(t_parser **block, t_parser *new)
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
	int i;

	i = 1;
	while (parser)
	{
		printf("block: %d	type: %d\n-----------------------\n", i, parser->block);
		print_token(parser->nexttoken);
		printf("-----------------------\n");
		parser = parser->nextblock;
		i++;
	}
}

void	cut_lexer(t_lexer **index)
{
	t_lexer *tmp;

	tmp = *index;
	(*index) = (*index)->previous;
	(*index)->next = NULL;
	*index = tmp;
	// sert a couper le lexer a la fin dune commande simple par exemple:
	// WORD WORD QUOTE SEP QUOTE PIPE WORD WORD END devient:
	// WORD WORD QUOTE SEP QUOTE END
	// PIPE WORD WORD END
}
