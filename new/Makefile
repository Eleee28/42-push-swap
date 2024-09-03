# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 20:52:15 by elena             #+#    #+#              #
#    Updated: 2024/09/02 10:41:49 by ejuarros         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################################### COLORS ####################################
DEFAULT	= \033[0m
GREEN	= \033[92m
YELLOW	= \033[93m
MAGENTA	= \033[95m
CYAN	= \033[96m
################################## VARIABLES ###################################

# Mandatory executable
NAME		= push_swap

# Bonus executable
CHECKER		= checker

# Library directory
LIB_DIR		= library

# Objects directory
BIN_DIR		= bin

# Temporary file for traking compilation
TMP			= $(BIN_DIR)/.tmp

################################################################################

# Compilation variables
CC			:= cc
CFLAGS		:= -Wall -Werror -Wextra -g3

# Remove flags
REMOVE		:= rm -rf

# Make flags
MAKEFLAGS	+= -s

################################################################################

# Possible source files path
VPATH = srcs:srcs/rules:checker_srcs

# Library file
LIB = $(LIB_DIR)/libft.a

# Source files
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

# Object files
OBJS = $(SRCS:%.c=$(BIN_DIR)/%.o)  $(RULES:%.c=$(BIN_DIR)/%.o)
CHECKER_OBJS =	$(CHECKER_SRCS:%.c=$(BIN_DIR)/%.o) $(RULES:%.c=$(BIN_DIR)/%.o)

################################################################################

# Main rule
all: $(NAME) msg
	@echo

# Push swap compilation
$(NAME): $(LIB) $(OBJS)
	@rm -rf $(TMP)
	@echo
	@$(CC) $(OBJS) $(LIB) -o $(NAME)

# Objects compilation
$(BIN_DIR)/%.o: %.c
	@mkdir -p $(BIN_DIR)
	@if [ ! -e $(TMP) ]; then \
		touch $(TMP); \
		echo "$(MAGENTA)🔶 MAKE PROGRAM 🔶$(DEFAULT)\n"; \
	fi
	@echo -n "\033[2K\r🔍 $(YELLOW)Compiling... $< $(DEFAULT)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Library compilation
$(LIB):
	@echo
	@echo "$(MAGENTA)🔶 MAKE LIBS 🔶$(DEFAULT)"
	@echo
	@make -C $(LIB_DIR)

################################################################################

# Checker compilation
bonus:  $(CHECKER) msg_checker
	@echo

$(CHECKER): $(CHECKER_OBJS) $(LIB)
	@echo
	@echo
	@echo "$(MAGENTA)🔶 MAKE CHECKER 🔶$(DEFAULT)"
	@$(CC) $(CHECKER_OBJS) $(LIB) -o $(CHECKER)
	@echo

################################################################################

aux_clean:
	@$(REMOVE) $(OBJS) $(CHECKER_OBJS) $(BIN_DIR)
	@echo "$(CYAN)Push swap object files cleaned$(DEFAULT)"

clean: msg_clean
	@make clean -C $(LIB_DIR)
	@make aux_clean
	@echo

fclean: msg_clean aux_clean
	@$(REMOVE) $(NAME) $(CHECKER)
	@echo "$(CYAN)Push swap executable files cleaned!$(DEFAULT)"
	@echo
	@make fclean -C $(LIB_DIR)
	
re: fclean
	@echo "$(GREEN)Cleaned everything for push swap!$(DEFAULT)"
	@make all

################################################################################

msg:
	@echo
	@echo "$(GREEN)✨ PUSH SWAP!$(DEFAULT)"

msg_checker:
	@echo "$(GREEN)✨ CHECKER!$(DEFAULT)"

msg_clean:
	@echo
	@echo "$(MAGENTA)🔶 CLEAN 🔶$(DEFAULT)"
	@echo

################################################################################
.PHONY: all bonus aux_clean clean fclean re msg msg_checker msg_clean
