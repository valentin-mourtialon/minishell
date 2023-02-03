/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:22:23 by sel-maar          #+#    #+#             */
/*   Updated: 2023/02/03 11:45:56 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

int 	ft_pipe(t_lexer **lexer)
{
	t_lexer *tmp;

	(*lexer)->previous->next = NULL;
	while (*lexer && ((*lexer)->token != T_QUOTE_DOUBLE
		&& (*lexer)->token != T_QUOTE_SIMPLE && (*lexer)->token != T_WORD
		&& (*lexer)->token != T_DOLLAR))
	{
		tmp = *lexer;
		*lexer = (*lexer)->next;
		deltoken(tmp);
	}
	if (!(*lexer) || (*lexer)->token == T_SUP || (*lexer)->token == T_INF)
		return (0);
	(*lexer)->previous = NULL;
	return (1);
}
