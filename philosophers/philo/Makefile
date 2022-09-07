# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: choewonjun <choewonjun@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/06 20:11:20 by choewonjun        #+#    #+#              #
#    Updated: 2022/09/07 16:14:09 by choewonjun       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

SRCS =	main.c\
		parsing.c\
		util.c\
		initialize.c\

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re