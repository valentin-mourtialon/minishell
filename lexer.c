/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:54:43 by sel-maar          #+#    #+#             */
/*   Updated: 2023/01/06 17:27:42 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
int		ft_checkbasicerror(char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
	{
		if (splited)
		if (splited[i] == splited[i+1])
				return (0);
		i++;
	}
	return (1);
}

int	ft_addcmd(t_tok *token, char **splited)
{
	tokens->cmd = *splited;
	return (1);
}

int	ft_add_opt_arg(tokens, splited)
{
	int	i;

	i = 0
	while (**splited != '|')
	{
		i++;
	}
	return (i);
}
int	ft_lexer(char **splited,t_tok *tokens)
{
	t_tok	tmp;
	int	i;

	i = 0;
	while(splited[i])
	{
		tmp = ft_newtoken();
		ft_tokaddback(tokens, splited);
		t_add_cmd(token, splited);
		i++;
		i += ft_add_opt_arg(tokens, splited);
		i++;
	}
	ft_clearsplit(splited);
	return (1);
}

t_tok	*ft_hublexer(char *s)
{
	t_tok	*tokens;
	char	**splited;

	tokens = NULL;
	splited = ft_split(s, ' ');
	if (!splited)
		return (NULL);
	if (!ft_checkbasicerror(splited))
		return (ft_clearsplit(splited), NULL);
	if (ft_lexer(splited, tokens))
			return (NULL);
	return (tokens);
}
/*
int	main(int ac, char **av)
{
	char **test = av;
	test++;
	printf("%s", *test);
	return (0);
}*/
