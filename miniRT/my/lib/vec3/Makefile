# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 16:58:48 by wonjchoi          #+#    #+#              #
#    Updated: 2023/01/09 16:58:51 by wonjchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libvec.a

AR		= ar
ARFLAGS	= -crs
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

INCLUDE = -I.

SRC = \
	./color3.c\
	./point3.c\
	./vcross.c\
	./vdivide_k.c\
	./vdot.c\
	./vec3.c\
	./vlength.c\
	./vlength2.c\
	./vmin.c\
	./vminus.c\
	./vmult.c\
	./vmult_k.c\
	./vplus.c\
	./vset.c\
	./vunit.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^
	@ar crsu $(NAME) $@
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re