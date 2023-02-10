/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:38:06 by sel-maar          #+#    #+#             */
/*   Updated: 2023/02/10 14:45:10 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

int	assignement(t_lexer **lexer, t_parser **parser, t_env **env)
{
	(void)env;
	if ((*parser)->block >= B_EXIT && (*lexer)->previous && !(*lexer)->previous->previous)
		(*parser)->block = B_ASSIGN;
	*lexer = (*lexer)->next;
	return (1);
}
int chearchenv(t_env **env, char *arg, char *argvalue)
{
	t_env	*index;
	int		len;
	len = ft_strlen(arg);
	index = (*env)->nextarg;
	while (index && ft_strncmp(index->str, arg, len))
		index = index->nextarg;
	if (!index)
	{
		index = (*env)->nextexport;
		while (index && ft_strncmp(index->str, arg, len))
			index = index->nextexport;
	}
	if (!index)
		return (0);
	free(index->str);
	index->str = argvalue;
	print_envarg(*env);
	return (1);
}

/*int	assignement(t_lexer **lexer, t_parser **parser, t_env **env)
{
	t_lexer	*start;
	t_env	*newarg;
	char	*argvalue;

	(void)parser;
	start = *lexer;
	argvalue = NULL;
	if (!(start->previous) || !(start->next))
		return (0);
	*lexer = (*lexer)->next;
	if ((*lexer)->token == T_QUOTE_SIMPLE)
		simplequote(lexer, parser, env);
	else if ((*lexer)->token == T_QUOTE_DOUBLE)
		doublequote(lexer, parser, env);
	argvalue = ft_strjoin(ft_strdup(start->previous->str), "=");
	argvalue = ft_strjoin(argvalue, start->next->str);
	if (!argvalue)
		return (0);
	if (chearchenv(env, start->previous->str, argvalue))
			return (1);
	newarg = newenv(argvalue);
	if (!newarg)
		return (0);
	envaddbackarg(env, newarg);
	print_envarg(*env);
	return (1);
}*/
