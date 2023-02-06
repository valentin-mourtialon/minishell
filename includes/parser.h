/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <sel-maar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:25:09 by sel-maar          #+#    #+#             */
/*   Updated: 2023/02/06 16:36:21 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <lexer.h>

typedef struct s_parser {
	int				block;
	t_lexer			*nexttoken;
	struct s_parser	*nextblock;
} t_parser;

typedef struct s_env {
	//char			*arg;
	char			*str;
	struct s_env	*nextexport;
	struct s_env	*nextarg;

} t_env;

typedef enum e_block_type {
	B_CMD,
	B_HEREDOC,
	B_INF,
	B_SUP,
	B_DOUBLSUP,
} typeblock;

/* parser.c */
t_parser	*ft_parser(t_lexer **lexer, t_env **env);

/* block.c */
t_parser	*newblock(int block, t_lexer **token);
void		print_block(t_parser *parser);
void		cut_lexer(t_lexer **index);
t_parser	*ft_parserlast(t_parser *block);

/* freeblock.c */
void		freeblock(t_parser *parser);

/* env.c */
t_env		*newenv(char *cmd);
void		copyenv(t_env **env, char **realenv);
void		addbackblock(t_parser **block, t_parser *new);

/* envmove.c */
void		print_env(t_env *lexer);
void		print_envarg(t_env *lexer);
void		envaddbackarg(t_env **envs, t_env *new);
void		envaddback(t_env **envs, t_env *new);

/* simplequote.c */
int			replace(t_lexer **start, t_lexer **lexer, t_parser **parser, char *cmd);
int			simplequote(t_lexer **lexer, t_parser **parser, t_env **env);
t_env		*newenv(char *cmd);
void		deltoken(t_lexer *lexer);

/* doublequote.c */
int			doublequote(t_lexer **lexer, t_parser **parser, t_env **env);

/*assignement.c*/
int	assignement(t_lexer **lexer, t_parser **parser, t_env **env);

/*dollar.c*/
int			dollar(t_lexer **lexer, t_parser **parser, t_env **env);
int			dollardouble(t_lexer **lexer, t_parser **parser, t_env **env);

/* sep.c */
int			sep(t_lexer **lexer, t_parser **parsert, t_env **env);

/* word.c */
int			word(t_lexer **lexer, t_parser **parser, t_env **env);

/* inf.c */
int			inf(t_lexer **lexer, t_parser **parser, t_env **env);

/* sup.c */
int			sup(t_lexer **lexer, t_parser **parser, t_env **env);
/* pipe.c */
int 	ft_pipe(t_lexer **lexer);
#endif

