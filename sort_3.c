/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:02:31 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/19 19:46:18 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

void	sort_3(t_stack *stack_a)
{
	int top_a;
	int top_b;

	top_a = stack_a->top;
	if (stack_a->num_arr[2] > stack_a->num_arr[1] && stack_a->num_arr[2] < stack_a->num_arr[0])
		swap(stack_a); 
	else if (stack_a->num_arr[2] > stack_a->num_arr[1] && stack_a->num_arr[1] > stack_a->num_arr[0])
	{
		swap(stack_a);
		reverse_rotate(stack_a);
	}
	else if (stack_a->num_arr[2] > stack_a->num_arr[1] && stack_a->num_arr[1] < stack_a->num_arr[2])
		rotate(stack_a);
	else if (stack_a->num_arr[2] < stack_a->num_arr[1] && 
			stack_a->num_arr[1] > stack_a->num_arr[0] && stack_a->num_arr[2] < stack_a->num_arr[0])
	{
		swap(stack_a);
		rotate(stack_a);
	}
	else if (stack_a->num_arr[2] < stack_a->num_arr[1] && 
			stack_a->num_arr[1] > stack_a->num_arr[0] && stack_a->num_arr[2] > stack_a->num_arr[0])
		reverse_rotate(stack_a);
}