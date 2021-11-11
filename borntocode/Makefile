CC = gcc
CFLAGS = -Wall -Wextra -Werror

TARGET = a.out
HEAD = ft.h
SOURCE = main.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c
OBJECTS = $(SOURCE:.c=.o)

all = $(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) -c $<


$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $^ $(HEAD)
	
clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(TARGET)

re : fclean all
