NAME = libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC =   ft_atoi.c\
        ft_isalnum.c\
        ft_isalpha.c\
        ft_isascii.c\
        ft_isdigit.c\
        ft_isprint.c\
        ft_memset.c\
        ft_strchr.c\
        ft_strlen.c\
        ft_strncmp.c\
        ft_strnstr.c\
        ft_strrchr.c\
        ft_tolower.c\
        ft_toupper.c\
        ft_memcpy.c\
        ft_bzero.c\
        ft_memchr.c\
        ft_memcmp.c\
        ft_strlcpy.c\
        ft_strlcat.c\
        ft_memmove.c\
        ft_strdup.c\
        ft_calloc.c\
        ft_substr.c\
        ft_strjoin.c\
        ft_strtrim.c\
        ft_putchar_fd.c\
        ft_putstr_fd.c\
        ft_putendl_fd.c\
        ft_putnbr_fd.c\
		error.c\
        ft_split.c\
        ft_strmapi.c\
        ft_striteri.c\
        ft_itoa.c\
		

OBJECT = ${SRC:.c=.o}


all : ${NAME}

${NAME} : ${OBJECT}
	ar -rc ${NAME} ${OBJECT}
        
clean :
	${RM} ${OBJECT}

fclean : clean
	${RM} ${NAME} 

re : fclean all

.PHONY:  all clean fclean re 
