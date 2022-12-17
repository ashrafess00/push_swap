/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:40:14 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/14 15:13:55 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	sa - swap a:
		swap first 2 elements at the top of stack a
	sb - swap b:
		swap first 2 elements at the top of stack b
	ss -
		sa && sb
	-----------------		
	pa - push a
		take first element at top of b and put it at top of a
	pb - push b
		take first element at top of a and put it at top of b
	------------------
	ra - rotate a
		shift up all elements in a by 1
	rb - rotate b
		shift up all elements in b by 1
	rr -
		ra && rb
	------------------
	rra - reverse rotate a
		shift down all elements of stack a by 1
	rrb - reverse rotate b
		shift down all elements of stack b by 1
	rrr -
		rra && rrb
*/
#include "my_header.h"
#include "./libft/libft.h"

void	free_stacks(t_stack_a *stack_a, t_stack_b *stack_b)
{
	free(stack_a->num_arr);
	free(stack_b->num_arr);
	free(stack_a);
	free(stack_b);
}

void	print_stacks(t_stack_a *stack_a, t_stack_b *stack_b)
{
	int	a;
	int	b;
	int	bigger;
	
	a = stack_a->top;
	b = stack_b->top;
	if (a >= b)
		bigger = a;
	else
		bigger = b;
	
	while (bigger >= 0)
	{
		if (stack_a->top >= bigger)
			printf("%d", stack_a->num_arr[bigger]);
		printf("\t\t");
		if (stack_b->top >= bigger)
			printf("%d", stack_b->num_arr[bigger]);
		printf("\n");
		bigger--;
	}
	printf("--------\t--------\nstack_a\t\tstack_b\n");
}


int	main(int c, char **args)
{
	int i = 0;

	// if (check_args(c, args) == 0)
	// {
	// 	printf("walla walo hhhh");
	// 	exit(0);
	// }
	t_stack_a *stack_a = cr_stack_a(c - 1);
	t_stack_b *stack_b = cr_stack_b(c - 1);
	fill_a(stack_a, args, c);

	// if (stack_a->top <= 2)
	// 	sort_3(stack_a, stack_b);
	// else if (stack_a->top <= 4)
	// 	sort_5(stack_a, stack_b);
	print_stacks(stack_a, stack_b);
	free_stacks(stack_a, stack_b);
}

//push two numbers to b
// calculate how many times it takes for every number to put in a good position in b
