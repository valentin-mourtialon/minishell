/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:25:09 by sel-maar          #+#    #+#             */
/*   Updated: 2023/01/27 15:20:43 by sel-maar         ###   ########.fr       */
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

/* parser.c */
t_parser	*ft_parser(t_lexer **lexer, t_env **env);

/* block.c */
t_parser	*newblock(int block, t_lexer **token);
void		print_block(t_parser *parser);
void		cut_lexer(t_lexer **index);

/* freeblock.c */
void		freeblock(t_parser *parser);

/* env.c */
t_env		*newenv(char *cmd);
void		copyenv(t_env **env, char **realenv);
void		addbackblock(t_parser **block, t_parser *new);

/* envmove.c */
void		print_env(t_env *lexer);
void		envaddbackarg(t_env **envs, t_env *new);
void		envaddback(t_env **envs, t_env *new);

/* simplequote.c */
int			replacequote(t_lexer **start, t_lexer **lexer, t_parser **parser, char *cmd);
int			simplequote(t_lexer **lexer, t_parser **parser, t_env **env);

/* sep.c */
int			sep(t_lexer **lexer, t_parser **parsert, t_env **env);

/* word.c */
int			word(t_lexer **lexer, t_parser **parser, t_env **env);

#endif

