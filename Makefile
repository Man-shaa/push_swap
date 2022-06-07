NAME = push_swap

SRCS =	lst_utils.c \
		lst_utils2.c \
		main.c \
		operation.c \
		parsing.c \
		tri_utils.c \
		radix_sort.c

OBJS = ${SRCS:.c=.o}

FLAGS = -Wall -Werror -Wall

RM = rm -rf

${NAME}: ${OBJS}
	gcc -g3 ${SRCS} -o $@

all: ${NAME}

.c.o:
	gcc $(FLAGS) -c $< -o $(<:.c=.o)

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} push_swap

re: fclean all

.PHONY: clean fclean re all 