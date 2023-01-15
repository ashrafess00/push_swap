/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:52:15 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/15 21:03:37 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

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
	if (is_a_sorted(arrays))
	{
		free_stacks_arrays(stacks, arrays);
		free_elements(NULL, NULL, NULL, numbers);
		exit(0);
	}
	free_elements(NULL, NULL, NULL, numbers);
}
