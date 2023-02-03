# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 15:05:42 by sel-maar          #+#    #+#              #
#    Updated: 2023/02/02 17:34:52 by sel-maar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LEXER_SRCS =	lexer/findtoken/issimple.c \
				lexer/findtoken/isdouble.c \
				lexer/findtoken/isword.c \
				lexer/findtoken/ispipe.c \
				lexer/findtoken/isdollar.c \
				lexer/findtoken/isinf.c \
				lexer/findtoken/issup.c \
				lexer/findtoken/isassignement.c \
				lexer/findtoken/is_sep.c \
				lexer/get_next_token.c \
				lexer/token.c \
				lexer/signal.c \

PARSER_SRCS = 	parser/parser.c \
				parser/simplequote.c \
				parser/doubleq.c \
				parser/pipe.c \
				parser/assignement.c \
				parser/dollar.c \
				parser/sep.c \
				parser/word.c \
				parser/block.c \
				parser/freeblock.c \
				parser/env.c \
				parser/envmove.c \
				main_parser.c \

LIBFT_SRCS =	libft/ft_strlen.c \
				libft/ft_strchr.c \
				libft/ft_strjoin.c \
				libft/strncmp.c \
				libft/str_dup.c \

INCLUDES = 		-I./includes

NAME = 			minishell

OBJS_LEXER = 	${LIBFT_SRCS:c=o} ${LEXER_SRCS:c=o}

OBJS_PARSER = 	${LIBFT_SRCS:c=o} ${PARSER_SRCS:c=o}

OBJS = 			${OBJS_PARSER} ${LEXER_SRCS:c=o}

CC = 			cc

CFLAGS =  		-Wextra -Werror -Wall

READLINE =		-lreadline

VGRD = 			valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --suppressions=./ignore_readline --track-origins=yes 

RM =			rm -f

all :			${OBJS}
				${CC} ${OBJS} -o ${NAME} ${READLINE}

lexer :			${OBJS_LEXER}
				${CC} ${OBJS_LEXER} -o ${NAME} ${READLINE}

vglexer :		${OBJS_LEXER}
				${VGRD} ${CC} ${OBJS_LEXER} -o ${NAME} ${READLINE}

parser :		${OBJS_PARSER} ${OBJS_LEXER} 
				${CC} ${OBJS_PARSER} ${OBJS_LEXER} -o ${NAME} ${READLINE}

vgparser :		${OBJS_PARSER}
				${VGRD} ${CC} ${OBJS_PARSER} -o ${NAME} ${READLINE}

%.o : %.c
				${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@ -g

clean :
				${RM} ${OBJS}

fclean :		clean
				${RM} ${NAME}

re :			fclean all

relexer :		fclean lexer

reparser :		fclean parser

.PHONY :		all lexer parser clean fclean re
