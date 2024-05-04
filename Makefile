# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 17:53:53 by aquinter          #+#    #+#              #
#    Updated: 2024/05/04 15:56:43 by aquinter         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft/libft.a

LIBFT_DIR = libft/
SRC_DIR = src/
INC_DIR = inc/
OBJ_DIR = obj/

CC = gcc
CFLAGS = -Wextra -Werror -Wall #-g3 #-fsanitize=address #-g 
IFLAGS = -I$(INC_DIR) -I$(LIBFT_DIR)

RM = rm -rf

SRC = $(addprefix $(SRC_DIR), \
	push_swap.c \
	movements/a_stack_ops.c \
	movements/b_stack_ops.c \
	movements/simultaneous_stack_ops.c \
	movements/stack_ops.c \
	sorting/sort.c \
	sorting/algorithm.c \
	sorting/a_to_b.c \
	sorting/b_to_a.c \
	utils/stack_manipulations.c \
	utils/print_stacks.c \
	utils/ft_stol.c \
	utils/sorting_utils.c \
	utils/frees.c)

OBJ = $(addprefix $(OBJ_DIR), $(SRC:$(SRC_DIR)%.c=%.o))

TOTAL_FILES		= $(words $(SRC))
CURRENT_FILES	= 0

define progress_bar
    @$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
    @printf "\r$(GREEN)Compiling push_swap... [%-$(TOTAL_FILES)s] %-10s%d%%$(NC)" $$(for i in $$(seq 1 $(CURRENT_FILE)); do printf "#"; done) "" $(shell echo $$((($(CURRENT_FILE) * 100) / $(TOTAL_FILES))))
	@if [ $(CURRENT_FILE) -eq $(TOTAL_FILES) ]; then echo ""; fi
endef

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
				$(call progress_bar)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

${LIBFT}:
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@$(RM) $(OBJ_DIR)
	@echo "Cleaned push_swap objects"
	@$(MAKE) clean -C $(LIBFT_DIR) > /dev/null
	@echo "Cleaned libft objects"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR) > /dev/null

re: fclean all

.PHONY: all clean fclean re