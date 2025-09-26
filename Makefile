NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRCDIR = src
INCDIR = include

SOURCES = src/main.c \
		  src/parsing/init_stack.c \
		  src/utils/ft_split.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re