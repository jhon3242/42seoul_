NAME = pipex

CC = gcc
CFLAG = -Wall -Wextra -Werror
RM = rm -f

FT_DIR = ./lib/libft
GNL_DIR	= ./lib/get_next_line
FT = ft
GNL	= gnl

M_SRC = \
	./mandatory/pipex.c\
	./mandatory/path.c\
	./mandatory/fd_handling.c\
	./mandatory/error_handling.c\

B_SRC = \
	./bonus/pipex_bonus.c\
	./bonus/path_bonus.c\
	./bonus/here_doc_bonus.c\
	./bonus/fd_handling_bonus.c\
	./bonus/error_handling_bonus.c\


M_OBJ = $(M_SRC:.c=.o)
B_OBJ = $(B_SRC:.c=.o)

ifdef WITH_BONUS
	OBJ = $(B_OBJ)
else
	OBJ = $(M_OBJ)
endif

all : $(NAME)

bonus : $(B_OBJ)
	make WITH_BONUS=1 all

$(NAME) : $(OBJ)
	$(MAKE) -C $(FT_DIR)
	$(MAKE) -C $(GNL_DIR)
	$(CC) $(CFLAG) -o $@ $^ \
		-L$(FT_DIR) -l$(FT) \
		-L$(GNL_DIR) -l$(GNL)

clean : 
	$(MAKE) clean -C $(FT_DIR)
	$(MAKE) clean -C $(GNL_DIR)
	$(RM) $(M_OBJ)
	$(RM) $(B_OBJ)

fclean : clean
	$(MAKE) fclean -C $(FT_DIR)
	$(MAKE) fclean -C $(GNL_DIR)
	$(RM) $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re

