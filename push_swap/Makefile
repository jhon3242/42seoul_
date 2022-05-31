CC = gcc
FLAG = -Wall -Wextra -Werror
NAME = push_swap
LIBDIR = libft/

SRC = push_swap.c\
		push_swap_node.c\
		push_swap_stack.c\

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(MAKE) -C $(LIBDIR) all
	cp ./libft/libft.a ./$(NAME)
	ar rcs $(NAME) $^

$%.o : %.c:
	$(CC) $(FLAG) -c $< -o $@

clean :
	$(MAKE) -C ./libft clean
	rm -f $(OBJ)

fclean : clean
	$(MAKE) -C ./libft fclean
	rm -f $(NAME) $(OBJ)

re : fclean all

.PHONY : all libft clean fclean re