NAME = push_swap
CHECKER = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRCS = $(wildcard src/*.c src/algo/*.c src/operation/*.c src/parsing/*.c src/utils/*.c)
OBJS = $(SRCS:.c=.o)

BONUS_SRCS = bonus/checker.c bonus/swap_silent.c bonus/rotate_silent.c bonus/reverse_rotate.c bonus/push_silente.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CHECKER_SRCS = $(filter-out src/main.c, $(SRCS)) $(BONUS_SRCS)
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

bonus: $(CHECKER)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -Iinclude -o $(NAME) $(OBJS)

$(CHECKER): $(CHECKER_OBJS)
	$(CC) $(CFLAGS) -Iinclude -o $(CHECKER) $(CHECKER_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

clean:
	@rm -f $(OBJS) $(CHECKER_OBJS)

fclean: clean
	@rm -f $(NAME) $(CHECKER)

re: fclean all

