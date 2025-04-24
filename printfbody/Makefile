SRCS	= ft_printf.c ft_putchar.c ft_putnbr_base_hexa.c ft_putnbr_decimal.c ft_putstr.c ft_see_format.c ft_strlen.c
OBJS	= ${SRCS:.c=.o}
NAME	= libftprintf.a
ARRCS	= ar rcs
CC		= cc
RM		= rm -f
CFLAGS	= -Wextra -Werror -Wall

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${ARRCS} ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean:
	${RM} ${NAME}

re: fclean all
