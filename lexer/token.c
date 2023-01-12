/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:44:22 by sel-maar          #+#    #+#             */
/*   Updated: 2023/01/12 18:20:06 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

int	findtoken(char *cmd)
{
	int	(*functions[5])(char*)
		   	= {is_sup, is_inf, is_pipe, is_assignement, is_dollar};
	int	i;

	i = 0;
	while (i < 5)
	{
		if(functions[i](cmd) >= 0)
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
