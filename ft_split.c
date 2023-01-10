/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:17:59 by sel-maar          #+#    #+#             */
/*   Updated: 2023/01/06 15:26:00 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static char	*ft_substr(char *s, unsigned int start, size_t len)
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

void	ft_clearsplit(char **s)
{
	char	*tmp;
	int		i;

	tmp = s[0];
	i = 1;
	while (s[i])
	{
		free(tmp);
		tmp = s[i];
		i++;
	}
	free(tmp);
	free(s);
}

static	int	nbword(char *s, char c)
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

char	**ft_split(char *s, char c)
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

/*int	main()
{
	char **result = ft_split("je m'appelle danny le puissant    ", ' ');
	int i = 0;
	printf("%d\n",nbword("je m'appelle danny le puissant    ", ' '));
	while (i < nbword("je m'appelle danny le puissant    ", ' '))
	{
		printf("%s\n", result[i]);
		i++;
	}
	return (0);
}*/
