NAME		=	push_swap

OBJS_DIR	=	objs

SRCS		=	main.c \
				GNL/get_next_line.c \
				GNL/get_next_line_utils.c \
				big_sort.c \
				cost.c \
				double_operations.c \
				create.c \
				free.c \
				operations.c \
				parsing.c \
				search_pos.c \
				setup_stack.c \
				sort_small.c \
				utils.c
				
OBJS		=	${SRCS:%.c=${OBJS_DIR}/%.o}

CC			=	clang

RM			=	rm -rf

GREEN		=	\033[1;32m

DEFAULT		=	\033[0m

CFLAGS		=	-Wall -Werror -Wextra -g3

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME}

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR) :
	@ mkdir -p $@
	@ mkdir -p objs/GNL

all:		${NAME}

clean:		
		${RM} ${OBJS}
		${RM} ${OBJS_DIR}

fclean:		clean
		${RM} ${NAME}
		@echo "\n${GREEN}Everything cleaned${DEFAULT}"

re:			fclean
		$(MAKE) all -j

.PHONY:		all clean fclean re