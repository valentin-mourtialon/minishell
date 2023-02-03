/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubleq.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:36:08 by sel-maar          #+#    #+#             */
/*   Updated: 2023/02/03 11:38:26 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

int	doublequote(t_lexer **lexer, t_parser **parser, t_env **env)
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
	if ((*lexer)->token == T_QUOTE_DOUBLE)
		result = ft_strjoin(result, "");
	while (*lexer && (*lexer)->token != T_QUOTE_DOUBLE)
	{
		if ((*lexer)->token == T_DOLLAR)
			dollardouble(lexer, parser, env);
		result = ft_strjoin(result, (*lexer)->str);
		if (!result)
			return (0);
		tmp = *lexer;
		*lexer = (*lexer)->next;
		deltoken(tmp);
	}
	if (*lexer && !replace(&start, lexer, parser, result))
		return (0);
	return (1);
}

