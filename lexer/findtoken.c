/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findtoken.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:13:24 by sel-maar          #+#    #+#             */
/*   Updated: 2023/01/13 14:07:48 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

int is_inf(char *element)
{
	if (ft_strlen(element) == 1 && element[0] == '<')
		return (T_INF);
	else
		return (-1);
}


int is_sup(char *element)
{
	if (ft_strlen(element) == 1 && element[0] == '>')
		return (T_SUP);
	else
		return (-1);
}

int is_pipe(char *element)
{
	if (ft_strlen(element) == 1 && element[0] == '|')
		return (T_PIPE);
	else
		return (-1);	
}


int is_assignement(char *element)
{
	if (ft_strlen(element) == 1 && element[0] == '=')
		return (T_ASSIGNMENT);
	else
		return (-1);	
}

int	is_dollar(char *element)
{
	if (ft_strlen(element) == 1 && element[0] == '$')
		return (T_DOLLAR);
	else
		return (-1);
}
