/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:38:06 by sel-maar          #+#    #+#             */
/*   Updated: 2023/01/27 14:07:30 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	assignement(t_lexer **lexer, t_parser **parser, t_env **env)
{
	t_lexer	*start;

	start = *lexer;
	if (!(start->previous) && start->previous != T_WORD)
			return (0);
	*lexer = (*lexer)->next;
	if ((*lexer)->token == T_DOLLAR)
		dollar;
	else if ((*lexer)->token == T_QUOTE_SIMPLE)
		simplequote;
	else if ((*lexer)->token == T_QUOTE_DOUBLE)
		doublequote;
	return (1);
}
