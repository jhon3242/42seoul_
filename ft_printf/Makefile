CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
HEADER = includes/ft_printf.h
LIBDIR = libft/

SRC = ft_printf.c\
		print_hex.c\
		print_pointer.c\
		print_unsigned_int.c\
		print_utils.c\

OBJ = $(SRC:.c=.o)
INC_LINK = -I./includes


all : $(NAME)

$(NAME) : $(OBJ)
	$(MAKE) -C $(LIBDIR) all
	cp ./libft/libft.a ./$(NAME)
	ar rcs $(NAME) $^

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) $(INC_LINK) -c $< -o $@

clean :
	$(MAKE) -C ./libft clean
	rm -f $(OBJ)

fclean : 
	$(MAKE) -C ./libft fclean
	rm -f $(NAME) $(OBJ)

re : fclean all

.PHONY : all libft clean fclean re