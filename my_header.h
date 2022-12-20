/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:26:15 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/20 16:24:37 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_HEADER_H
#define MY_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include "./ft_printf/ft_printf.h"
#include "./libft/libft.h"
#include <math.h>

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
void	repeat_ra(t_stack *stack_a, int c);
void	repeat_rra(t_stack *stack_a, int c);
void	repeat_rb(t_stack *stack_a, int c);
void	repeat_rrb(t_stack *stack_b, int c);
void	repeat_rr(t_stack *stack_a, t_stack *stack_b, int c);
void	repeat_rrr(t_stack *stack_a, t_stack *stack_b, int c);
#endif