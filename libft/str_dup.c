/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:17:35 by sel-maar          #+#    #+#             */
/*   Updated: 2023/01/30 16:18:44 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

char	*ft_strdup(char *s)
{
	char	*dup;
	int		i;

	dup = malloc(sizeof(*dup) * ft_strlen(s) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
