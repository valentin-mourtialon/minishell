/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sep.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:31:05 by sel-maar          #+#    #+#             */
/*   Updated: 2023/02/10 13:56:58 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

int	sep(t_lexer **lexer, t_parser **parser, t_env **env)
{
	t_lexer	*tmp;
	t_lexer *start;
	(void)env;
	if ((*lexer)->next && (*lexer)->next->token == T_SEP)
	{
		if ((*lexer)->previous)
		{
			(*lexer)->previous->next = (*lexer)->next;
			start = (*lexer)->previous;
		}
		else
		{
			(*parser)->nexttoken = (*lexer)->next;
			start = NULL;
		}
		tmp = *lexer;
		*lexer = (*lexer)->next;
		if (*lexer)
			(*lexer)->previous = start;
		deltoken(tmp);
	}
	else
		*lexer = (*lexer)->next;
	return (1);
}
