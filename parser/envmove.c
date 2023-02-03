/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:59:50 by sel-maar          #+#    #+#             */
/*   Updated: 2023/01/30 14:41:20 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static t_env	*ft_envlast(t_env *envs)
{
	if (!envs)
		return (NULL);
	while (envs->nextexport)
		envs = envs->nextexport;
	return (envs);
}

void	envaddback(t_env **envs, t_env *new)
{
	if (envs)
	{
		if (*envs)
			(*ft_envlast(*envs)).nextexport = new;
		else
			*envs = new;
	}
}

t_env	*newenv(char *cmd)
{
	t_env	*newenv;

	newenv = malloc(sizeof(t_env)/* sizeof(t_env *)*/); //bizarre
	if (newenv == NULL)
		return (NULL);
	//newenv->str = arg;
	newenv->str = cmd;
	newenv->nextexport = NULL;
	newenv->nextarg = NULL;
	return (newenv);
}

t_env	*ft_envlastarg(t_env *envs)
{
	if (!envs)
		return (NULL);
	while (envs->nextarg)
		envs = envs->nextarg;
	return (envs);
}

void	envaddbackarg(t_env **envs, t_env *new)
{
	if (envs)
	{
		if (*envs)
			(*ft_envlastarg(*envs)).nextarg = new;
		else
			*envs = new;
	}
}

void	print_envarg(t_env *lexer)
{
	while (lexer)
	{
		printf("%s\n", lexer->str);
		lexer = lexer->nextarg;
	}
}

void	print_env(t_env *lexer)
{
	while (lexer)
	{
		printf("%s\n", lexer->str);
		lexer = lexer->nextexport;
	}
}

