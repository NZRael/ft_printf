SRCS = 

OBJS = ${SRCS:.c=.o}

GCC = gcc -Wall -Wextra -Werror

NAME = libftprintf.a

INCLUDES = -I libft , libftprintf.h

.c.o :
		${GCC} ${INCLUDES} -c $< -o ${<:.c=.o}

$(NAME) : ${OBJS}
		ar rcs ${NAME} ${OBJS}

all : $(NAME)

clean:
		rm -f *.o

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY : .c.o all clean fclean re
