# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-maar <sel-maar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 15:05:42 by sel-maar          #+#    #+#              #
#    Updated: 2023/02/07 11:27:25 by sel-maar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SRCS

SRCS_LEXER =	lexer/findtoken/issimple.c \
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

SRCS_PARSER = 	parser/parser.c \
				parser/simplequote.c \
				parser/doubleq.c \
				parser/pipe.c \
				parser/assignement.c \
				parser/sup.c \
				parser/inf.c \
				parser/dollar.c \
				parser/sep.c \
				parser/word.c \
				parser/block.c \
				parser/freeblock.c \
				parser/env.c \
				parser/envmove.c \
				main_parser.c \

SRCS_LIBFT =	libft/ft_strlen.c \
				libft/ft_strchr.c \
				libft/ft_strjoin.c \
				libft/strncmp.c \
				libft/str_dup.c \

SRCS_BUILT	 =	builtin/pwd.c \

SRCS_EXEC	 =	executer/pipex/main.c \
				executer/pipex/pipex_strjoin.c \
				executer/pipex/init.c \
				executer/pipex/free.c \
				executer/pipex/close.c \
				executer/pipex/wait.c \
				executer/pipex/child.c \
				executer/pipex/alert.c \
				executer/pipex/exit.c \
				executer/pipex/handle_heredoc.c \
				executer/pipex/multi_pipes.c \
				executer/pipex/args.c \
				executer/gnl/get_next_line.c \
				executer/gnl/clear.c \
				executer/gnl/extract.c \
				executer/gnl/memory.c

# OBJS

OBJS_LIBFT =	${SRCS_LIBFT:c=o}

OBJS_LEXER = 	${SRCS_LIBFT:c=o} ${SRCS_LEXER:c=o}

OBJS_PARSER = 	${SRCS_LIBFT:c=o} ${SRCS_PARSER:c=o}

OBJS_EXEC = 	${SRCS_LIBFT:c=o} ${SRCS_EXEC:c=o}

OBJS_EXEC = 	${SRCS_LIBFT:c=o} ${SRCS_BUILT:c=o}

OBJS = 			${OBJS_PARSER} ${SRCS_LEXER:c=o}

INCLUDES = 		-I./includes

NAME = 			minishell

# OTHER VARIABLES

CC = 			cc

CFLAGS =  		-Wextra -Werror -Wall

READLINE =		-lreadline

VGRD = 			valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --suppressions=./ignore_readline --track-origins=yes 

RM =			rm -f

# TARGETS

%.o : %.c
				${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@ -g

all :			${OBJS}
				${CC} ${OBJS} -o ${NAME} ${READLINE}

# LEXER

lexer :			${OBJS_LEXER}
				${CC} ${OBJS_LEXER} -o ${NAME} ${READLINE}

vglexer :		${OBJS_LEXER}
				${VGRD} ${CC} ${OBJS_LEXER} -o ${NAME} ${READLINE}

# PARSER

parser :		${OBJS_PARSER} ${OBJS_LEXER} 
				${CC} ${OBJS_PARSER} ${OBJS_LEXER} -o ${NAME} ${READLINE}

vgparser :		${OBJS_PARSER}
				${VGRD} ${CC} ${OBJS_PARSER} -o ${NAME} ${READLINE}

# EXECUTER

executer:		$(OBJS_EXEC)
				$(CC) $(OBJS_EXEC) -o $(NAME)

clean :
				${RM} ${OBJS} ${OBJS_EXEC} ${OBJS_PARSER} ${OBJS_LEXER}

fclean :		clean
				${RM} ${NAME}

re :			fclean all

relexer :		fclean lexer

reparser :		fclean parser

.PHONY :		all lexer vglexer parser vgparser executer clean fclean re
