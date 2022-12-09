/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:26:15 by aessaoud          #+#    #+#             */
/*   Updated: 2022/11/27 21:36:42 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_HEADER_H
#define MY_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include "./ft_printf/ft_printf.h"
#include "./libft/libft.h"

typedef struct	s_stack_a
{
	int	top;
	int	size;
	int	*num_arr;
}	t_stack_a;

typedef struct	s_stack_b
{
	int	top;
	int	size;
	int	*num_arr;
}	t_stack_b;

void		reverse_rotate_a(t_stack_a *stack_a);
void		reverse_rotate_b(t_stack_b *stack_b);
void		rotate_a(t_stack_a *stack_a);
void		rotate_b(t_stack_b *stack_b);
void		push_a(t_stack_a *stack_a, t_stack_b *stack_b);
void		push_b(t_stack_a *stack_a, t_stack_b *stack_b);
void		print_nums_a(t_stack_a *stack_a);
void		print_nums_b(t_stack_b *stack_b);
void		swap_a(t_stack_a *stack_a);
void		swap_b(t_stack_b *stack_b);
void		fill_a(t_stack_a *stack_a, char **args, int c);
void		free_stacks(t_stack_a *stack_a, t_stack_b *stack_b);
int	check_args(int c, char **args);
t_stack_a	*cr_stack_a(int size);
t_stack_b	*cr_stack_b(int size);

#endif