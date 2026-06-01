NAME = push_swap.a

SRCS = ft_atoi.c\
       ft_lstnew.c\
       ft_check_args.c\
       ft_push.c\
       ft_rev_rotate.c\
       ft_rotate.c\
       ft_swap.c\
       main.c\

OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
%.o: %.c push_swap.h
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re 
