SRC_DIR	= ./srcs/
INC_DIR	= ./includes/

SRC		= main.c ft_hexdump.c ft_print.c ft_print_option.c ft_error.c ft_option.c ft_utils.c

SRCS	= ${addprefix ${SRC_DIR}, ${SRC}}
OBJS	= ${SRCS:.c=.o}

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

NAME	= ft_hexdump

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
