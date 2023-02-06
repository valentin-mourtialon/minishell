/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <sel-maar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:22:23 by sel-maar          #+#    #+#             */
/*   Updated: 2023/02/06 16:02:44 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

int 	ft_pipe(t_lexer **lexer)
{
	t_lexer *tmp;

	if (!(*lexer)->previous || !(*lexer)->next)
		return (write(1, "pipe on end of line\n", 19),0);
	(*lexer)->previous->next = NULL;
	while (*lexer && ((*lexer)->token != T_QUOTE_DOUBLE
		&& (*lexer)->token != T_QUOTE_SIMPLE && (*lexer)->token != T_WORD
		&& (*lexer)->token != T_DOLLAR))
	{
		//if ((*lexer)->token == T_SUP || (*lexer)->token == T_INF || (*lexer)->token == T_PIPE)
		//	return (0);
		tmp = *lexer;
		*lexer = (*lexer)->next;
		deltoken(tmp);
	}
	if (!(*lexer))
		return (0);
	(*lexer)->previous = NULL;
	return (1);
}
