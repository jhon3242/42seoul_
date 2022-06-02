CC = gcc
FLAG = -Wall -Wextra -Werror
NAME = push_swap
LIB_DIR = libft/

SRC = push_swap.c\
		push_swap_node.c\
		push_swap_stack.c\
		push_swap_a_to_b.c\
		push_swap_b_to_a.c\
		push_swap_do_op.c\
		push_swap_node.c\
		push_swap_parsing.c\
		push_swap_pivot.c\
		push_swap_sort.c\
		push_swap_sort_utile.c\
		push_swap_atoi_and_nullck.c\

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(MAKE) -C $(LIB_DIR)
	$(CC) $(FLAG) -o $@ $^ -L $(LIB_DIR) -lft

%.o : %.c
	$(CC) $(FLAG) -c $< -o $@

clean :
	$(MAKE) -C ./libft clean
	rm -f $(OBJ)

fclean : clean
	$(MAKE) -C ./libft fclean
	rm -f $(NAME) $(OBJ)

re : fclean all

.PHONY : all libft clean fclean re