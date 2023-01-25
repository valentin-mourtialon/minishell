/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdouble.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:07:06 by sel-maar          #+#    #+#             */
/*   Updated: 2023/01/16 12:39:16 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <findtoken.h>

int	is_double(char *element)
{
	if (ft_strlen(element) == 1 && element[0] == '"')
		return (T_QUOTE_DOUBLE);
	else
		return (-1);
}
