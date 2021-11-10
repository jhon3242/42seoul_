CC = gcc
CFLAGS = -Wall -Wextra -Werror

TARGET = a.out
SOURCE = main.c ft_isalpha.c ft.h 
OBJECTS = $(SOURCE:.c=.o)

all = $(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@


$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@
	
clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(TARGET)

re : fclean all
