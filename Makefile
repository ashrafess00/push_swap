CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRCS=./ft_printf/*.c ./libft/*.c actions1.c check_args.c
OBJS=${SRCS:.c=.o}
NAME=push_swap
AR=ar -rc

# all:$(SRCS)
# 	$(CC) $(CFLAGS) -c ^$

all:
	gcc main.c $(SRCS) && ./a.out 2 1 3 6 5 8

com:
	gcc main.c $(SRCS)

# all:
# 	$(CC) $(CFLAGS) main.c $(SRCS) -o $(NAME) && ./$(NAME)
