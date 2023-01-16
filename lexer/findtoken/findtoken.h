/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findtoken.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:34:03 by sel-maar          #+#    #+#             */
/*   Updated: 2023/01/16 12:37:56 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FINDTOKEN_H
# define FINDTOKEN_H

# include <lexer.h>

int	is_assignement(char *cmd);
int	is_word(char *cmd);
int	is_sup(char *cmd);
int	is_inf(char *cmd);
int	is_simple(char *cmd);
int	is_double(char *cmd);
int	is_dollar(char *cmd);
int	is_pipe(char *cmd);

#endif
