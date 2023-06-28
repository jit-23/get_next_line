
NAME =  comp.a
CFLAGS = -Wall -Werror -Wextra
CC = cc
FUN =     get_next_line.c       get_next_line_utils.c
FUN_B =   get_next_line_bonus.c get_next_line_utils_bonus.c 

OBJS = ${FUN:.c=.o}
OBJS_B = ${FUN_B:.c=.o}

all: ${NAME}

${NAME}:
		${CC} ${CFLAGS} -c ${FUN}
		ar rc ${NAME} ${OBJS}

clean:
		rm -f ${OBJS} ${OBJS_B}

fclean: clean
		rm -f ${NAME}
bonus:
		${CC} ${FLAGS}  -c ${FUN_B}
		ar rcs ${NAME} ${OBJ_B}

re: fclean all

.PHONY: all clean fclean re
