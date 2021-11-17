CC = gcc
CFLAGS = -Wall -Wextra -Werror

TARGET = libft.a
HEAD = ft.h
INCLUDES = ./libft.h
SOURCE = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c
OBJECTS = $(SOURCE:.c=.o)

all : $(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@


$(TARGET) : $(OBJECTS)
	ar rc $@ $^
	
clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(TARGET)

re : fclean all
