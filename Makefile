# **************************************************************************** #
#                              MAKEFILE - PUSH_SWAP                             #
# **************************************************************************** #

NAME    := push_swap

CC      := cc
CFLAGS  := -Wall -Wextra -Werror
RM      := rm -f

# Tous les fichiers sources principaux + ceux dans instructions/
SRCS    := src/main.c src/parsing.c src/utils.c src/small_sort.c src/node_utils.c \
           src/chunk_sort/chunk_sort.c src/chunk_sort/empty_b.c \
		   src/chunk_sort/costs.c \
           src/instructions/push.c src/instructions/rotate.c \
           src/instructions/rrotate.c src/instructions/swap.c
OBJS    := $(SRCS:.c=.o)

LIBFT   := ./includes/libft/libft.a
FTPRINTF:= ./includes/ft_printf/libftprintf.a
INCLUDES:= -I./includes/libft -I./includes/ft_printf

# =============================== COLORS ===================================== #
GREEN   := \033[32m
YELLOW  := \033[33m
RED     := \033[31m
BLUE    := \033[34m
RESET   := \033[0m

# =============================== RULES ====================================== #

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FTPRINTF) -o $(NAME)
	@echo "$(GREEN)[OK] $(NAME) created$(RESET)"

%.o: %.c push_swap.h
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(BLUE)Compiling:$(RESET) $<"

clean:
	@$(RM) $(OBJS)
	@echo "$(YELLOW)[Clean] Object files removed$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)[Fclean] $(NAME) removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
