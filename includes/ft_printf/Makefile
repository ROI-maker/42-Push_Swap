# **************************************************************************** #
#                              MAKEFILE - FT_PRINTF                            #
# **************************************************************************** #

NAME    := libftprintf.a

# ============================== COMPILATION ================================= #
CC      := cc
CFLAGS  := -Wall -Wextra -Werror
AR      := ar rcs
RM      := rm -f

# =============================== SOURCES ==================================== #
SRCS    := ft_printf.c \
           ft_printf_utils1.c \
           ft_printf_utils2.c

OBJS    := $(SRCS:.c=.o)

# =============================== COLORS ===================================== #
GREEN   := \033[0;32m
YELLOW  := \033[1;33m
RED     := \033[1;31m
BLUE    := \033[1;34m
RESET   := \033[0m

# =============================== RULES ====================================== #
all: banner $(NAME)
	@echo "$(GREEN)✔ Build terminé avec succès !$(RESET)"

banner:
	@echo "$(BLUE)====================================$(RESET)"
	@echo "$(YELLOW)     🔧 Compilation de $(NAME) 🔧     $(RESET)"
	@echo "$(BLUE)====================================$(RESET)"

$(NAME): $(OBJS)
	@echo "$(YELLOW)[Archive]$(RESET) Création de $@"
	@$(AR) $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	@echo "$(GREEN)[Compiling]$(RESET) $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)[Cleaning objs]$(RESET)"
	@$(RM) $(OBJS)

fclean: clean
	@echo "$(RED)[Removing binary]$(RESET)"
	@$(RM) $(NAME)

re: fclean all

# Bonus : petite barre de progression (visuelle)
progress:
	@printf "$(BLUE)Progress: ["
	@for i in 1 2 3 4 5 6 7 8 9 10; do \
		sleep 0.05; printf "#"; \
	done; \
	printf "]$(RESET)\n"

.PHONY: all clean fclean re banner progress
