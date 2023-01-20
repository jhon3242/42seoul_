# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 13:58:19 by wonjchoi          #+#    #+#              #
#    Updated: 2023/01/20 16:40:22 by wonjchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= miniRT

CC		= cc
CFLAGS	= #-Wall -Wextra -Werror
MFLAGS	= -framework OpenGL -framework AppKit

MLX_DIR	= ./lib/libmlx
MLX 	= mlx

VEC_DIR	= ./lib/vec3
VEC		= vec

INCLUDE = -I./include

SRC_DIR = ./

SRC =  main.c \
		parser/parser.c \
		mlx/ft_mlx.c \
		utils/util_libft.c \
		utils/util_libft2.c \
		utils/util_object.c \
		utils/util.c \
		object/ambient.c \
		object/camera.c \
		object/cylinder.c \
		object/light.c\
		object/object.c \
		object/plane.c \
		object/sphere.c\
		trace/hit_object.c \
		trace/hit.c \
		trace/phong_lighting.c \
		trace/ray.c \
		validator/valid_check.c \
		validator/valid_check_cnt.c \
		validator/valid_object_must.c \
		validator/valid_object.c \
		validator/valid_util.c \
		validator/validator.c \
		utils/ft_malloc.c\
		utils/ft_open.c\
		# validator/valid_check.c \
		# validator/valid_object_cnt.c \
		# validator/valid_object_environment.c \
		# validator/valid_object.c \
		# validator/valid_util.c \
		# validator/validator.c \
		# utils/util_libft.c \
		# utils/util_libft2.c \
		# utils/util_object.c \
		# utils/util.c \

OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(MLX_DIR)
	$(MAKE) -C $(VEC_DIR)
	$(CC) $(CFLAGS) -o $@ $^ \
		-L$(MLX_DIR) -l$(MLX) $(MFLAGS) \
		-L$(VEC_DIR) -l$(VEC)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $^

clean:
	$(MAKE) clean -C $(MLX_DIR)
	$(MAKE) clean -C $(VEC_DIR)
	rm -f $(OBJ)
	rm -f $(OBJ_BNS)

fclean: clean
	$(MAKE) fclean -C $(VEC_DIR)
	rm -f $(NAME)
	rm -f bonus

re: fclean all

.PHONY: all clean fclean re