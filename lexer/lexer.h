/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:23:07 by vmourtia          #+#    #+#             */
/*   Updated: 2023/01/11 16:07:21 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_lexer {
	int				token;
	char			*str;
	struct s_lexer	*next;
} t_lexer;

int		is_special(char c);
int		is_separator(char c);
char	*retrieve_element(char **ptr);
int		get_next_token(char **cmd);

#endif