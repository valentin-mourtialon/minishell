/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:51:16 by sel-maar          #+#    #+#             */
/*   Updated: 2023/01/26 16:59:14 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	if (ft_strlen(s) - start < len)
		result = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		result[i] = s[start];
		start++;
		i++;
	}
	result[i] = 0;
	return (result);
}

static	int	nbword(const char *s, char c)
{
	int	i;
	int	nbword;

	i = 0;
	nbword = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			while (s[i] != c && s[i])
				i++;
			nbword++;
		}
		while (s[i] == c && s[i])
			i++;
	}
	return (nbword);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	int		i;
	int		j;
	int		k;

	result = malloc (sizeof(char *) * (nbword(s, c) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (k < nbword(s, c))
		{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			j++;
		}
		result[k++] = ft_substr(s, i - j, j);
		j = 0;
	}
	result[k] = NULL;
	return (result);
}
