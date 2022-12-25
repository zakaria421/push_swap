NAME = push_swap
BONUS = checker
FLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC =	push_swap.c\
		rules1.c\
		rules2.c\
		Sarr_and_size.c\
		Snumber_sort.c\
		maker.c\
		Bnumber.c\
		Bnumber2.c\
		
BONUS_SRC =	checker.c\
			get_next_line.c\
			get_next_line_utils.c\
			maker.c\
			Bounus_rules2.c\
			Bonus_rules.c\
			Bonus_rules3.c\
			


HEAD = -I push_swap.h
OBJECT=${SRC:.c=.o}
BOBJECT=${BONUS_SRC:.c=.o}
all: $(NAME)
$(NAME): $(OBJECT)
	make -C ./libft
	cc $(HEAD) $(OBJECT) ./libft/libft.a -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(BOBJECT)
	make -C ./libft
	cc $(HEAD) $(BOBJECT) ./libft/libft.a -o $(BONUS)

clean:
	make clean -C ./libft
	$(RM) $(OBJECT)
	$(RM) $(BOBJECT) 
	
fclean:
	make fclean -C ./libft
	$(RM) $(OBJECT) 
	$(RM) $(BOBJECT) 

re: fclean all	
