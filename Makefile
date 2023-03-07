#######################
#      Variables      #
#######################

####    COLORS     ####
Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
W = "\033[37m"
X = "\033[0m"
UP = "\033[A" # move line
CLEAR = "\033[K" # clear line

#### COMPILATION ####
CC		= gcc
CFLAGS	= -g -fsanitize=address -Wall -Wextra -Werror 
# -g -fsanitize=address 
NAME	= minishell

#### STRUCTURE FILES ####

DIR	=	$(shell basename $(shell pwd))

### SRC FILES ###
SRC_PATH	=	src/

SRC_MAIN = main.c

SRC_LEX =\
lexer.c lexer_utils.c\
operators.c\
states.c states_stack.c states_utils.c\
tokens.c tokens_update.c tokens_utils_dlist.c tokens_utils.c\
syntaxe.c syntaxe_utils.c syntaxe_utils2.c\

SRC_PARS =\
pre_parse.c parse_cmds.c parse_gp_cmds.c

SRC_UTILS = str_utils.c params_utils.c\
lexer_debug.c env_debug.c

SRC_ENV =\
env.c env_utils.c

### OBJ FILES ###
OBJ_PATH 			= obj/

OBJ_MAIN = $(addprefix $(OBJ_PATH), $(SRC_MAIN:.c=.o))
OBJ_LEX = $(addprefix $(OBJ_PATH), $(SRC_LEX:.c=.o))
OBJ_UTILS = $(addprefix $(OBJ_PATH), $(SRC_UTILS:.c=.o))
OBJ_PARS = $(addprefix $(OBJ_PATH), $(SRC_PARS:.c=.o))
OBJ_ENV = $(addprefix $(OBJ_PATH), $(SRC_ENV:.c=.o))

OBJ_ALL = $(OBJ_MAIN) $(OBJ_LEX) $(OBJ_PARS) $(OBJ_UTILS) $(OBJ_ENV)

### HEADER FILES ###
INCS	= 	-I inc

### LIBRARIES ###
## LIBFT
LIBFT_PATH	=	libft/
LIBFT		=	$(LIBFT_PATH)libft.a
INCS		+= 	-I libft/inc

## READLINE
INCS		+= -lreadline

#######################
#        Rules        #
#######################

all:		$(NAME)
			@printf $(CLEAR)
			@echo $(G)Success"   "[$(NAME)]$(X)

$(NAME): 	$(OBJ_PATH) $(LIBFT) $(OBJ_ALL)
			@$(CC) $(CFLAGS) -o $@ $(OBJ_ALL) $(LIBFT) $(INCS)

$(LIBFT):
			@make -sC $(LIBFT_PATH)

$(OBJ_PATH)%.o:		$(SRC_PATH)%.c
					@echo $(Y)Compiling [$@]...$(X)
					@$(CC) $(CFLAGS) -o $@ -c $< $(INCS)
					@printf $(UP) $(CLEAR)

$(OBJ_PATH)%.o:		$(SRC_PATH)lexer/%.c
					@echo $(Y)Compiling [$@]...$(X)
					@$(CC) $(CFLAGS) -o $@ -c $< $(INCS)
					@printf $(UP) $(CLEAR)

$(OBJ_PATH)%.o:		$(SRC_PATH)parser/%.c
					@echo $(Y)Compiling [$@]...$(X)
					@$(CC) $(CFLAGS) -o $@ -c $< $(INCS)
					@printf $(UP) $(CLEAR)

$(OBJ_PATH)%.o:		$(SRC_PATH)utils/%.c
					@echo $(Y)Compiling [$@]...$(X)
					@$(CC) $(CFLAGS) -o $@ -c $< $(INCS)
					@printf $(UP) $(CLEAR)

$(OBJ_PATH)%.o:		$(SRC_PATH)env/%.c
					@echo $(Y)Compiling [$@]...$(X)
					@$(CC) $(CFLAGS) -o $@ -c $< $(INCS)
					@printf $(UP) $(CLEAR)

$(OBJ_PATH):
			@mkdir $(OBJ_PATH)

clean:
			@make clean -sC $(LIBFT_PATH)
			@if [ -n "$(wildcard $(OBJ_PATH))" ]; then \
				rm -rf $(OBJ_PATH); \
				echo $(R)Cleaning"  "[$(DIR)/$(OBJ_PATH)]$(X);\
			fi
			

fclean: clean
			@make fclean -sC $(LIBFT_PATH)
			@if [ -n "$(wildcard $(NAME))" ]; then \
				rm -f $(NAME); \
				echo $(R)Cleaning"  "[$(NAME)]$(X);\
			fi

re: fclean all

.PHONY: all bonus clean fclean re