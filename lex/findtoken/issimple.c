/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issimple.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:06:25 by sel-maar          #+#    #+#             */
/*   Updated: 2023/01/16 12:40:22 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <findtoken.h>

int	is_simple(char *element)
{
	if (ft_strlen(element) == 1 && element[0] == '\'')
		return (T_QUOTE_SIMPLE);
	else
		return (-1);
}
