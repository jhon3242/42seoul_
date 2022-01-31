CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRC_NAME = ft_printf.c
SRC_PATH = ./srcs
SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

# OBJ_NAME = $(SRC_NAME:.c=.o)
# OBJ_PATH = ./objs
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