NAME = pipex

CC = gcc
CFLAG = # -Wall -Wextra -Werror
RM = rm -f

FT_DIR = ./lib/libft
FT = ft


M_SRC = \
	./mandatory/pipex.c\
	./mandatory/path.c\
	./mandatory/fd_handling.c\
	./mandatory/error_handling.c\

M_OBJ = $(M_SRC:.c=.o)

ifdef WITH_BONUS
	OBJ = $(B_OBJ)
else
	OBJ = $(M_OBJ)
endif

all : $(NAME)

$(NAME) : $(OBJ)
	$(MAKE) -C $(FT_DIR)
	$(CC) $(CFLAG) -o $@ $^ \
		-L$(FT_DIR) -l$(FT)

clean : 
	$(MAKE) clean -C $(FT_DIR)
	$(RM) $(M_OBJ)

fclean : clean
	$(MAKE) fclean -C $(FT_DIR)
	$(RM) $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re

