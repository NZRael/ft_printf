SRCS = ft_printf.c ft_arguments.c
OBJS = ${SRCS:.c=.o}
GCC = gcc -Wall -Wextra -Werror
NAME = libftprintf.a
HEAD = -I ft_printf.h
MAKE = make

all : $(NAME)

$(NAME) :
		@${MAKE} bonus -C libft
		@cp libft/libft.a ${NAME}
		@${GCC} ${HEAD} -c ${SRCS}
		ar -rcs ${NAME} ${OBJS}

clean:
		rm -f ${OBJS}
		@${MAKE} clean -C libft

fclean:
		rm -f ${OBJS}
		rm -f $(NAME)
		@${MAKE} fclean -C libft

re: fclean all

.PHONY : all clean fclean re
