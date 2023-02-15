NAME		=	push_swap

BONUS	=	checker

OBJS_DIR	=	objs

B_OBJS_DIR	=	objs/bonus

SRCS		=	main.c \
				bonus/GNL/get_next_line.c \
				bonus/GNL/get_next_line_utils.c \
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

SRCS_BONUS	=	main.c \
				checker.c

OBJS		=	${SRCS:%.c=${OBJS_DIR}/%.o}

OBJS_BONUS	=	${SRCS_BONUS:%.c=${B_OBJS_DIR}/%.o}

CC			=	clang

RM			=	rm -rf

GREEN		=	\033[1;32m

DEFAULT		=	\033[0m

CFLAGS		=	-Wall -Werror -Wextra -g3

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME}

$(BONUS):	${OBJS} ${OBJS_BONUS}
		${CC} ${CFLAGS} ${OBJS_BONUS} -o ${BONUS}

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR) :
	@ mkdir -p $@
	@ mkdir -p objs/bonus/GNL
	@ mkdir -p objs/bonus

all:		${NAME}

bonus:	${BONUS}

clean:		
		${RM} ${OBJS}
		${RM} ${OBJS_BONUS}
		${RM} ${OBJS_DIR}

fclean:		clean
		${RM} ${NAME}
		${RM} ${BONUS}
		@echo "\n${GREEN}Everything cleaned${DEFAULT}"

re:			fclean
		$(MAKE) all -j

.PHONY:		all clean fclean re bonus