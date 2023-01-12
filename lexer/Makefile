# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 15:05:42 by sel-maar          #+#    #+#              #
#    Updated: 2023/01/12 18:28:05 by sel-maar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 		main.c \
	   		test.c \
			token.c \
			findtoken.c \
			libft.c \

HEADER = 	lexer.h

NAME = 		lexer

OBJS = 		${SRCS:c=o}

CC = 		gcc

CFLAGS =  	-Wextra -Werror -Wall

READLINE =	-lreadline

INC = 		-I./

VGRD = 		valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --suppressions=./ignore_readline --track-origins=yes 

RM =		rm -f

all :		${NAME}

vg :		${CRAKITO}

%.o : %.c
			${CC} ${CFLAGS} ${INC} -c $< -o $@ -g


${NAME} :	${OBJS}
			${CC} ${OBJS} -o ${NAME} ${READLINE}

CRAKITO :	${OBJS}
			${VGRD} ${CC} ${OBJS} -o lexer ${READLINE}

clean :
			${RM} ${OBJS}

fclean :	clean
			${RM} ${NAME}

re :		fclean all

.PHONY :	all clean fclean re
