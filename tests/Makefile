# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 21:14:32 by tmilcent          #+#    #+#              #
#    Updated: 2023/01/18 21:48:35 by tmilcent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	tester
FLAGS	=	-Wall -Werror -Wextra -fsanitize=address

DIR_SRC		=	./../parsing/
DIR_INC		=	./../parsing/
DIR_TEST	=	./
DIR_INC_TEST=	./
DIR_OBJ		=	./objs/

SRCS_F	=	parsing.c
TEST_F	=	test_color_utils.c test_parsing.c

SRCS = $(addprefix $(DIR_SRC), $(SRCS_F))
TEST = $(addprefix $(DIR_TEST), $(TEST_F))
OBJS = $(addprefix $(DIR_OBJ), $(SRCS_F:.c=.o))
OBJS += $(addprefix $(DIR_OBJ), $(TEST_F:.c=.o))

all				:	$(NAME)

$(NAME)			:	$(DIR_OBJ) $(OBJS)
					gcc -fsanitize=address $(OBJS) -o $(NAME)

$(DIR_OBJ)		:
					mkdir -p $(DIR_OBJ)

$(DIR_OBJ)%.o	:	$(DIR_SRC)%.c
					gcc $(FLAGS) -I $(DIR_INC_TEST) -I $(DIR_INC) -o $@ -c $<

$(DIR_OBJ)%.o	:	$(DIR_TEST)%.c
					gcc $(FLAGS) -I $(DIR_INC_TEST) -I $(DIR_INC) -o $@ -c $<

clean			:
					rm -Rf $(DIR_OBJ)

fclean			:	clean
					rm -f $(NAME)

re				:	fclean all