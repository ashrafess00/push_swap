/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_stacks_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:52:15 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/15 18:46:56 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header_bonus.h"

void	initiate_stacks(t_stacks *stacks, t_arrays *arrays, int *numbers)
{
	int			i;

	stacks->top_a = -1;
	stacks->top_b = -1;
	arrays->top_a = -1;
	arrays->top_b = -1;
	stacks->numbers_a = malloc(numbers[0] * sizeof(int));
	stacks->numbers_b = malloc(numbers[0] * sizeof(int));
	arrays->numbers_a = malloc(numbers[0] * sizeof(int));
	arrays->numbers_b = malloc(numbers[0] * sizeof(int));
	i = 1;
	while (i <= numbers[0])
	{
		arrays->top_a++;
		push(stacks, numbers[i], 'a');
		arrays->numbers_a[arrays->top_a] = numbers[i];
		i++;
	}
	free_elements(NULL, NULL, NULL, numbers);
}
