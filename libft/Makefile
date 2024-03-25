# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 19:59:11 by aquinter          #+#    #+#              #
#    Updated: 2024/03/23 20:05:25 by aquinter         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libft.a

LIBFT_DIR 	= libft/
GNL_DIR 	= gnl/
PRINTF_DIR 	= ft_printf/
OBJ_DIR 	= obj/

RM 			= rm -rf

CC 			= gcc
CFLAGS 		= -Wextra -Wall -Werror
IFLAGS 		= -I$(INC_DIR) -I$(INC_DIR)libft -I$(INC_DIR)get_next_line -I$(INC_DIR)ft_printf

LIBFT_SRC = $(addprefix $(LIBFT_DIR), \
	ft_isalpha.c 	ft_isdigit.c 	ft_isalnum.c 		ft_isascii.c 		\
	ft_isprint.c 	ft_strlen.c 	ft_memset.c 		ft_bzero.c 	 		\
	ft_memcpy.c 	ft_memmove.c 	ft_strlcpy.c 		ft_strlcat.c 		\
	ft_toupper.c 	ft_tolower.c 	ft_strchr.c 		ft_strrchr.c 		\
	ft_strncmp.c 	ft_memchr.c 	ft_memcmp.c 		ft_strnstr.c 		\
	ft_atoi.c 		ft_calloc.c		ft_strdup.c 		ft_substr.c	 		\
	ft_strjoin.c	ft_strtrim.c 	ft_split.c 			ft_itoa.c 	 		\
	ft_strmapi.c 	ft_striteri.c 	ft_putchar_fd.c 	ft_putstr_fd.c		\
	ft_putendl_fd.c	ft_putnbr_fd.c 	ft_lstnew.c 		ft_lstadd_front.c 	\
	ft_lstsize.c	ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c 		\
	ft_lstclear.c 	ft_lstiter.c 	ft_lstmap.c)

GNL_SRC = $(addprefix $(GNL_DIR), \
	get_next_line.c)

PRINTF_SRC = $(addprefix $(PRINTF_DIR), \
	ft_printf.c		ft_putchar.c 	ft_puthexa.c			ft_putnbr.c 	\
	ft_putptr.c		ft_putstr.c		ft_put_transform_hexa.c	ft_putunsigned.c)

OBJ_LIBFT = $(addprefix $(OBJ_DIR), $(LIBFT_SRC:$(LIBFT_DIR)%.c=%.o))
OBJ_GNL = $(addprefix $(OBJ_DIR), $(GNL_SRC:$(GNL_DIR)%.c=%.o))
OBJ_PRINTF = $(addprefix $(OBJ_DIR), $(PRINTF_SRC:$(PRINTF_DIR)%.c=%.o))

OBJ = $(OBJ_LIBFT) $(OBJ_GNL) $(OBJ_PRINTF)

TOTAL_FILES  := $(words $(LIBFT_SRC) $(GNL_SRC) $(PRINTF_SRC))
CURRENT_FILE := 0

define progress_bar
    @printf "\rCompiling libft_v2  [%-$(TOTAL_FILES)s]%-10s%d%%$(NC)" $$(for i in $$(seq 1 $(1)); do printf "#"; done) "" $(shell echo $$((($(1) * 100) / $(TOTAL_FILES))))
		@if [ $(1) -eq $(TOTAL_FILES) ]; then echo ""; fi
endef

$(OBJ_DIR)%.o: $(LIBFT_DIR)%.c
				@mkdir -p $(dir $@)
				@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
				$(call progress_bar,$(shell echo $$(($(CURRENT_FILE) + 1))))
				@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))

$(OBJ_DIR)%.o: $(GNL_DIR)%.c
				@mkdir -p $(dir $@)
				@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
				$(call progress_bar,$(shell echo $$(($(CURRENT_FILE) + 1))))
				@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))

$(OBJ_DIR)%.o: $(PRINTF_DIR)%.c
				@mkdir -p $(dir $@)
				@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
				$(call progress_bar,$(shell echo $$(($(CURRENT_FILE) + 1))))
				@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))

all: ${NAME}

${NAME} : ${OBJ}
	@ar rcs $(NAME) $(OBJ)
	
clean:
		@$(RM) $(OBJ)
		@$(RM) $(OBJ_DIR)
		@echo "Libft cleaned"

fclean: clean
		@$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
