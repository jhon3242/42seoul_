# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 15:31:33 by wonjchoi          #+#    #+#              #
#    Updated: 2022/12/02 15:33:32 by wonjchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=Identify

CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror

SRCS = main.cpp\
	   A.cpp\
	   B.cpp\
	   C.cpp\
	   Base.cpp

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.cpp
	$(CC) $(CFLAGS) -c -o $@ $^

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS)
	rm -f $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re
