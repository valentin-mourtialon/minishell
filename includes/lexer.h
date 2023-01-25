/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:23:07 by vmourtia          #+#    #+#             */
/*   Updated: 2023/01/24 15:30:58 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <findtoken.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_lexer {
	int				token;
	char			*str;
	struct s_lexer	*next;
	struct s_lexer	*previous;
}	t_lexer;

typedef enum e_token_type {
	//token
	T_SUP,
	T_INF,
	T_PIPE,
	T_ASSIGNMENT,
	T_SEP,
	T_DOLLAR,
	T_QUOTE_SIMPLE,
	T_QUOTE_DOUBLE,
	T_WORD,
	//block
	B_SIMPLE,
}	t_lexeren_type;

/* main.c */
int			is_special(char c);
int			is_separator(char c);
char		*retrieve_element(char **ptr);
int			get_next_token(char **cmd, t_lexer **lexer);

/* token.c */
int			findtoken(char *cmd);
void		print_token(t_lexer *lexer);
t_lexer		*ft_lexerlast(t_lexer *tokens);
t_lexer		*newtoken(int token, char *cmd);
void		addback(t_lexer **tokens, t_lexer *new);
t_lexer		*parcour_lexer(t_lexer *lexer, int i);
/*signal.c*/
void		handle_sigquit(int d);

/*a regler*/
int			ft_strlen(char *s);
char		*ft_strchr(char *s, char c);
char		*ft_strjoin(char *mem_line, char *buff);
#endif
