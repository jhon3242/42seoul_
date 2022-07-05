# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/02 21:18:27 by wonjchoi          #+#    #+#              #
#    Updated: 2022/07/05 17:48:37 by wonjchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
FLAG = 
MLX_FLAG = -framework OpenGL -framework AppKit


SRC_DIR = src
LIB_DIR = lib/libft/
GNL_DIR = lib/libgnl/
MLX_DIX = lib/libmlx/
INCLUDE = -I./include


SRC = $(SRC_DIR)/so_long.c\
		$(SRC_DIR)/so_long_map.c\
		$(SRC_DIR)/so_long_init_game.c\
		$(SRC_DIR)/so_long_check.c\
		$(SRC_DIR)/so_long_util.c\
		$(SRC_DIR)/so_long_player.c\
		$(SRC_DIR)/so_long_img.c\
		$(SRC_DIR)/so_long_draw.c\
		
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(MAKE) -C $(LIB_DIR)
	$(MAKE) -C $(GNL_DIR)
	$(MAKE) -C $(MLX_DIX)
	$(CC) $(FLAG) -o $@ $^ \
		-L $(LIB_DIR) -lft \
		-L $(GNL_DIR) -lgnl \
		-L $(MLX_DIX) -lmlx $(MLX_FLAG)
		


%.o : %.c
	$(CC) $(FLAG) $(INCLUDE) -c $< -o $@

clean :
	$(MAKE) -C $(LIB_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean
	$(MAKE) -C $(MLX_DIX) clean
	rm -f $(OBJ)

fclean : clean
	$(MAKE) -C $(LIB_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re all