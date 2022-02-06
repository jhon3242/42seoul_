CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRC = ft_printf.c\
		print_hex.c\
		print_pointer.c\
		print_unsigned_int.c\
		print_utils.c\

OBJ = $(SRC:.c=.o)

INC_LINK = -I./includes

all : $(NAME)

$(NAME) : $(OBJ) libft
	cp libft/libft.a ./$(NAME)
	ar rcs $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(FLAGS) $(INC_LINK) -c $< -o $@

libft :
	$(MAKE) -C ./libft all

clean :
	$(MAKE) -C ./libft clean
	rm -f $(OBJ)

fclean : 
	$(MAKE) -C ./libft fclean
	rm -f $(NAME) $(OBJ)

re : fclean all

.PHONY : libft clean fclean re all