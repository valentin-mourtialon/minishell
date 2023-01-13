/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:44:22 by sel-maar          #+#    #+#             */
/*   Updated: 2023/01/13 14:58:08 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

int	findtoken(char *cmd)
{
	int	(*functions[8])(char*)
		= {is_sup, is_inf, is_pipe, is_assignement,
			is_dollar, is_simple, is_double, is_word};
	int	i;

	i = 0;
	while (i < 8)
	{
		if (functions[i](cmd) >= 0)
			return (functions[i](cmd));
		i++;
	}
	return (-1);
}

t_lexer	*newtoken(int token, char *cmd)
{
	t_lexer	*newtoken;

	newtoken = malloc(sizeof(t_lexer *));
	if (newtoken == NULL)
		return (NULL);
	newtoken->token = token;
	newtoken->str = cmd;
	newtoken->next = NULL;
	return (newtoken);
}

t_lexer	*ft_lexerlast(t_lexer *tokens)
{
	if (!tokens)
		return (NULL);
	while (tokens->next)
		tokens = tokens->next;
	return (tokens);
}

void	addback(t_lexer **tokens, t_lexer *new)
{
	if (tokens)
	{
		if (*tokens)
			(*ft_lexerlast(*tokens)).next = new;
		else
			*tokens = new;
	}
}

void	print_token(t_lexer *lexer)
{
	while (lexer)
	{
		printf("%d\t%s\n", lexer->token, lexer->str);
		lexer = lexer->next;
	}
}
