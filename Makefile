NAME = push_swap
FLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC =	linkdlist.c\
		rules1.c\
		rules2.c\
		Sarr_and_size.c\
		Snumber_sort.c\
		maker.c\
		Bnumber.c\
		Bnumber2.c\
		


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
