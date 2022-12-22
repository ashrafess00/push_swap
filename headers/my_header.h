/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:26:15 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/22 19:37:34 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_HEADER_H
#define MY_HEADER_H

#include "../libft/includes/libft.h"
#include "../libft/includes/ft_printf.h"
#include "../libft/includes/get_next_line.h"

typedef struct	s_stack
{
	int	top;
	int	*num_arr;
	int	which_stack;
}	t_stack;

void		initiate_stacks(t_stack *stack_a, t_stack *stack_b, int size);
void		rotate(t_stack *stack_a);
void		reverse_rotate(t_stack *stack_a);
void		push_a(t_stack *stack_a, t_stack *stack_b);
void		push_b(t_stack *stack_a, t_stack *stack_b);
void		print_nums_a(t_stack *stack_a);
void		print_nums_b(t_stack *stack_b);
void		swap(t_stack *stack);
int			fill_a(t_stack *stack_a, char **numbers, int c);
char		**get_args(int c, char **args);
void		sort_3(t_stack *stack_a);
void		sort_me(t_stack *stack_a, t_stack *stack_b);
void		rotate_both(t_stack *stack_a, t_stack *stack_b);
void		reverse_rotate_both(t_stack *stack_a, t_stack *stack_b);
char		**get_args(int c, char **args);
void		repeat_rotate(t_stack *stack, int c);
void		repeat_reverse_rotate(t_stack *stack, int c);

void		repeat_rr(t_stack *stack_a, t_stack *stack_b, int c);
void		repeat_rrr(t_stack *stack_a, t_stack *stack_b, int c);
void		repeat_pb(t_stack *stack_a, t_stack *stack_b, int c);
void		sort_big(t_stack *stack_a, t_stack *stack_b);
void		print_stacks(t_stack stack_a, t_stack stack_b);

void		rotate_with_rr(t_stack *stack_a, t_stack *stack_b, int ia, int ib);
void		rotate_with_rrr(t_stack *stack_a, t_stack *stack_b, int ia, int ib);
void		rotate_with_ra_rrb(t_stack *stack_a, t_stack *stack_b, int ia, int ib);
void		rotate_with_rra_rb(t_stack *stack_a, t_stack *stack_b, int ia, int ib);
int			a_pos_in_a(t_stack *stack_a, int num);
int			a_pos_in_b(t_stack *stack_b, int num);
int			b_pos_in_a(t_stack *stack_a, int num);
void		push_all_2_a(t_stack *stack_a, t_stack *stack_b, int num);
void		push_all_2_b(t_stack *stack_a, t_stack *stack_b, int num);
int			find_min(t_stack *stack);

// void	adapt(t_stack *stack_a);
// int  count_rotations(t_stack *stack_a, t_stack *stack_b, int num);
// int	cheaper_num(t_stack *stack_a, t_stack *stack_b);

#endif