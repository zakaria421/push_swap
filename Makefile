NAME = push_swap
FLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC =	linkdlist.c


HEAD = -I push_swap.h
OBJECT=${SRC:.c=.o}
all: $(NAME)
$(NAME): $(OBJECT)
	make -C ./libft
	cc $(HEAD) $(OBJECT) ./libft/libft.a -o $(NAME)

clean:
	make clean -C ./libft
	$(RM) $(OBJECT)
	
fclean:
	make fclean -C ./libft
	$(RM) $(OBJECT) 

re: fclean all	
