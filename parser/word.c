/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:28:22 by sel-maar          #+#    #+#             */
/*   Updated: 2023/02/07 17:34:15 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

int	isbuilt(char *str)
{
	int len;

	len = ft_strlen(str);
	if (len < 8)
		len = 8;
	if (!strncmp(str, "cd", len))
		return (B_CD);
	if (!strncmp(str, "pwd", len))
		return (B_PWD);
	if (!strncmp(str, "echo", len))
		return (B_ECHO);
	if (!strncmp(str, "unset", len))
		return (B_UNSET);
	if (!strncmp(str, "export", len))
		return (B_EXPORT);
	if (!strncmp(str, "env", len))
		return (B_ENV);
	if (!strncmp(str, "exit", len))
		return (B_EXIT);
	return (B_CMD);
}

int	word(t_lexer **lexer, t_parser **parser, t_env **env)
{
	(void)env;
	if (!(*lexer)->previous)
		(*parser)->block = isbuilt((*lexer)->str);
	*lexer = (*lexer)->next;
	return (1);
}
