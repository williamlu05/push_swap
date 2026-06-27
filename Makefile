NAME = push_swap
BONUS = checker

CC = cc
FLAGS = -Wall -Wextra -Werror

PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

GNL_DIR = get_next_line

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
       sort_small.c \
       ft_bubble.c \
       ft_radixsort.c \
       ft_chunksort.c \
       utils_chunk.c \

BONUS_SRCS = main_bonus.c \
             ft_init_bonus.c \
             utils_bonus.c \
             utils_lst_bonus.c \
             ft_swap_bonus.c \
             ft_push_bonus.c \
             ft_rotate_bonus.c \
             ft_rev_rotate_bonus.c \
             $(GNL_DIR)/get_next_line.c \
             $(GNL_DIR)/get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

bonus: $(BONUS)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(PRINTF) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(PRINTF) -o $(NAME)

$(BONUS): $(BONUS_OBJS)
	$(CC) $(FLAGS) $(BONUS_OBJS) -o $(BONUS)

%.o: %.c push_swap.h
	$(CC) $(FLAGS) -I $(PRINTF_DIR) -c $< -o $@

$(BONUS_OBJS): %.o: %.c checker_bonus.h
	$(CC) $(FLAGS) -I $(GNL_DIR) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re
