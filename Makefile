# Colors
COLOR_RESET = \033[0m
COLOR_YELLOW = \033[1;33m
COLOR_CYAN = \033[1;36m
COLOR_RED = \033[91m
COLOR_GREEN = \033[92m
COLOR_PINK = \033[95m

# Project Name
NAME = push_swap

RM = rm -rf

# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(PATH_HEADER)

# Paths
PATH_LIBFT = libft
PATH_SRCS = srcs
PATH_HEADER = include
OBJ_DIR = objs

# Source Files
SRCS =	$(PATH_SRCS)/push_swap.c		\
		$(PATH_SRCS)/ft_push.c			\
		$(PATH_SRCS)/ft_swap.c			\
		$(PATH_SRCS)/ft_rotate.c		\
		$(PATH_SRCS)/ft_reverse.c		\
		$(PATH_SRCS)/ft_lst1.c			\
		$(PATH_SRCS)/ft_lst2.c			\
		$(PATH_SRCS)/ft_findidx.c		\
		$(PATH_SRCS)/parse.c		\
		$(PATH_SRCS)/algorithm_utils1.c	\
		$(PATH_SRCS)/algorithm_utils2.c	\
		$(PATH_SRCS)/algorithm_init.c	\
		$(PATH_SRCS)/algorithm_large.c	\
		$(PATH_SRCS)/utils.c			\
		$(PATH_SRCS)/butterfly.c		\
		$(PATH_SRCS)/ft_comp.c


# Object Files
OBJS = $(patsubst $(PATH_SRCS)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(PATH_LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(PATH_LIBFT) -lft
	@echo "[$(COLOR_YELLOW)$(NAME) --> OK$(COLOR_RESET)]\n ${COLOR_GREEN}Success!${COLOR_RESET}"
	@echo "$(COLOR_PINK)\tUsage: push_swap$(COLOR_RESET)"

$(OBJ_DIR)/%.o: $(PATH_SRCS)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(COLOR_GREEN)Compiled:$(COLOR_RESET) $<"

clean:
	@make clean -C $(PATH_LIBFT)
	@$(RM) $(OBJ_DIR)
	@echo "$(COLOR_RED)Cleaned up object files!$(COLOR_RESET)"

fclean: clean
	@make fclean -C $(PATH_LIBFT)
	@$(RM) $(NAME)
	@echo "$(COLOR_RED)Cleaned up executable $(COLOR_RESET)$(COLOR_PINK) $(NAME)!$(COLOR_RESET)"

re: fclean all

.PHONY: all clean fclean re
