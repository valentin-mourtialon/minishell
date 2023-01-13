/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findtoken2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:30:08 by sel-maar          #+#    #+#             */
/*   Updated: 2023/01/13 14:57:08 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

int	is_simple(char *element)
{
	if (ft_strlen(element) == 1 && element[0] == '\'')
		return (T_QUOTE_SIMPLE);
	else
		return (-1);
}

int	is_double(char *element)
{
	if (ft_strlen(element) == 1 && element[0] == '"')
		return (T_QUOTE_DOUBLE);
	else
		return (-1);
}

int	is_word(char *element)
{
	if (element)
		return (T_WORD);
	else
		return (-1);
}
