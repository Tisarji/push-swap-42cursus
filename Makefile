COLOR_RESET = \033[0m
COLOR_YELLOW = \033[1;33m
COLOR_CYAN = \033[1;36m
COLOR_RED = \033[91m
COLOR_GREEN = \033[92m
COLOR_PINK = \033[95m

NAME = push_swap
CHECKER_NAME = checker

RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -I $(PATH_HEADER)

PATH_LIBFT = libft
PATH_SRCS = srcs

PATH_ALGORITHM = srcs/algorithm
PATH_ERRORHANDLE = srcs/errorhandle
PATH_INSTRUCTIONS = srcs/instructions
PATH_MISC = srcs/misc

PATH_HEADER = includes
OBJ_DIR = objs

ALGORITHM_SRC =		01_bubble_sort.c	\
					01_butterfly.c		\
					01_sorting.c

ERRORHANDLE_SRC =	01_parser.c			\
					01_free.c

INSTRUCTIONS_SRC =	action_inst.c

MISC_SRC =			01_lst.c			\
					01_utils.c

ALGORITHM_SRCS = $(addprefix $(SRC_PATH)/algorithm/, $(ALGORITHM_SRC))
ERRORHANDLE_SRCS = $(addprefix $(SRC_PATH)/errorhandle/, $(ERRORHANDLE_SRC))
INSTRUCTIONS_SRCS = $(addprefix $(SRC_PATH)/instructions/, $(INSTRUCTIONS_SRC))
MISC_SRCS = $(addprefix $(SRC_PATH)/misc/, $(MISC_SRC))

SRCS = $(PATH_SRCS)/push_swap.c $(ALGORITHM_SRCS) $(ERRORHANDLE_SRCS) $(INSTRUCTIONS_SRCS) $(MISC_SRCS)
OBJS = $(SRCS:$(SRC_PATH)/%.c=$(OBJ_DIR)/%.o)

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

PATH_CHECKER = bonus/srcs

SRCS_CHECKER =	$(PATH_CHECKER)/00_free_bonus.c		\
				$(PATH_CHECKER)/01_utils_bonus.c	\
				$(PATH_CHECKER)/02_action_bonus.c	\
				$(PATH_CHECKER)/03_action_bonus.c	\
				$(PATH_CHECKER)/04_lst_bonus.c		\
				$(PATH_CHECKER)/05_parser_bonus.c	\
				$(PATH_CHECKER)/06_check_bonus.c	\
				bonus/checker.c

OBJ_DIR_CHECKER = objs_checker

OBJS_CHECKER = $(SRCS_CHECKER:$(PATH_CHECKER)/%.c=$(OBJ_DIR_CHECKER)/%.o)

$(OBJ_DIR_CHECKER)/%.o: $(PATH_CHECKER)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(COLOR_GREEN)Compiled:$(COLOR_RESET) $<"

bonus: $(CHECKER_NAME)

$(CHECKER_NAME): $(OBJS_CHECKER)
	@make -C $(PATH_LIBFT)
	@$(CC) $(CFLAGS) -o $(CHECKER_NAME) $(OBJS_CHECKER) -L$(PATH_LIBFT) -lft
	@echo "[$(COLOR_YELLOW)$(CHECKER_NAME) --> OK$(COLOR_RESET)]\n ${COLOR_GREEN}Success!${COLOR_RESET}"
	@echo "$(COLOR_PINK)\tUsage: checker$(COLOR_RESET)"

$(OBJ_DIR_CHECKER)/%.o: $(PATH_CHECKER)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(COLOR_GREEN)Compiled:$(COLOR_RESET) $<"

clean_bonus:
	@make clean -C $(PATH_LIBFT)
	@$(RM) $(OBJ_DIR_CHECKER)
	@echo "$(COLOR_RED)Cleaned up bonus object files$(COLOR_RESET)"
	@$(RM) .DS_Store

fclean_bonus: clean_bonus
	@make fclean -C $(PATH_LIBFT)
	@$(RM) $(CHECKER_NAME)
	@echo "$(COLOR_RED)Cleaned up bonus executables$(COLOR_RESET)"

re_bonus: fclean_bonus bonus

.PHONY: all clean fclean re bonus clean_bonus fclean_bonus re_bonus
