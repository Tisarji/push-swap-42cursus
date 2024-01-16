COLOR_RESET = \033[0m
COLOR_YELLOW = \033[1;33m
COLOR_CYAN = \033[1;36m
COLOR_RED = \033[91m
COLOR_GREEN = \033[92m
COLOR_PINK = \033[95m

NAME	=	push_swap

RM		=	rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror $(INCLUDE)

PATH_LIBFT = libft
PATH_SRCS = srcs
PATH_HEADER = include
OBJ_DIR = objs

INCLUDE = -I$(PATH_HEADER)

SRCS =	$(PATH_SRCS)/push_swap.c \
		$(PATH_SRCS)/algorithm.c \
		$(PATH_SRCS)/ft_error.c \
		$(PATH_SRCS)/parse.c

OBJS = $(SRCS:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	@echo "$(COLOR_GREEN)Compiled:$(COLOR_RESET) $<"

$(NAME): $(OBJS)
	@make -C $(PATH_LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(PATH_LIBFT) -lft
	@echo "$(COLOR_CYAN)Executable $(NAME) has been created!$(COLOR_RESET)"

all: $(NAME)

clean:
	@make clean -C $(PATH_LIBFT)
	@$(RM) $(OBJS)
	@echo "$(COLOR_YELLOW)Cleaned up object files!$(COLOR_RESET)"

fclean: clean
	@make fclean -C $(PATH_LIBFT)
	@$(RM) $(NAME)
	@echo "$(COLOR_RED)Cleaned up executable $(NAME)!$(COLOR_RESET)"

re: fclean all

.PHONY: all clean fclean re
