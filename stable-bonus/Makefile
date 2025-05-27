SRCS	= ft_flags.c ft_flags_helper.c ft_flags_helper2.c ft_indent.c ft_itoa.c ft_itoa_base.c ft_itoa_pt.c ft_printf.c ft_printf_utils.c ft_printf_utils2.c ft_see_format.c ft_sub_cpy.c 
OBJS	= ${SRCS:.c=.o}
NAME	= libftprintf.a
ARRCS	= ar rcs
CC		= cc
CFLAGS	= -Wextra -Werror -Wall -g
RM		= rm -f

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

.PHONY: all bonus clean fclean re d
