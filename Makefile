# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 10:38:38 by tmilcent          #+#    #+#              #
#    Updated: 2023/01/22 16:04:25 by tmilcent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell
FLAGS	=	-Wall -Werror -Wextra -fsanitize=address

DIR_PARSING			=	./parsing/
DIR_TESTS			=	./tests/

DIR_OBJ				=	./objs/
DIR_OBJ_TESTS		=	./objs_tests/

DIR_LIBFT			=	./libft/

SRC_FILE_PARSING	=	parsing.c node_manipulation.c
SRC_FILE_TESTS		=	test_color_utils.c test_parsing.c

SRCS = $(addprefix $(DIR_PARSING), $(SRC_FILE_PARSING))
OBJS = $(addprefix $(DIR_OBJ), $(SRC_FILE_PARSING:.c=.o))

LIBFT	= $(addprefix $(DIR_LIBFT), libft.a)
LIB		= -L $(DIR_LIBFT) -lft

TEST = $(addprefix $(DIR_TESTS), $(SRC_FILE_TESTS))
OBJS_TESTS = $(addprefix $(DIR_OBJ_TESTS), $(SRC_FILE_TESTS:.c=.o))


all					:	$(NAME)

$(NAME)				:	$(DIR_OBJ) $(OBJS) $(LIBFT)
						gcc -fsanitize=address $(OBJS) minishell.o $(LIB) -o $(NAME)

$(LIBFT)			:
						make a -C $(DIR_LIBFT)

$(DIR_OBJ)			:
						mkdir -p $(DIR_OBJ)

$(DIR_OBJ)%.o		:	$(DIR_PARSING)%.c
						gcc $(FLAGS) -I $(DIR_PARSING) -I $(DIR_LIBFT) -o $@ -c $<
						gcc $(FLAGS) -I $(DIR_PARSING) -o minishell.o -c minishell.c

clean				:
						rm -Rf $(DIR_OBJ)
						rm -Rf $(DIR_OBJ_TESTS)
						rm -Rf minishell.o
						make -C $(DIR_LIBFT) clean

fclean				:	clean
						rm -f $(NAME)
						rm -f tester
						make -C $(DIR_LIBFT) fclean

re					:	fclean all

$(DIR_OBJ_TESTS)	:
						mkdir -p $(DIR_OBJ_TESTS)

$(DIR_OBJ_TESTS)%.o	:	$(DIR_TESTS)%.c
						gcc $(FLAGS) -I $(DIR_TESTS) -I $(DIR_PARSING) -I $(DIR_LIBFT) -o $@ -c $<

test				:	$(NAME) $(DIR_OBJ_TESTS) $(OBJS_TESTS)
						gcc -fsanitize=address $(OBJS_TESTS) $(OBJS) $(LIB) -o tester
					