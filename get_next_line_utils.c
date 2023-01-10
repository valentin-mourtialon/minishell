/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:58:19 by sel-maar          #+#    #+#             */
/*   Updated: 2022/06/17 11:34:05 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_cutline1(char *mem_line)
{
	int		i;
	char	*str;

	i = 0;
	if (!mem_line[i])
		return (NULL);
	while (mem_line[i] && mem_line[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (mem_line[i] && mem_line[i] != '\n')
	{
		str[i] = mem_line[i];
		i++;
	}
	if (mem_line[i] == '\n')
	{
		str[i] = mem_line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_cutline2(char *mem_line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (mem_line[i] && mem_line[i] != '\n')
	i++;
	if (!mem_line[i])
	{
		free(mem_line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(mem_line) - i + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (mem_line[i])
	{
		str[j] = mem_line[++i];
		j++;
	}
	str[j] = '\0';
	free(mem_line);
	return (str);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int		i;
	char	*pt;

	i = 0;
	if (!s)
		return (0);
	if (c > 256)
		c %= 256;
	while (s[i])
	{
		if (s[i] == c)
		{
			pt = &s[i];
			return (pt);
		}
		i++;
	}
	if (s[i] == c)
	{
		pt = &s[i];
		return (pt);
	}
	return (0);
}

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
	free(buff);
	return (str);
}
