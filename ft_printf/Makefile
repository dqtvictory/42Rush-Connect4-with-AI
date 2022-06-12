LIBFT_DIR	= ../libft
LIBFT_FNAME	= libft.a

LIBS_DIR	= ../libs

SRCS	=	checks.c ft_printf.c print_c.c \
			print_d.c print_misc.c print_n.c \
			print_p.c print_s.c print_u.c \
			print_x.c utils.c

OBJS	=	${SRCS:.c=.o}

NAME		= libftprintf.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			make -C ${LIBFT_DIR}
			mv ${LIBFT_DIR}/${LIBFT_FNAME} ${NAME}
			ar -rcs ${NAME} ${OBJS}
			ranlib ${NAME}
			mkdir -p ${LIBS_DIR}
			mv ${NAME} ${LIBS_DIR}

all:		${NAME}

clean:
			make -C ${LIBFT_DIR} clean
			rm -f ${OBJS}

fclean:		clean
			make -C ${LIBFT_DIR} fclean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re makelib
