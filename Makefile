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
CFLAGS = -Wall -Wextra -Werror -I $(PATH_HEADER)

# Paths
PATH_LIBFT = libft
PATH_SRCS = srcs

PATH_ALGORITHM = srcs/algorithm
PATH_ERRORHANDLE = srcs/errorhandle
PATH_INSTRUCTIONS = srcs/instructions
PATH_MISC = srcs/misc

PATH_HEADER = includes
OBJ_DIR = objs

# Source Files Categories
ALGORITHM_SRC =		01_utils.c		\
					02_utils.c		\
					alg_init.c		\
					alg_large.c		\
					alg.c			\
					ft_comp.c

ERRORHANDLE_SRC =	01_parser.c

INSTRUCTIONS_SRC =	ft_swappush.c	\
					ft_rotate.c		\
					ft_reverse.c

MISC_SRC =			01_lst.c		\
					01_others.c		\
					02_lst.c		\
					02_others.c

# Prepending the path
ALGORITHM_SRCS = $(addprefix $(SRC_PATH)/algorithm/, $(ALGORITHM_SRC))
ERRORHANDLE_SRCS = $(addprefix $(SRC_PATH)/errorhandle/, $(ERRORHANDLE_SRC))
INSTRUCTIONS_SRCS = $(addprefix $(SRC_PATH)/instructions/, $(INSTRUCTIONS_SRC))
MISC_SRCS = $(addprefix $(SRC_PATH)/misc/, $(MISC_SRC))

# Combining All Sources
SRCS = $(PATH_SRCS)/push_swap.c $(ALGORITHM_SRCS) $(ERRORHANDLE_SRCS) $(INSTRUCTIONS_SRCS) $(MISC_SRCS)

# Object Files
OBJS = $(SRCS:$(SRC_PATH)/%.c=$(OBJ_DIR)/%.o)

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
	@echo "$(COLOR_RED)Cleaned up object files$(COLOR_RESET)"
	@$(RM) .DS_Store

fclean: clean
	@make fclean -C $(PATH_LIBFT)
	@$(RM) $(NAME)
	@echo "$(COLOR_RED)Cleaned up executables$(COLOR_RESET)"

re: fclean all

.PHONY: all clean fclean re
