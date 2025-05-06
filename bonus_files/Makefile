SRCS	= ft_itoa.c ft_itoa_base.c ft_flags_helper.c ft_printf_utils2.c ft_see_format.c main.c ft_printf.c ft_printf_utils.c ft_flags.c ft_indent.c 
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

bonus: all

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

d: all clean

.PHONY: all bonus clean fclean re d
