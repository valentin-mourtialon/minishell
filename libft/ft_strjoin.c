/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:48:20 by sel-maar          #+#    #+#             */
/*   Updated: 2023/01/25 15:52:23 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

char	*ft_strjoin(char *mem_line, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = -1;
	j = 0;
	if (!mem_line)
	{
		mem_line = (char *)malloc(1 * sizeof(char));
		if (!mem_line)
			return (NULL);
		mem_line[0] = '\0';
	}
	if (!mem_line || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(mem_line) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	while (mem_line[++i] != '\0')
		str[i] = mem_line[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(mem_line) + ft_strlen(buff)] = '\0';
	free(mem_line);
	return (str);
}
