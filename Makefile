# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 17:53:53 by aquinter          #+#    #+#              #
#    Updated: 2024/03/23 20:55:04 by aquinter         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft.a

LIBFT_DIR = libft_v2/
SRC_DIR = src/
INC_DIR = inc/
OBJ_DIR = obj/

CC = gcc
CFLAGS = -Wextra -Werror -Wall #-g #-fsanitize=address
IFLAGS = -I$(INC_DIR) -I$(LIBFT_DIR)

RM = rm -rf

SRC = $(addprefix $(SRC_DIR), \
	push_swap.c \
	utils/ft_atoi.c \
	utils/ft_isdigit.c \
	utils/ft_lstadd_front.c \
	utils/ft_lstadd_back.c \
	utils/ft_lstdelone.c \
	utils/ft_lstclear.c \
	utils/ft_lstiter.c \
	utils/ft_lstnew.c \
	utils/ft_lstlast.c \
	utils/ft_lstmap.c \
	utils/print_stacks.c \
	stacks/a.c \
	stacks/b.c \
	movements/executions.c \
	movements/simultaneous.c \
	movements/operations.c \
	algorithm/is_sorted.c \
	algorithm/sort_three.c)

OBJ = $(addprefix $(OBJ_DIR), $(SRC_DIR:$(SRC):%.c=%.o))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
				@mkdir -p $(dir $@)
				@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

all: ${NAME}

${NAME}: ${OBJ}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all