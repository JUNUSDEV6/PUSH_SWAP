NAME = push_swap
CHECKER = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRCDIR = src
INCDIR = include
BONUSDIR = bonus

SOURCES = src/main.c \
		  src/parsing/init_stack.c \
		  src/utils/ft_split.c \
		  src/utils/utils.c \
		  src/operations/swap.c \
		  src/operations/push.c \
		  src/operations/rotate.c \
		  src/algo/push_swap.c \
		  src/algo/sort_small.c \
		  src/algo/sort_big.c

BONUS_SOURCES = bonus/checker.c \
				bonus/operations_silent.c \
				src/parsing/init_stack.c \
				src/utils/ft_split.c \
				src/utils/utils.c

OBJECTS = $(SOURCES:.c=.o)
BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

bonus: $(CHECKER)

$(CHECKER): $(BONUS_OBJECTS)
	$(CC) $(CFLAGS) -o $(CHECKER) $(BONUS_OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: all bonus clean fclean re