NAME = push_swap

CC = cc
FLAGS = -Wall -Wextra -Werror

PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

SRCS = main.c \
       ft_init.c \
       utils.c \
       utils_lst.c \
       ft_disorder_index.c \
       flags.c \
       strategy.c \
       bench.c \
       ft_swap.c \
       ft_push.c \
       ft_rotate.c \
       ft_rev_rotate.c \
       ft_bubble.c \
       ft_mergesort.c \
       utils_merge.c \
       ft_chunksort.c \
       utils_chunk.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(PRINTF) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(PRINTF) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(FLAGS) -I $(PRINTF_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
