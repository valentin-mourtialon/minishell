/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:44:22 by sel-maar          #+#    #+#             */
/*   Updated: 2023/01/19 12:00:28 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

void	init_tab(int (**f)(char*))
{
	f[0] = &is_sup;
	f[1] = &is_inf;
	f[2] = &is_pipe;
	f[3] = &is_assignement;
	f[4] = &is_sep;
	f[5] = &is_dollar;
	f[6] = &is_simple;
	f[7] = &is_double;
	f[8] = &is_word;
}

int	findtoken(char *cmd)
{
	int	(*functions[9])(char*);
	int	i;

	init_tab(functions);
	i = 0;
	while (i < 9)
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
