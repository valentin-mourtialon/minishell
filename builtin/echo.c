/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:20:08 by sel-maar          #+#    #+#             */
/*   Updated: 2023/02/10 14:12:10 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include <parser.h>

int echo(t_parser **parser)
{
	t_lexer *index;
	int opt;
	
	index = (*parser)->nexttoken->next;
	opt = 0;
	while (index && (index->token == T_SEP || ft_strncmp("-n", index->str, 3) == 0))
	{
		if (opt == 0 && ft_strncmp("-n", index->str, 3))
			opt++;
		index = index->next;
	}
	while (index)
	{
		printf("%s", index->str);
		index = index->next;
	}
	if (opt == 0)
		printf("\n");
	return (0);
}
