CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRCS=./ft_printf/*.c ./libft/*.c actions1.c check_args.c
OBJS=${SRCS:.c=.o}
NAME=push_swap
AR=ar -rc

# all:$(SRCS)
# 	$(CC) $(CFLAGS) -c ^$

all:
	gcc main.c actions1.c ./check_args.c ./libft/*.c ./ft_printf/*.c sort_3.c intiate_stacks.c repeat_instructions.c -o push_swap && ./push_swap 5 7 3 4 -7

com:
	gcc main.c $(SRCS)

# all:
# 	$(CC) $(CFLAGS) main.c $(SRCS) -o $(NAME) && ./$(NAME)

