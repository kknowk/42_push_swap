NAME = push_swap
CC = cc
INCLUDES_DIR = ./Includes
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES_DIR)

SRCS = srcs/main.c \
	srcs/utils/utils.c \
	srcs/error_free/error_handlig.c \
	srcs/error_free/free_return.c \
	srcs/opperation/create_compression.c \
	srcs/opperation/operation_stack_1.c \
	srcs/order/order_a.c \
	srcs/order/order_b.c \
	srcs/order/order_double.c \
	srcs/under_6/only_3_numbers.c \
	srcs/under_6/under_6_numbers.c \
	srcs/kiniku_sort/kinniku.c \
	srcs/kiniku_sort/protein.c

OBJS = $(SRCS:%.c=%.o)

LIBDIR = ./libft
LIBFT = $(LIBDIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBDIR)

clean:
	$(MAKE) fclean -C $(LIBDIR)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
