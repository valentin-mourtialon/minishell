/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:23:07 by vmourtia          #+#    #+#             */
/*   Updated: 2023/01/12 18:20:53 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_lexer {
	int				token;
	char			*str;
	struct s_lexer	*next;
}	t_lexer;

typedef enum e_token_type {
	T_WORD,
	T_INF,
	T_HEREDOC,
	T_SUP,
	T_REDIRECT_OUT_APPEND,
	T_PIPE,
	T_ASSIGNMENT,
	T_DOLLAR,
	T_QUOTE_DOUBLE,
	T_QUOTE_SIMPLE,
	T_CTRLC,
	T_CTRLD,
	T_CTRLBACKSLASH
}	t_lexeren_type;

/* main.c */
int			is_special(char c);
int			is_separator(char c);
char		*retrieve_element(char **ptr);
int			get_next_token(char **cmd);

/* findtoken.c */
int			is_inf(char *element);
int			is_sup(char *element);
int			is_pipe(char *element);
int			is_assignement(char *element);
int			is_dollar(char *element);

/* token.c */
int			findtoken(char *cmd);
t_lexer		*ft_lexerlast(t_lexer *tokens);
t_lexer		*newtoken(int token, char *cmd);
void		addback(t_lexer **tokens, t_lexer *new);

/*libft.c*/
int			ft_strlen(char *s);

#endif
