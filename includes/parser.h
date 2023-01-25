/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:25:09 by sel-maar          #+#    #+#             */
/*   Updated: 2023/01/25 14:04:27 by sel-maar         ###   ########.fr       */
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

t_parser	*ft_parser(t_lexer **lexer);
t_parser	*newblock(int block, t_lexer **token);
void	addbackblock(t_parser **block, t_parser *new);
void	freeblock(t_parser *parser);
void	print_block(t_parser *parser);
void	cut_lexer(t_lexer **index);
int		sep(t_lexer **lexer, t_parser **parser);
int		word(t_lexer **lexer, t_parser **parser);
int		simplequote(t_lexer **lexer, t_parser **parser);

#endif

