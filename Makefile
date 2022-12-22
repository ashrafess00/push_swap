# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 16:27:55 by aessaoud          #+#    #+#              #
#    Updated: 2022/12/22 19:35:24 by aessaoud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap

LIBFT_DIR=libft/
LIBFT_A=$(LIBFT_DIR)libft.a
OBJS_DIR=objs/
SRCS_DIR=srcs/
SRCS_LIST=main.c check_args.c instructions.c print_stacks.c sort_3.c repeat_instructions.c sort_big.c rotate_with.c find_pos.c push_all_to_a_b.c
SRCS=$(addprefix $(SRCS_DIR), $(SRCS_LIST))

OBJ_LIST=$(SRCS_LIST:.c=.o)
OBJS=$(addprefix $(OBJS_DIR), $(OBJ_LIST))

all:$(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)
	
$(NAME):$(OBJS) $(LIBFT_A)
	gcc $(OBJS) $(LIBFT_A) -o $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)
	
$(OBJS_DIR)%.o:$(SRCS_DIR)%.c
	gcc -c -o  $@ $^
	
clean:
	make clean -C $(LIBFT_DIR)
	rm -rf $(OBJS_DIR)
fclean:
	make clean
	rm push_swap
	
