NAME = push_swap
SRCS = checker.c ft_check_form.c ft_printf.c ft_printf_utils.c \
       split.c error.c sort_stack.c three_stack.c push.c \
       rev_rotate.c rotate.c swap.c algo_a_to_b.c \
       algo_b_to_a.c init_stack.c utils_stack.c 

OBJS = ${SRCS:.c=.o}
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${CC} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
