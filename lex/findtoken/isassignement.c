/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isassignement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:04:58 by sel-maar          #+#    #+#             */
/*   Updated: 2023/01/16 12:33:11 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <findtoken.h>

int	is_assignement(char *element)
{
	if (ft_strlen(element) == 1 && element[0] == '=')
		return (T_ASSIGNMENT);
	else
		return (-1);
}
