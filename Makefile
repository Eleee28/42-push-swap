# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 20:52:15 by elena             #+#    #+#              #
#    Updated: 2024/03/20 12:02:42 by ejuarros         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLOR CODES

DEFAULT = \033[0m

GREEN = \033[92m

RED = \033[91m

YELLOW = \033[93m

BLUE = \033[36m

MAGENTA = \033[95m

CYAN = \033[96m

GRAY = \033[90m

BOLD = \033[1m

# VARIABLES

NAME = push_swap

CHECKER = checker

SRC_DIR = srcs

RULES_DIR = rules

CHECKER_DIR = checker_srcs

LIBFT_DIR = library

BIN_DIR = bin

CC = cc

CFLAGS += -Wall -Werror -Wextra -g3

REMOVE = rm -rf

LIB = ar -crs

VPATH = srcs:srcs/rules:checker_srcs

# SOURCES

SRCS =	main.c \
		ft_error.c \
		ft_init.c \
		list_utils.c \
		list_utils2.c \
		ft_sort.c \
		ft_is_sorted.c \
		ft_find.c \
		ft_dup_number.c \
		ft_sort_big.c \
		utils.c \
		ft_calc_moves.c

RULES = push.c	\
		reverse_rotate.c \
		rotate.c \
		swap.c

CHECKER_SRCS = 	ft_error.c \
				ft_init.c \
				list_utils.c \
				list_utils2.c \
				ft_is_sorted.c \
				ft_dup_number.c \
				checker.c
		
OBJS = $(SRCS:%.c=$(BIN_DIR)/%.o)  $(RULES:%.c=$(BIN_DIR)/%.o)

CHECKER_OBJS =	$(CHECKER_SRCS:%.c=$(BIN_DIR)/%.o) $(RULES:%.c=$(BIN_DIR)/%.o)

LIBFT = $(LIBFT_DIR)/libft.a

all:	$(NAME) msg
		@echo " "

$(NAME): $(OBJS) $(LIBFT)
	@echo " "
	@echo "$(MAGENTA)🔶 MAKE PROGRAM 🔶$(DEFAULT)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo " "
	@echo "👉 $(CYAN) $(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(DEFAULT)"
	@echo " "

msg:
	@echo "$(GREEN)✨ PUSH SWAP!$(DEFAULT)"

msg_checker:
	@echo "$(GREEN)✨ CHECKER!$(DEFAULT)"

$(BIN_DIR)/%.o: %.c
	@mkdir -p $(BIN_DIR)
	@echo "🔍 $(YELLOW)Compiling... $< $(DEFAULT)"
	@$(CC) $(CFLAGS) -c $< -o $@

# $(BIN_DIR)/%.o: %.c
# 	@mkdir -p $(BIN_DIR)
# 	@echo "🔍 $(YELLOW)Compiling... $< $(DEFAULT)"
# 	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): 
	@echo " "
	@echo "$(MAGENTA)🔶 MAKE LIBS 🔶$(DEFAULT)"
	@echo " "
	@echo "$(GREEN)Libft lib...$(DEFAULT)"
	@$(MAKE) -sC $(LIBFT_DIR)
	@echo " "
	@make -sC $(LIBFT_DIR)
	@echo "$(GREEN)Library compiled!$(DEFAULT)"

clean:
	@echo " "
	@echo "$(MAGENTA)🔶 CLEAN 🔶$(DEFAULT)"
	@echo " "
	@make clean -sC $(LIBFT_DIR)
	@echo "$(CYAN)Library object files cleaned$(DEFAULT)"
	@$(REMOVE) $(OBJS) $(CHECKER_OBJS) $(BIN_DIR)
	@echo "$(CYAN)Push swap object files cleaned$(DEFAULT)"

fclean: clean
	@$(REMOVE) $(NAME) $(CHECKER)
	@echo "$(CYAN)Push swap executable files cleaned!$(DEFAULT)"
	@make fclean -C $(LIBFT_DIR)
	@echo "$(CYAN)Library executable files cleaned!$(DEFAULT)"
	
re: fclean
	@echo " "
	@echo "$(GREEN)Cleaned everything for push swap!$(DEFAULT)"
	@$(MAKE) all

test: all
	@cp $(NAME) test/.
	@cd test; ./push_swap_test.sh

bonus:  $(CHECKER) msg_checker
		@echo " "

$(CHECKER): $(CHECKER_OBJS) $(LIBFT)
			@echo " "
			@echo "$(MAGENTA)🔶 MAKE CHECKER 🔶$(DEFAULT)"
			@$(CC) $(CFLAGS) $(CHECKER_OBJS) $(LIBFT) -o $(CHECKER)
			@echo " "
			@echo "👉 $(CYAN) $(CC) $(CFLAGS) $(CHECKER_OBJS) $(LIBFT) -o $(CHECKER) $(DEFAULT)"
			@echo " "
	
.PHONY: all clean fclean bonus re