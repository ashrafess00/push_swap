/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:47:38 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/23 19:48:09 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->num_arr);
	free(stack_b->num_arr);
}
