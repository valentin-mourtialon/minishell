/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:22:34 by sel-maar          #+#    #+#             */
/*   Updated: 2023/02/02 14:50:26 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

int			dollar(t_lexer **lexer, t_parser **parser, t_env **env)
{
	t_lexer	*start;
	t_env	*index;
	int 	len;

	start = *lexer;
	if (!start->next)
		return (0);
	index = (*env)->nextarg;
	*lexer = (*lexer)->next;
	len = ft_strlen((*lexer)->str);
	if (start->next->token !=T_WORD)
		return (0);
	while (index && ft_strncmp(index->str, (*lexer)->str, len))
		index = index->nextarg;
	if (!index)
	{
		index = (*env)->nextexport;
		while (index && ft_strncmp(index->str, (*lexer)->str, len))
			index = index->nextexport;
	}
	if (!index)
		replace(&start, lexer, parser, ft_strdup(""));
	else
		replace(&start, lexer, parser, ft_strdup(ft_strchr(index->str,'=') + 1));
	return (1);
}

int			dollardouble(t_lexer **lexer, t_parser **parser, t_env **env)
{
	t_lexer	*start;
	t_env	*index;
	int 	len;

	(void)parser;
	start = *lexer;
	if (!start->next)
		return (0);
	index = (*env)->nextarg;
	*lexer = (*lexer)->next;
	len = ft_strlen((*lexer)->str);
	if (start->next->token !=T_WORD)
		return (0);
	while (index && ft_strncmp(index->str, (*lexer)->str, len))
		index = index->nextarg;
	if (!index)
	{
		index = (*env)->nextexport;
		while (index && ft_strncmp(index->str, (*lexer)->str, len))
			index = index->nextexport;
	}
	free((*lexer)->str);
	(*lexer)->str = ft_strdup(ft_strchr(index->str,'=') + 1);
	deltoken(start);
	return (1);
}
