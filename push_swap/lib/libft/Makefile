CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

NAME = libft.a
INCLUDES = ./libft.h
SOURCE = ft_atoi.c\
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_strcmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \

SOURCE_B = ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c


OBJECTS = $(SOURCE:.c=.o)
OBJECTS_b = $(SOURCE_B:.c=.o)

ifdef WITH_BONUSE
	OBJECT_FILES = $(OBJECTS) $(OBJECTS_b)
else
	OBJECT_FILES = $(OBJECTS)
endif

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJECT_FILES)
	$(AR) $@ $^

bonus : 
	make WITH_BONUSE=1 all

clean :
	rm -f $(OBJECTS) $(OBJECTS_b)

fclean : clean
	rm -f $(NAME)

re : fclean all

 .PHONY: bonus all clean fclean re
