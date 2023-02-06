# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 16:16:53 by valentin          #+#    #+#              #
#    Updated: 2023/02/06 10:26:17 by vmourtia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SRCS

EXEC_SRCS	 =	executer/pipex/main.c \
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

# OBJECTS

EXEC_OBJS = 	${EXEC_SRCS:c=o} ${LIBFT:c=o}

# OTHER VARIABLES 

NAME =			executer

CC =			cc

CFLAGS =		-Wall -Werror -Wextra

INC =			-I./includes/

RM =			rm -f

# TARGETS

all :			${NAME}

%.o : %.c
				${CC} ${CFLAGS} ${INC} -c $< -o $@ -g

${NAME} :		$(EXEC_OBJS)
				$(CC) $(EXEC_OBJS) -o $(NAME)

clean :
				${RM} $(EXEC_OBJS)

fclean :		clean
				${RM} ${NAME}

re :			fclean all

.PHONY :		all clean fclean bonus re
