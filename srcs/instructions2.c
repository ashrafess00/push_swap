/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:14:32 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/23 23:43:19 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

void	rotate(t_stack *stack)
{
	int	last_num;
	int	i;

	last_num = stack->num_arr[stack->top];
	i = stack->top + 1;
	while (i-- > 0)
		stack->num_arr[i] = stack->num_arr[i - 1];
	stack->num_arr[0] = last_num;
	if (stack->which_stack)
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
}

void	rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	int	last_num_a;
	int	last_num_b;
	int	i;

	last_num_a = stack_b->num_arr[stack_b->top];
	i = stack_b->top + 1;
	while (i-- > 0)
		stack_b->num_arr[i] = stack_b->num_arr[i - 1];
	stack_b->num_arr[0] = last_num_a;
	last_num_b = stack_a->num_arr[stack_a->top];
	i = stack_a->top + 1;
	while (i-- > 0)
		stack_a->num_arr[i] = stack_a->num_arr[i - 1];
	stack_a->num_arr[0] = last_num_b;
	ft_printf("rr\n");
}

void	reverse_rotate(t_stack *stack)
{
	int	first_num;
	int	i;

	first_num = stack->num_arr[0];
	i = 0;
	while (i < stack->top)
	{
		stack->num_arr[i] = stack->num_arr[i + 1];
		i++;
	}
	stack->num_arr[stack->top] = first_num;
	if (stack->which_stack)
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
}

void	reverse_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	int	first_num_a;
	int	first_num_b;
	int	i;

	first_num_a = stack_a->num_arr[0];
	i = 0;
	while (i < stack_a->top)
	{
		stack_a->num_arr[i] = stack_a->num_arr[i + 1];
		i++;
	}
	stack_a->num_arr[stack_a->top] = first_num_a;
	first_num_b = stack_b->num_arr[0];
	i = 0;
	while (i < stack_b->top)
	{
		stack_b->num_arr[i] = stack_b->num_arr[i + 1];
		i++;
	}
	stack_b->num_arr[stack_b->top] = first_num_b;
	ft_printf("rrr\n");
}
