INC_DIR		= .
SRC_DIR		= .

SRC_NAMES	= atoi.c bzero.c calloc.c isalnum.c isalpha.c isascii.c \
			isdigit.c isprint.c itoa.c memccpy.c memchr.c memcmp.c \
			memcpy.c memmove.c memset.c putchar_fd.c putendl_fd.c \
			putnbr_fd.c putstr_fd.c split.c strchr.c strdup.c strjoin.c \
			strlcat.c strlcpy.c strlen.c strmapi.c strncmp.c strnstr.c \
			strrchr.c strtrim.c substr.c tolower.c toupper.c \
			len_num.c putnbr_fd.c strhas.c stridx.c
SRCS		= $(addprefix $(SRC_DIR)/, $(SRC_NAMES))
OBJS		= ${SRCS:.c=.o}

NAME		= libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -I ${INC_DIR} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re