# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 15:05:42 by sel-maar          #+#    #+#              #
#    Updated: 2023/01/19 10:22:05 by sel-maar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FINDTOKEN =	lex/findtoken/issimple.c \
			lex/findtoken/isdouble.c \
			lex/findtoken/isword.c \
			lex/findtoken/ispipe.c \
			lex/findtoken/isdollar.c \
			lex/findtoken/isinf.c \
			lex/findtoken/issup.c \
			lex/findtoken/isassignement.c \
			lex/findtoken/is_sep.c \

LIBFT =		lex/ft_strlen.c \

MAIN = 		main.c \
			lex/get_next_token.c \
			lex/token.c \
			lex/ft_strlen.c \
			lex/ft_strchr.c \
			lex/signal.c \

INCLUDES = 	-I./lex/findtoken/ -I./lex/

NAME = 		lexer

OBJS = 		${MAIN:c=o} ${FINDTOKEN:c=o}

CC = 		gcc

CFLAGS =  	-Wextra -Werror -Wall

READLINE =	-lreadline

INC = 		-I./

VGRD = 		valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --suppressions=./ignore_readline --track-origins=yes 

RM =		rm -f

all :		${NAME}

vg :		${CRAKITO}

%.o : %.c
			${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@ -g


${NAME} :	${OBJS}
			${CC} ${OBJS} -o ${NAME} ${READLINE}

clean :
			${RM} ${OBJS}

fclean :	clean
			${RM} ${NAME}

samisupp :
			${VGRD} ./${NAME}

re :		fclean all

.PHONY :	all clean fclean re
