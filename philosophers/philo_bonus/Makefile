# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/09 16:49:50 by wonjchoi          #+#    #+#              #
#    Updated: 2022/09/11 15:21:06 by wonjchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo_bonus

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

SRCS =	main.c\
		observe.c\
		util.c\
		parsing.c\
		semaphore.c\
		semaphore_util.c\
		running.c\
		routine.c\
		routine_util.c\

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