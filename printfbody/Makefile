SRCS	= ft_putnbr_decimal.c ft_see_format.c ft_printf.c ft_putnbr_base_hexa.c ft_printf_utils.c ft_putnbr_base_pointer.c ft_print_pt.c
OBJS	= ${SRCS:.c=.o}
NAME	= libftprintf.a
ARRCS	= ar rcs
CC		= cc
RM		= rm -f
CFLAGS	= -Wextra -Werror -Wall -g

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${ARRCS} ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
