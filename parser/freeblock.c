/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeblock.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:48:32 by sel-maar          #+#    #+#             */
/*   Updated: 2023/01/27 14:54:36 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void	freeblock(t_parser *parser)
{
		t_parser	*tmp;

		while(parser)
		{
			tmp = parser;
			freelexer(&tmp->nexttoken);
			parser = parser->nextblock;
			free(tmp);
		}
}
