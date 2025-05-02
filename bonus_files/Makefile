SRCS	= ft_itoa_base.c ft_see_format.c ft_printf_utils.c ft_printf.c ft_putstr.c ft_flags.c ft_mem_alloc.c ft_itoa.c 
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
