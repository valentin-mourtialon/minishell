/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:28:22 by sel-maar          #+#    #+#             */
/*   Updated: 2023/01/27 10:47:11 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

int	word(t_lexer **lexer, t_parser **parser, t_env **env)
{
	(void)parser;
	(void)env;
	*lexer = (*lexer)->next;
	return (1);
}
