# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 16:27:55 by aessaoud          #+#    #+#              #
#    Updated: 2023/01/18 12:59:49 by aessaoud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
CC=gcc
CFLAGS=-Wall -Wextra -Werror 
CFLAGS=
RM=rm -rf

INC=-I./headers/
BONUS_NAME=checker
ARGS= 88 16 75 89 60 57 79 77 80 13 46 78 47 40 35 86 94 33 4 20 18 45 23 19 55 96 7 64 42 90 51 73 10 50 70 53 43 14 84 95 83 66 30 71 82 39 98 2 9 100 25 28 48 92 68 32 29 85 97 72 74 37 69 11 91 3 49 6 41 1 22 61 27 56 62 34 26 0 17 44 93 12 67 81 24 76 54 63 52 59 15 5 8 99 87 38 58 31 36 65

LIBFT_DIR=libft/
LIBFT_A=$(LIBFT_DIR)libft.a
OBJS_DIR=objs/
BONUS_OBJS_DIR=bonus_objs/

SRCS_DIR=srcs/
BONUS_SRCS_DIR=bonus/

SRCS_LIST=main.c check_args_1.c check_args_2.c instructions1.c instructions2.c instructions3.c sort_3.c repeat_instructions1.c repeat_instructions2.c sort_big.c rotate_with.c find_pos.c push_all_to_a_b.c free_all.c initiate_stacks.c errors.c push_pop.c utils.c
BONUS_SRCS_LIST=main_bonus.c check_args_1_bonus.c check_args_2_bonus.c errors_bonus.c initiate_stacks_bonus.c instructions1_bonus.c instructions2_bonus.c instructions3_bonus.c push_pop_bonus.c sort_bonus.c free_all_bonus.c utils_bonus.c

HEADERS_DIR=headers/

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
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT_A) -o $(BONUS_NAME)


$(BONUS_OBJS_DIR)%.o:$(BONUS_SRCS_DIR)%.c
	$(CC) $(CFLAGS) $(INC) -c -o  $@ $^

check: all
	./$(NAME) $(ARGS) | ./checker_Mac $(ARGS)

check_ins:
	./$(NAME) $(ARGS) | wc -l
	
clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS_DIR)
	$(RM) $(BONUS_OBJS_DIR)

fclean:clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)
	
re: fclean all	

norm:
	norminette $(SRCS_DIR) $(HEADERS_DIR) $(LIBFT_DIR) $(BONUS_SRCS_DIR)
	
.PHONY:bonus check clean fclean norm