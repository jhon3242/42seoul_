# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 23:52:28 by wonjchoi          #+#    #+#              #
#    Updated: 2022/06/29 16:52:10 by wonjchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap
B_NAME = checker

CC = gcc
CFLAG = -Wall -Wextra -Werror

LIB_DIR = lib/libft/
GNL_DIR = lib/get_next_line/
FPT_DIR = lib/ft_printf/
SRC_DIR = src

INCLUDE = -I./include

SRC = $(SRC_DIR)/push_swap.c\
		$(SRC_DIR)/push_swap_node.c\
		$(SRC_DIR)/push_swap_stack.c\
		$(SRC_DIR)/push_swap_a_to_b.c\
		$(SRC_DIR)/push_swap_b_to_a.c\
		$(SRC_DIR)/push_swap_do_op.c\
		$(SRC_DIR)/push_swap_node.c\
		$(SRC_DIR)/push_swap_parsing.c\
		$(SRC_DIR)/push_swap_pivot.c\
		$(SRC_DIR)/push_swap_sort.c\
		$(SRC_DIR)/push_swap_sort_utile.c\
		$(SRC_DIR)/push_swap_atoi_and_nullck.c\
		$(SRC_DIR)/push_swap_command_add.c\
		$(SRC_DIR)/push_swap_command_zip.c\
		$(SRC_DIR)/push_swap_utile.c\
		

B_SRC = $(SRC_DIR)/push_swap_checker.c\
		$(SRC_DIR)/push_swap_node.c\
		$(SRC_DIR)/push_swap_stack.c\
		$(SRC_DIR)/push_swap_a_to_b.c\
		$(SRC_DIR)/push_swap_b_to_a.c\
		$(SRC_DIR)/push_swap_do_op.c\
		$(SRC_DIR)/push_swap_node.c\
		$(SRC_DIR)/push_swap_parsing.c\
		$(SRC_DIR)/push_swap_pivot.c\
		$(SRC_DIR)/push_swap_sort.c\
		$(SRC_DIR)/push_swap_sort_utile.c\
		$(SRC_DIR)/push_swap_atoi_and_nullck.c\
		$(SRC_DIR)/push_swap_command_add.c\
		$(SRC_DIR)/push_swap_command_zip.c\
		$(SRC_DIR)/push_swap_utile.c\

OBJ = $(SRC:.c=.o)
B_OBJ = $(B_SRC:.c=.o)

all : $(NAME)

bonus : $(B_NAME)

$(NAME) : $(OBJ)
	$(MAKE) -C $(LIB_DIR)
	$(MAKE) -C $(FPT_DIR)
	$(CC) $(FLAG) -o $@ $^ -L $(LIB_DIR) -lft -L $(FPT_DIR) -lftprintf

$(B_NAME) : $(B_OBJ)
	$(MAKE) -C $(LIB_DIR)
	$(MAKE) -C $(GNL_DIR)
	$(MAKE) -C $(FPT_DIR)
	$(CC) $(FLAG) -o $@ $^ -L $(LIB_DIR) -lft -L $(GNL_DIR) -lgnl -L $(FPT_DIR) -lftprintf 

%.o : %.c
	$(CC) $(FLAG) $(INCLUDE) -c $< -o $@

clean :
	$(MAKE) -C $(LIB_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean
	$(MAKE) -C $(FPT_DIR) clean
	rm -f $(OBJ) $(B_OBJ)

fclean : clean
	$(MAKE) -C $(LIB_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean
	$(MAKE) -C $(FPT_DIR) fclean
	rm -f $(NAME) $(B_NAME)

re : fclean all

.PHONY : all clean fclean re bonus
