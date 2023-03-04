# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 14:09:02 by tmilcent          #+#    #+#              #
#    Updated: 2023/02/13 16:16:21 by tmilcent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft/
LIBFT_INC = -I $(LIBFT_DIR)
LIBFT_LINK = -L $(LIBFT_DIR) -lft $(LIBFT_DIR)libft.a

SRC_NAME = parsing.c t_token_operations.c
SRC_DIR = ./srcs
SRC = $(addprefix $(SRC_DIR)/, $(SRC_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_DIR = ./obj
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_NAME))

INC_DIR = ./includes
INC = $(addprefix -I, $(INC_DIR))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LINK) -o $(NAME)
	@echo "Compilation of $(NAME) done"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(LIBFT_INC) $(INC) -o $@ -c $<
	@echo "Compilation of $< done"

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "Clean done"

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@echo "Fclean done"	

re: fclean all

.PHONY: all clean fclean re