SRCS = ./ft_bzero.c ./ft_isalnum.c ./ft_memset.c ./ft_memcpy.c ./ft_isalpha.c ./ft_isascii.c ./ft_isdigit.c ./ft_isprint.c ./ft_strlen.c ./ft_memmove.c ./ft_strlcpy.c ./ft_strlcat.c ./ft_toupper.c ./ft_tolower.c ./ft_strchr.c ./ft_strrchr.c ./ft_strncmp.c ./ft_memchr.c ./ft_memcmp.c ./ft_strnstr.c ./ft_atoi.c ./ft_calloc.c ./ft_strdup.c ./ft_substr.c ./ft_strjoin.c ./ft_strtrim.c ./ft_split.c ./ft_itoa.c ./ft_strmapi.c ./ft_striteri.c ./ft_putchar_fd.c ./ft_putstr_fd.c ./ft_putendl_fd.c ./ft_putnbr_fd.c
BONUS = ./ft_lstnew.c ./ft_lstadd_front.c ./ft_lstsize.c ./ft_lstlast.c ./ft_lstadd_back.c ./ft_lstdelone.c ./ft_lstclear.c ./ft_lstiter.c ./ft_lstmap.c
OBJS = ${SRCS:.c=.o}
OBJ = ${OBJS} ${BONUS:.c=.o}
FLAGS =  -Wall -Wextra -Werror
GCC = gcc
NAME = libft.a
HEAD = libft.h

all : $(NAME)

$(NAME) : ${HEAD}
		@${GCC} -c ${SRCS} ${FLAGS}
		ar -rcs ${NAME} ${OBJS}

bonus : ${HEAD}
		@${GCC} -c ${SRCS} ${BONUS} ${FLAGS}
		ar -rcs ${NAME} ${OBJ}

clean:
		rm -f ${OBJ}

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY : all bonus clean fclean re
