/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:13:05 by sel-maar          #+#    #+#             */
/*   Updated: 2023/01/17 15:21:54 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <findtoken.h>

int	is_sep(char *element)
{
	if (ft_strlen(element) == 1 && (element[0] == ' ' ||
		element[0] == '\t' || element[0] == '\n' ||
		element[0] == '\n' || element[0] == '\r' ||
		element[0] == '\v'))
		return (T_SEP);
	else
		return (-1);
}
