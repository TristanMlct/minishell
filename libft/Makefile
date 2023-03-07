#######################
#      Variables      #
#######################

####    COLORS     ####
Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
W = "\033[37m"
X = "\033[0m" # reset color
UP = "\033[A" # move line
CLEAR = "\033[K" # clear line

#### COMPILATION ####
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror 

NAME	=	libft.a

#### STRUCTURE FILES ####

DIR	=	$(shell basename $(shell pwd))

### SRC FILES ###
SRC_PATH	=	src/

SRC_MEM = \
ft_memset.c ft_bzero.c ft_memcpy.c ft_memcmp.c ft_memmove.c\
ft_memchr.c ft_memcmp.c ft_calloc.c ft_memalloc.c ft_free.c ft_memdel.c\
ft_strdel.c ft_strarrdel.c
SRC_TYPE = \
ft_islower.c ft_isupper.c ft_isalpha.c ft_isdigit.c ft_isxdigit.c ft_str_isdigit.c\
ft_isspace.c ft_isblank.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c
SRC_STR	= \
ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strcmp.c ft_strncmp.c\
ft_strnstr.c ft_atoi.c ft_atol.c ft_atoll.c ft_atoi_base.c ft_strdup.c ft_substr.c\
ft_strjoin.c ft_strtrim.c ft_split.c ft_split_set.c ft_itoa.c ft_strmapi.c ft_striteri.c\
ft_strcatdup.c ft_strndup.c
SRC_ARR = \
ft_arr_str_len.c
SRC_MATH = \
ft_abs.c ft_min.c ft_max.c ft_deg_to_rad.c ft_clamp.c
SRC_PUT	= \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRC_PRINTF	= \
ft_flags_utils.c ft_print_char.c ft_print_hex.c ft_print_int.c ft_print_percent.c\
ft_print_str.c ft_printf.c ft_spec_utils.c
SRC_LST	= \
ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c ft_lstsize.c ft_lstlast.c\
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstfind.c
SRC_GNL	= \
get_next_line.c get_next_line_utils.c
SRC_BTREE = \
btree_create_node.c btree_apply_prefix.c btree_apply_infix.c btree_apply_suffix.c\
btree_insert_data.c btree_search_item.c btree_level_count.c btree_apply_by_level.c\
btree_delone.c btree_clear.c

### OBJ FILES ###
OBJ_PATH	=	obj/

OBJ_MEM = $(addprefix $(OBJ_PATH), $(SRC_MEM:.c=.o))
OBJ_TYPE = $(addprefix $(OBJ_PATH), $(SRC_TYPE:.c=.o))
OBJ_STR = $(addprefix $(OBJ_PATH), $(SRC_STR:.c=.o))
OBJ_ARR = $(addprefix $(OBJ_PATH), $(SRC_ARR:.c=.o))
OBJ_MATH = $(addprefix $(OBJ_PATH), $(SRC_MATH:.c=.o))
OBJ_PUT = $(addprefix $(OBJ_PATH), $(SRC_PUT:.c=.o))
OBJ_PRINTF = $(addprefix $(OBJ_PATH), $(SRC_PRINTF:.c=.o))
OBJ_LST = $(addprefix $(OBJ_PATH), $(SRC_LST:.c=.o))
OBJ_GNL = $(addprefix $(OBJ_PATH), $(SRC_GNL:.c=.o))
OBJ_BTREE = $(addprefix $(OBJ_PATH), $(SRC_BTREE:.c=.o))

OBJ_ALL	=	$(OBJ_MEM) $(OBJ_TYPE) $(OBJ_STR) $(OBJ_ARR) $(OBJ_MATH) \
			$(OBJ_PUT) $(OBJ_PRINTF) $(OBJ_LST) $(OBJ_GNL) $(OBJ_BTREE)
### HEADER FILES ###
INCS	= 	-I inc

#######################
#        Rules        #
#######################

all:		$(NAME)
			@printf $(CLEAR)
			@echo $(G)Success"   "[$(NAME)]$(X)

$(NAME):	$(OBJ_PATH) $(OBJ_ALL)
			@ar rcs $@ $(OBJ_ALL)

$(OBJ_PATH)%.o:		$(SRC_PATH)mem/%.c
					@echo $(Y)Compiling [$@]...$(X)
					@$(CC) $(CFLAGS) -o $@ -c $< $(INCS)
					@printf $(UP)$(CLEAR)

$(OBJ_PATH)%.o:		$(SRC_PATH)type/%.c
					@echo $(Y)Compiling [$@]...$(X)
					@$(CC) $(CFLAGS) -o $@ -c $< $(INCS)
					@printf $(UP)$(CLEAR)

$(OBJ_PATH)%.o:		$(SRC_PATH)str/%.c
					@echo $(Y)Compiling [$@]...$(X)
					@$(CC) $(CFLAGS) -o $@ -c $< $(INCS)
					@printf $(UP)$(CLEAR)

$(OBJ_PATH)%.o:		$(SRC_PATH)arr/%.c
					@echo $(Y)Compiling [$@]...$(X)
					@$(CC) $(CFLAGS) -o $@ -c $< $(INCS)
					@printf $(UP)$(CLEAR)

$(OBJ_PATH)%.o:		$(SRC_PATH)math/%.c
					@echo $(Y)Compiling [$@]...$(X)
					@$(CC) $(CFLAGS) -o $@ -c $< $(INCS)
					@printf $(UP)$(CLEAR)

$(OBJ_PATH)%.o:		$(SRC_PATH)put/%.c
					@echo $(Y)Compiling [$@]...$(X)
					@$(CC) $(CFLAGS) -o $@ -c $< $(INCS)
					@printf $(UP)$(CLEAR)

$(OBJ_PATH)%.o:		$(SRC_PATH)printf/%.c
					@echo $(Y)Compiling [$@]...$(X)
					@$(CC) $(CFLAGS) -o $@ -c $< $(INCS)
					@printf $(UP)$(CLEAR)

$(OBJ_PATH)%.o:		$(SRC_PATH)lst/%.c
					@echo $(Y)Compiling [$@]...$(X)
					@$(CC) $(CFLAGS) -o $@ -c $< $(INCS)
					@printf $(UP)$(CLEAR)

$(OBJ_PATH)%.o:		$(SRC_PATH)gnl/%.c
					@echo $(Y)Compiling [$@]...$(X)
					@$(CC) $(CFLAGS) -o $@ -c $< $(INCS)
					@printf $(UP)$(CLEAR)

$(OBJ_PATH)%.o:		$(SRC_PATH)btree/%.c
					@echo $(Y)Compiling [$@]...$(X)
					@$(CC) $(CFLAGS) -o $@ -c $< $(INCS)
					@printf $(UP)$(CLEAR)

$(OBJ_PATH):
			@mkdir $(OBJ_PATH)

clean:
			@if [ -n "$(wildcard $(OBJ_PATH))" ]; then \
				rm -rf $(OBJ_PATH); \
				echo $(R)Cleaning"  "[$(DIR)/$(OBJ_PATH)]$(X);\
			fi

fclean:		clean
			@if [ -n "$(wildcard $(NAME))" ]; then \
				rm -f $(NAME); \
				echo $(R)Cleaning"  "[$(NAME)]$(X);\
			fi

re:			fclean all

.PHONY: all bonus clean fclean re
