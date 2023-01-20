# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 16:27:55 by aessaoud          #+#    #+#              #
#    Updated: 2023/01/20 23:37:07 by aessaoud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
CC=cc
CFLAGS=-Wall -Wextra -Werror 
RM=rm -rf

INC=-I./headers/
BONUS_NAME=checker
LIBFT_DIR=libft/
LIBFT_A=$(LIBFT_DIR)libft.a
OBJS_DIR=objs/
BONUS_OBJS_DIR=bonus_objs/
SHARED_DIR=shared/
SRCS_DIR=srcs/
BONUS_SRCS_DIR=bonus/

SHARED_LIST= check_args_1.c check_args_2.c errors.c instructions1.c instructions2.c instructions3.c utils.c free_all.c
BONUS_SRCS_LIST=main_bonus.c initiate_stacks_bonus.c push_pop_bonus.c sort_bonus.c
SRCS_LIST=main.c sort_3.c repeat_instructions1.c repeat_instructions2.c sort_big.c rotate_with.c find_pos.c push_all_to_a_b.c initiate_stacks.c push_pop.c
HEADERS_DIR=headers/



OBJS=$(addprefix $(OBJS_DIR), $(SRCS_LIST:.c=.o)) $(addprefix $(OBJS_DIR), $(SHARED_LIST:.c=.o))
BONUS_OBJS=$(addprefix $(BONUS_OBJS_DIR), $(BONUS_SRCS_LIST:.c=.o)) $(addprefix $(BONUS_OBJS_DIR), $(SHARED_LIST:.c=.o))

all:$(OBJS_DIR) $(NAME)
	
$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)
	
$(NAME):$(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJS_DIR)%.o:$(SRCS_DIR)%.c
	$(CC) $(CFLAGS) $(INC) -c -o  $@ $^

$(OBJS_DIR)%.o:$(SHARED_DIR)%.c
	$(CC) $(CFLAGS) $(INC) -c -o  $@ $^



bonus:$(BONUS_OBJS_DIR) $(BONUS_NAME)

$(BONUS_OBJS_DIR):
	mkdir -p $(BONUS_OBJS_DIR)
	
$(BONUS_NAME):$(BONUS_OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT_A) -o $(BONUS_NAME)


$(BONUS_OBJS_DIR)%.o:$(BONUS_SRCS_DIR)%.c
	$(CC) $(CFLAGS) $(INC) -c -o  $@ $^

$(BONUS_OBJS_DIR)%.o:$(SHARED_DIR)%.c
	$(CC) $(CFLAGS) $(INC) -c -o  $@ $^
	
clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS_DIR)
	$(RM) $(BONUS_OBJS_DIR)

fclean:clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)
	
re: fclean all
	
.PHONY:bonus check clean fclean norm