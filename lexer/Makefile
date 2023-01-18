# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 15:05:42 by sel-maar          #+#    #+#              #
#    Updated: 2023/01/17 15:20:53 by sel-maar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FINDTOKEN =	findtoken/issimple.c \
			findtoken/isdouble.c \
			findtoken/isword.c \
			findtoken/ispipe.c \
			findtoken/isdollar.c \
			findtoken/isinf.c \
			findtoken/issup.c \
			findtoken/isassignement.c \
			findtoken/is_sep.c \

LIBFT =		libft\ft_strlen.c

MAIN = 		get_next_token.c \
			token.c \
	   		main.c \
			ft_strlen.c\
			ft_strchr.c\
			signal.c\

INCLUDES = 	-I./findtoken/ -I./

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
