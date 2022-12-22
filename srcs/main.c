/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:32:34 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/22 19:39:44 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/my_header.h"

// void	free_stacks(t_stack_a *stack_a, t_stack_b *stack_b)
// {
// 	free(stack_a->num_arr);
// 	free(stack_b->num_arr);
// 	free(stack_a);
// 	free(stack_b);
// }

int	is_a_sorted(t_stack stack_a)
{
	int	s_t;
	int	s_t2;

	s_t = stack_a.top;
	while (s_t >= 0)
	{
		s_t2 = s_t - 1;
		while (s_t2 >= 0)
		{
			if (stack_a.num_arr[s_t] > stack_a.num_arr[s_t2])
				return (0);
			s_t2--;
		}
		s_t--;
	}
	return (1);
}

int	count_numbers(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int main(int c, char **args)
{
	char	**numbers;
	int i = 0;
	int	numbers_count;
	t_stack	stack_a;
	t_stack stack_b;
	int	cheaper;
	
	numbers = get_args(c, args);
	if (!numbers)
	{
		printf("error");
		exit(0);
	}
	numbers_count = count_numbers(numbers);
	initiate_stacks(&stack_a, &stack_b, numbers_count);
	if(!fill_a(&stack_a, numbers, numbers_count))
	{
		printf("error");
		exit(0);
	}

	if (is_a_sorted(stack_a))
		exit(0);
	if (stack_a.top == 2)
		sort_3(&stack_a);
	else
		sort_big(&stack_a, &stack_b);
}
