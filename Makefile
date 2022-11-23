SRCS = ft_printf.c

OBJS = ${SRCS:.c=.o}

SRCS_B = ft_bzero.c ft_isalnum.c ft_memset.c ft_memcpy.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_strlen.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS_B = $(addprefix libft/, ${SRCS_B:.c=.o})

GCC = gcc -Wall -Wextra -Werror

NAME = libftprintf.a

.c.o :
		${GCC} -I libftprintf.h -c $< -o ${<:.c=.o}

$(NAME) : ${OBJS} ${OBJS_B}
		ar rcs ${NAME} ${OBJS} ${OBJS_B}

all : $(NAME)

clean:
		rm -f $(OBJS_B) ${OBJS}

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY : .c.o all clean fclean re
