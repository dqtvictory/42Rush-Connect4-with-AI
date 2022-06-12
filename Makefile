INC_DIR		= .

SRCS		=	./main.c \
				./utils.c \
				./libft/substr.c \
				./libft/memset.c \
				./libft/memccpy.c \
				./libft/strchr.c \
				./libft/42gc/ft_gc_ctx_delete.c \
				./libft/42gc/ft_gc_global.c \
				./libft/42gc/ft_gc_ptr_utils.c \
				./libft/42gc/ft_gc_ctx_create.c \
				./libft/42gc/ft_gc_static.c \
				./libft/42gc/ft_gc_ctx_transfer.c \
				./libft/42gc/ft_gc_ctx_wild_manip.c \
				./libft/memchr.c \
				./libft/strdup.c \
				./libft/strjoin.c \
				./libft/strlcpy.c \
				./libft/strlen.c \
				./libft/isalnum.c \
				./libft/isprint.c \
				./libft/strhas.c \
				./libft/atoi.c \
				./libft/split.c \
				./libft/bzero.c \
				./libft/toupper.c \
				./libft/tolower.c \
				./libft/memmove.c \
				./libft/memcpy.c \
				./libft/strnstr.c \
				./libft/isascii.c \
				./libft/strlcat.c \
				./libft/calloc.c \
				./libft/memcmp.c \
				./libft/putstr_fd.c \
				./libft/strncmp.c \
				./libft/putchar_fd.c \
				./libft/isdigit.c \
				./libft/strtrim.c \
				./libft/putnbr_fd.c \
				./libft/ft_printf/print_p.c \
				./libft/ft_printf/utils.c \
				./libft/ft_printf/checks.c \
				./libft/ft_printf/print_s.c \
				./libft/ft_printf/print_u.c \
				./libft/ft_printf/ft_printf.c \
				./libft/ft_printf/print_x.c \
				./libft/ft_printf/print_d.c \
				./libft/ft_printf/print_n.c \
				./libft/ft_printf/print_misc.c \
				./libft/ft_printf/print_c.c \
				./libft/putendl_fd.c \
				./libft/itoa.c \
				./libft/isalpha.c \
				./libft/strrchr.c \
				./libft/stridx.c \
				./libft/len_num.c \
				./libft/strmapi.c \
				./alpha_beta.c \
				./game.c \
				./loop.c \
				./winning.c \
				./evaluate.c\

OBJS		= $(SRCS:.c=.o)

NAME		= connect4

CC			= clang
FLAGS		= -Wall -Wextra -Werror -O3

RM			= rm -f

.cpp.o:
			@$(CC) $(FLAGS) -I$(INC_DIR) -c $< -o $(<:.cpp=.o)

$(NAME):	$(OBJS)
			@echo "Object files compiled"
			@$(CC) $(FLAGS) $(OBJS) -I$(INC_DIR) -o $(NAME)
			@echo "Executable created"
			@echo "Compilation finished"

all:		$(NAME)

clean:
			@$(RM) $(OBJS)
			@echo "Deleted all but executable"

fclean:		clean
			@$(RM) $(NAME)
			@echo "Everything deleted"

re:			fclean all

.PHONY:		all clean fclean re
