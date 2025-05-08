SRC_DIR	= ./srcs/
INC_DIR	= ./includes/

SRC		= ft_putchar.c ft_putstr.c ft_strlen.c ft_strcmp.c ft_swap.c

SRCS	= ${addprefix ${SRC_DIR}, ${SRC}}
OBJS	= ${SRCS:.c=.o}

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

LIB		= libft.a

AR		= ar rc
ID		= ranlib
RM		= rm -f


all:	${LIB}

.c.o:
		${CC} ${CFLAGS} -c -I ${INC_DIR} $< -o ${<:.c=.o}

${LIB}:	${OBJS}
		${AR} ${LIB} ${OBJS}
		${ID} ${LIB}

clean: 
		${RM} ${OBJS}

fclean:	clean
		${RM} ${LIB}

re:		fclean all

.PHONY:	all clean fclean re
