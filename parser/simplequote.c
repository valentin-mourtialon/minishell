/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplequote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:15:15 by sel-maar          #+#    #+#             */
/*   Updated: 2023/01/27 15:13:03 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static void	deltoken(t_lexer *token)
{
	free(token->str);
	free(token);
}

int	replacequote(t_lexer **start, t_lexer **lexer, t_parser **parser, char *cmd)
{
	t_lexer *token;
	t_lexer	*tmp;

	token = newtoken(T_WORD, cmd);
	if ((*start)->previous)
		(*start)->previous->next = token;
	else
		(*parser)->nexttoken = token;
	deltoken(*start);
	token->next = ((*lexer)->next);
	if ((*lexer)->next)
		(*lexer)->next->previous = token;
	tmp = *lexer;
	*lexer = (*lexer)->next;
	deltoken(tmp);
	return (1);
}

int	simplequote(t_lexer **lexer, t_parser **parser, t_env **env)
{
	t_lexer	*start;
	t_lexer	*tmp;
	char	*result;

	(void)env;
	start = *lexer;
	result = NULL;
	if (!(*lexer)->next)
		return (0);
	*lexer = (*lexer)->next;
	if ((*lexer)->token == T_QUOTE_SIMPLE)
		result = ft_strjoin(result, "");
	while (*lexer && (*lexer)->token != T_QUOTE_SIMPLE)
	{
		result = ft_strjoin(result, (*lexer)->str);
		if (!result)
			return (0);
		tmp = *lexer;
		*lexer = (*lexer)->next;
		deltoken(tmp);
	}
	if (*lexer && replacequote(&start, lexer, parser, result))
		return (1);
	return (0);
}
