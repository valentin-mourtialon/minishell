/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:48:44 by sel-maar          #+#    #+#             */
/*   Updated: 2023/01/06 17:00:50 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

t_tokens	*ft_newtoken()
{
	t_tokens	*newtoken;

	newtoken = malloc(sizeof(*t_tokens));
	if (newtoken == NULL)
		return (NULL);
	newtoken->arg = NULL;
	newtoken->cmd = NULL;
	newtoken->next = NULL;
	return (newtoken);
}

t_tokens	*ft_tokenslast(t_list *tokens)
{
	if (!tokens)
		return (NULL);
	while (tokens->next)
	{
		tokens = tokens->next;
	}
	return (tokens);
}

void	ft_tokaddback(t_tok **tokens, t_tok new)
{
	if (tokens)
	{
		if (*tokens)
			(*ft_tokenslast(*tokens)).next = new;
		else
			*tokens = new;
	}
}
