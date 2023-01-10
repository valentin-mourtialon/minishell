/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:58:34 by sel-maar          #+#    #+#             */
/*   Updated: 2022/06/17 11:34:56 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000000
# endif

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *mem_line, char *buff);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *s);
char	*ft_cutline1(char *mem_line);
char	*ft_cutline2(char *mem_line);
#endif
