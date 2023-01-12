/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:03:03 by vmourtia          #+#    #+#             */
/*   Updated: 2023/01/12 18:06:25 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

int	is_separator(char c)
{
	const char	separators[2] = {' ', '\t'};
	int			i;

	i = 0;
	while (separators[i])
	{
		if (c == separators[i])
			return (1);
		i++;
	}
	return (0);
}

int	is_special(char c)
{
	const int	specials[10]
		= {'|', '>', '<', '"', '\n', '\'', '$', '{', '}', '"'};
	int			i;

	i = 0;
	while (i < 10)
	{
		if (c == specials[i])
			return (specials[i]);
		i++;
	}
	return (0);
}

char	*retrieve_element(char **ptr)
{
	char	*element;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!ptr)
		return (NULL);
	while ((*ptr)[len] && !is_separator((*ptr)[len])
			&& !is_special((*ptr)[len]))
		len++;
	element = malloc(sizeof(char) * len + 1);
	if (!element)
		return (NULL);
	element[len] = '\0';
	while (i < len)
	{	
		element[i] = **ptr;
		(*ptr)++;
		i++;
	}
	return (element);
}

char	*consume_special(char **cmd)
{
	char	*stringspecial;
	char	c;
	int		i;
	int		len;

	c = **cmd;
	i = 0;
	len = 0;
	//printf("bonjour");
	while ((*cmd)[len] && (*cmd)[len] == c)
		len++;
	stringspecial = malloc(sizeof(char) * (len + 1));
	if (!stringspecial)
		return (NULL);
	stringspecial[len] = '\0';
	while (i < len)
	{
		stringspecial[i] = **cmd;
		(*cmd)++;
		i++;
	}
	return (stringspecial);
}

int	get_next_token(char **cmd)//, t_lexer **lexer)
{
	char	*element;
	//t_lexer	*token;

	//token = NULL;
	while (is_separator(**cmd))
		(*cmd)++;
	if (is_special(**cmd))
		element = consume_special(cmd);
	else
		element = retrieve_element(cmd);
	if (element)
	{
		printf("%s\t", element);
		printf("%d\n", findtoken(element));
		free(element);//a enlever
	}
	//token = newtoken(findtoken(element), element);
	//add_back(lexer, token);
	return (0);
}

/*
int main()
{
	char	*cmd = "echo hello world| grep h\n";
	t_lexer	*lexer;

	//init_lexer(&lexer);
	lexer = NULL;
	get_next_token(&cmd, &lexer);
	write(1, "\n", 1);
	get_next_token(&cmd);
	write(1, "\n", 1);
	get_next_token(&cmd);
	write(1, "\n", 1);
	get_next_token(&cmd);
	write(1, "\n", 1);
	get_next_token(&cmd);
	write(1, "\n", 1);
	get_next_token(&cmd);
	return (0);
}*/
