/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <sel-maar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:49:54 by sel-maar          #+#    #+#             */
/*   Updated: 2023/02/06 16:34:52 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

int	sup(t_lexer **lexer, t_parser **parser, t_env **env)
{
	(void)parser;
	(void)env;
	*lexer = (*lexer)->next;
	return (1);
}