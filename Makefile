# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 17:53:53 by aquinter          #+#    #+#              #
#    Updated: 2024/03/16 21:59:11 by aquinter         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap 

CC = gcc

CFLAGS = -Wextra -Werror -Wall #-fsanitize=address

RM = rm -rf

SRC = main.c \
	src/utils/ft_atoi.c \
	src/utils/ft_isdigit.c \
	src/utils/ft_lstadd_front.c \
	src/utils/ft_lstadd_back.c \
	src/utils/ft_lstdelone.c \
	src/utils/ft_lstclear.c \
	src/utils/ft_lstiter.c \
	src/utils/ft_lstnew.c \
	src/utils/ft_lstlast.c \
	src/utils/ft_lstmap.c 

OBJ = ${SRC:%.c=%.o}

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all