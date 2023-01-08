

NAME = study

CC = gcc
FLAG = 

SRC_DIR = src

INCLUDE = -I./include

SRC = $(SRC_DIR)/main.c\
		$(SRC_DIR)/print.c\
		$(SRC_DIR)/utils.c\
		$(SRC_DIR)/sence/canvas.c\
		$(SRC_DIR)/sence/object_create.c\
		$(SRC_DIR)/sence/sence.c\
		$(SRC_DIR)/trace/hit/hit_sphere.c\
		$(SRC_DIR)/trace/hit/hit.c\
		$(SRC_DIR)/trace/hit/normal.c\
		$(SRC_DIR)/trace/ray/ray.c\
		$(SRC_DIR)/trace/ray/phong_lighting.c\
		$(SRC_DIR)/utils/object_utils.c\
		


OBJ = $(SRC:.c=.o)

all : $(NAME)


$(NAME) : $(OBJ)
	$(CC) $(FLAG) -o $@ $^

$(B_NAME) : $(B_OBJ)
	$(CC) $(FLAG) -o $@ $^

%.o : %.c
	$(CC) $(FLAG) $(INCLUDE) -c $< -o $@

clean :
	rm -f $(OBJ) $(B_OBJ)

fclean : clean
	rm -f $(NAME) $(B_NAME)

re : fclean all

.PHONY : all clean fclean re bonus