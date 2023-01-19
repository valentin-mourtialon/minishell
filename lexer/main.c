/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:03:03 by vmourtia          #+#    #+#             */
/*   Updated: 2023/01/12 14:10:02 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	is_separator(char c, char *separators)
{
	int		i;

	i = 0;
	while (separators[i])
	{
		if (c == separators[i])
			return (1);
		i++;
	}
	return (0);
}

int	is_special(char c, char *specials)
{
	while (*specials)
	{
		if (c == *specials)
			return (*specials);
		specials++;
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
	while ((*ptr)[len] && !is_separator((*ptr)[len], " \t") && !is_special((*ptr)[len], "|><\n\"\'${}"))
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
	char	c;

	c = **cmd;
	while (**cmd == c) //while there's the same special character we continue !
	{
		printf("%c", **cmd);
		(*cmd)++;
	}
	printf("\n");
	return (NULL);
}

int	get_next_token(char **cmd)//, t_lexer **lexer)
{
	char 	*element;
	/*t_lexer	*token;

	token = NULL;*/
	while (is_separator(**cmd))
		(*cmd)++;
	if (is_special(**cmd))
		element = consume_special(cmd);
	else
		element = retrieve_element(cmd);
	if (element)
	{
		printf("%s\n", element);
		free(element);
	}
	//token = newtoken();
	//addelement(token , findtoken(), retrieve_element(*cmd));
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