/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:26:15 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/09 17:03:57 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_HEADER_H
# define MY_HEADER_H
# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int	top;
	int	*num_arr;
	int	which_stack;
}	t_stack;

typedef struct s_top
{
	int	top_a;
	int	top_b;
}	t_top;

typedef struct s_position
{
	int	a_pos_in_a;
	int	a_pos_in_b;
	int	a_pos_in_a_tmp;
	int	a_pos_in_b_tmp;
}	t_pos;

void	swap(t_stack *stack);
void	swap_both(t_stack *stack_a, t_stack *stack_b);
void	push_a(t_stack *stack_a, t_stack *stack_b);
void	push_b(t_stack *stack_a, t_stack *stack_b);
void	rotate(t_stack *stack_a);
void	rotate_both(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate(t_stack *stack_a);
void	reverse_rotate_both(t_stack *stack_a, t_stack *stack_b);
void	initiate_stacks(t_stack *stack_a, t_stack *stack_b, char **nums, int s);
char	**get_args(int c, char **args);
void	sort_3(t_stack *stack_a);
char	**get_args(int c, char **args);
void	repeat_rotate(t_stack *stack, int c);
void	repeat_reverse_rotate(t_stack *stack, int c);
void	repeat_rr(t_stack *stack_a, t_stack *stack_b, int c);
void	repeat_rrr(t_stack *stack_a, t_stack *stack_b, int c);
void	repeat_pb(t_stack *stack_a, t_stack *stack_b, int c);
void	sort_big(t_stack *stack_a, t_stack *stack_b);
void	print_stacks(t_stack stack_a, t_stack stack_b);
void	rotate_with_rr(t_stack *stack_a, t_stack *stack_b, int ia, int ib);
void	rotate_with_rrr(t_stack *stack_a, t_stack *stack_b, int ia, int ib);
void	rotate_with_ra_rrb(t_stack *stack_a, t_stack *stack_b, int ia, int ib);
void	rotate_with_rra_rb(t_stack *stack_a, t_stack *stack_b, int ia, int ib);
int		a_pos_in_a(t_stack *stack_a, int num);
int		a_pos_in_b(t_stack *stack_b, int num);
int		b_pos_in_a(t_stack *stack_a, int num);
void	push_all_2_a(t_stack *stack_a, t_stack *stack_b, int num);
void	push_all_2_b(t_stack *stack_a, t_stack *stack_b, t_pos pos);
int		find_min(t_stack *stack);
int		count_numbers(char **s);
int		is_a_sorted(t_stack *stack_a);
int		is_duplicated(char **nums);
int		is_number(char *s);
void	free_arrs(char **s);
void	write_error_1(char *numbers_string);
void	write_error_2(char **numbers);
void	free_stacks(t_stack *stack_a, t_stack *stack_b);
#endif