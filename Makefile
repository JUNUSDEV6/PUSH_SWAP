NAME = push_swap
SRCS = checker.c ft_check_form.c ft_printf.c ft_printf_utils.c \
       split.c error.c sort_stack.c sort_three.c push.c \
       rev_rotate.c rotate.c swap.c init_a_to_b.c \
       init_b_to_a.c init_stack.c init_utils.c 

OBJS = ${SRCS:.c=.o}
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

# Utilisation de variables automatiques pour rendre le Makefile plus extensible
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
