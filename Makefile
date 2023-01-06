# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 16:27:55 by aessaoud          #+#    #+#              #
#    Updated: 2022/12/27 14:10:08 by aessaoud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -rf

INC=-I./headers/
BONUS_NAME=checker
ARGS=  1000 "68 44 70 55 26 24 59 13 4 10 80 16 81 12 2 47 84 19 82 50 99 76 28 65 39 38 1 85 7 40 67 45 56 94 42 91 20 69 6 52 17 98 79 37 92 95 53 21 97 8 90 83 11 29 78 23 36 75 93 35 73 74 66 88 51 54 25 43 49 9 30 33 34 58 72 60 32 5 3 22 48 31 64 77 46 86 15 41 18 0 27 100 71 89 63 62 14 87 61 57"

LIBFT_DIR=libft/
LIBFT_A=$(LIBFT_DIR)libft.a
OBJS_DIR=objs/
BONUS_OBJS_DIR=bonus_objs/

SRCS_DIR=srcs/
BONUS_SRCS_DIR=bonus/

SRCS_LIST=main.c check_args.c check_args_2.c instructions1.c instructions2.c print_stacks.c sort_3.c repeat_instructions.c sort_big.c rotate_with.c find_pos.c push_all_to_a_b.c free_all.c initiate_stacks.c errors.c
BONUS_SRCS_LIST=main.c check_args_bonus.c check_args_2_bonus.c instructions1_bonus.c instructions2_bonus.c print_stacks_bonus.c free_all_bonus.c sort_bonus.c initiate_stacks_bonus.c errors_bonus.c


# OBJ_LIST=$(SRCS_LIST:.c=.o)
OBJS=$(addprefix $(OBJS_DIR), $(SRCS_LIST:.c=.o))

BONUS_OBJ_LIST=$(BONUS_SRCS_LIST:.c=.o)
BONUS_OBJS=$(addprefix $(BONUS_OBJS_DIR), $(BONUS_OBJ_LIST))

LEAKS_CHECKER=leacks_cheker_ex.c

all:$(OBJS_DIR) $(NAME)
	
$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)
	
$(NAME):$(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)
	
$(OBJS_DIR)%.o:$(SRCS_DIR)%.c
	$(CC) $(CFLAGS) $(INC) -c -o  $@ $^
	

bonus:$(BONUS_OBJS_DIR) $(BONUS_NAME)

$(BONUS_OBJS_DIR):
	mkdir -p $(BONUS_OBJS_DIR)
	
$(BONUS_NAME):$(BONUS_OBJS) $(LIBFT_A)
	gcc $(BONUS_OBJS) $(LIBFT_A) -o $(BONUS_NAME)


$(BONUS_OBJS_DIR)%.o:$(BONUS_SRCS_DIR)%.c
	gcc $(INC) -c -o  $@ $^

check: all
	./$(NAME) $(ARGS) | ./checker_Mac $(ARGS)
	
clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS_DIR)
	$(RM) $(BONUS_OBJS_DIR)

fclean:clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)
	
	
.PHONY:bonus check clean fclean