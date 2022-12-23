# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 16:27:55 by aessaoud          #+#    #+#              #
#    Updated: 2022/12/23 19:48:35 by aessaoud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap

INC=-I./headers/
BONUS_NAME=checker
ARGS=  "100 83 17 1 0 -9 461 64"

LIBFT_DIR=libft/
LIBFT_A=$(LIBFT_DIR)libft.a
OBJS_DIR=objs/
BONUS_OBJS_DIR=bonus_objs/

SRCS_DIR=srcs/
BONUS_SRCS_DIR=bonus/

SRCS_LIST=main.c check_args.c instructions1.c instructions2.c print_stacks.c sort_3.c repeat_instructions.c sort_big.c rotate_with.c find_pos.c push_all_to_a_b.c free_stacks.c
BONUS_SRCS_LIST=main.c check_args_bonus.c instructions1_bonus.c instructions2_bonus.c print_stacks_bonus.c


OBJ_LIST=$(SRCS_LIST:.c=.o)
OBJS=$(addprefix $(OBJS_DIR), $(OBJ_LIST))

BONUS_OBJ_LIST=$(BONUS_SRCS_LIST:.c=.o)
BONUS_OBJS=$(addprefix $(BONUS_OBJS_DIR), $(BONUS_OBJ_LIST))

all:$(OBJS_DIR) $(NAME)
	
$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)
	
$(NAME):$(OBJS) $(LIBFT_A)
	gcc $(OBJS) $(LIBFT_A) -o $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)
	
$(OBJS_DIR)%.o:$(SRCS_DIR)%.c
	gcc $(INC) -c -o  $@ $^
	

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
	rm -rf $(OBJS_DIR)

fclean:
	make fclean -C $(LIBFT_DIR)
	rm push_swap
	rm -rf $(BONUS_OBJS_DIR)
	rm $(BONUS_NAME)
# .PHONY:checker