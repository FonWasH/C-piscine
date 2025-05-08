SRC_DIR	= ./srcs/
INC_DIR	= ./includes/

SRC		= main.c ft_cat.c ft_error.c ft_putstr.c

SRCS	= ${addprefix ${SRC_DIR}, ${SRC}}
OBJS	= ${SRCS:.c=.o}

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

NAME	= ft_cat

RM		= rm -f


all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -c -I ${INC_DIR} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o $@ ${OBJS}

clean: 
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

.PHONY: 	all clean fclean
