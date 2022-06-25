# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 23:52:28 by wonjchoi          #+#    #+#              #
#    Updated: 2022/06/26 01:10:38 by wonjchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap
B_NAME = checker

CC = gcc
FLAG = -Wall -Wextra -Werror

LIB_DIR = libft/
GNL_DIR = get_next_line/
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
	$(CC) $(FLAG) -o $@ $^ -L $(LIB_DIR) -lft

$(B_NAME) : $(B_OBJ)
	$(MAKE) -C $(LIB_DIR)
	$(MAKE) -C $(GNL_DIR)
	$(CC) $(FLAG) -o $@ $^ -L $(LIB_DIR) -lft -L $(GNL_DIR) -lgnl

%.o : %.c
	$(CC) $(FLAG) $(INCLUDE) -c $< -o $@

clean :
	$(MAKE) -C $(LIB_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean
	rm -f $(OBJ)

fclean : clean
	$(MAKE) -C $(LIB_DIR) fclean
	$(MAKE) -C $(GNL_DIR) clean
	rm -f $(NAME) $(OBJ)

re : fclean all

.PHONY : all libft clean fclean re