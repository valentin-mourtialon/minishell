/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:25:09 by sel-maar          #+#    #+#             */
/*   Updated: 2023/01/20 11:47:59 by sel-maar         ###   ########.fr       */
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

t_parser	*newblock(int block, t_lexer *token);
t_parser	*ft_parserlast(t_parser *block);
void	addback(t_parser **block, t_parser *new);
void	print_block(t_parser *parser);
void	cut_lexer(t_lexer *lexer);
