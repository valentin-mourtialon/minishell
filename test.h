/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:41:11 by sel-maar          #+#    #+#             */
/*   Updated: 2023/01/06 16:47:54 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>

typedef struct s_tok
{
	char			*cmd;
	char			**arg;
	struct s_tok	*next;
}	t_tok;

size_t	ft_strlen(char *s);
char	**ft_split(char *s, char c);
void	ft_clearsplit(char **s);
int		ft_lexer(char **splited,t_tok *tokens);
void	ft_add_opt_arg(tokens, splited);
void	ft_tokaddback(tokens, splited);
#endif
