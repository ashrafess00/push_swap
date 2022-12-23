/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_header.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:12:54 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/23 19:33:43 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>

typedef struct	s_stack
{
	int	top;
	int	*num_arr;
	int	which_stack;
}	t_stack;

void		swap(t_stack *stack);
void		swap_both(t_stack *stack_a, t_stack *stack_b);
void		rotate(t_stack *stack_a);
void		rotate_both(t_stack *stack_a, t_stack *stack_b);
void		reverse_rotate(t_stack *stack_a);
void		reverse_rotate_both(t_stack *stack_a, t_stack *stack_b);
void		push_a(t_stack *stack_a, t_stack *stack_b);
void		push_b(t_stack *stack_a, t_stack *stack_b);
void		initiate_stacks(t_stack *stack_a, t_stack *stack_b, int size);
int			fill_a(t_stack *stack_a, char **numbers, int c);
char		**get_args(int c, char **args);
void		print_stacks(t_stack stack_a, t_stack stack_b);