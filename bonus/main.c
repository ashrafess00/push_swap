/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:44:43 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/23 23:22:57 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_header.h"

int	is_instruction(char *ins)
{
	if (!ft_strcmp(ins, "sa\n") || !ft_strcmp(ins, "sb\n") || !ft_strcmp(ins, "ss\n")
		|| !ft_strcmp(ins, "pa\n") || !ft_strcmp(ins, "pb\n") || !ft_strcmp(ins, "ra\n")
		||!ft_strcmp(ins, "ra\n") || !ft_strcmp(ins, "rb\n") || !ft_strcmp(ins, "rr\n")
		|| !ft_strcmp(ins, "rra\n") || !ft_strcmp(ins, "rrb\n")|| !ft_strcmp(ins, "rrr\n"))
		return (1);
	return (0);
}

char	**read_input(void)
{
	char	*s;
	char	*instructions_string;
	char	**instructions;

	instructions_string = ft_calloc(1, 1);
	s = get_next_line(0);
	if (is_instruction(s) == 0)
		return (0);
	instructions_string = ft_strjoin(instructions_string, s);
	while (s)
	{
		s = get_next_line(0);
		if (s)
		{
			if (is_instruction(s) == 0)
				return (0);
			instructions_string = ft_strjoin(instructions_string, s);
		}
	}
	instructions = ft_split(instructions_string, '\n');
	free(instructions_string);
	return (instructions);
}

void	sort_with_instructions(t_stack *stack_a, t_stack *stack_b, char **instructions)
{
	int	i;

	i = -1;
	printf("(%s)\n", instructions[0]);
	while (instructions[++i])
	{
		if (!ft_strcmp(instructions[i], "sa"))
			swap(stack_a);
		else if(!ft_strcmp(instructions[i], "sb"))
			swap(stack_b);
		else if(!ft_strcmp(instructions[i], "ss"))
			swap_both(stack_a, stack_b);
		else if(!ft_strcmp(instructions[i], "pa"))
			push_a(stack_a, stack_b);
		else if(!ft_strcmp(instructions[i], "pb"))
			push_b(stack_a, stack_b);
		else if(!ft_strcmp(instructions[i], "ra"))
			rotate(stack_a);
		else if(!ft_strcmp(instructions[i], "rb"))
			rotate(stack_b);
		else if(!ft_strcmp(instructions[i], "rr"))
			rotate_both(stack_a, stack_b);
		else if(!ft_strcmp(instructions[i], "rra"))
			reverse_rotate(stack_a);
		else if(!ft_strcmp(instructions[i], "rrb"))
			reverse_rotate(stack_b);
		else if(!ft_strcmp(instructions[i], "rrr"))
			reverse_rotate_both(stack_a, stack_b);
	}
}

void	initiate_stacks(t_stack *stack_a, t_stack *stack_b, int size)
{
	stack_a->top = -1;
	stack_b->top = -1;
	stack_a->num_arr = malloc(size * sizeof(int));
	stack_b->num_arr = malloc(size * sizeof(int));
	stack_a->which_stack = 1;
	stack_b->which_stack = 0;
}

int	fill_a(t_stack *stack_a, char **numbers, int c)
{
	int	num;
	int	i;

	num = 0;
	i = -1;
	while (--c >= 0)
	{
		stack_a->top++;
		num = ft_atoi(numbers[c]);
		stack_a->num_arr[stack_a->top] = num;
	}
	if (is_a_sorted(stack_a))
		return (0);
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
	char	**instructions;
	int		i;
	char	**numbers;
	t_stack	stack_a;
	t_stack	stack_b;
	int		number_count;
	
	if (c == 1)
		exit(0);
	numbers = get_args(c, args);
	instructions = read_input();
	if (!numbers || !instructions)
	{
		write (2, "ERROR", 5);
		exit(1);
	}
	i = 0;
	number_count = count_numbers(numbers);
	initiate_stacks(&stack_a, &stack_b, number_count);
	fill_a(&stack_a, numbers, number_count);

	sort_with_instructions(&stack_a, &stack_b, instructions);
	
	if (is_a_sorted(&stack_a) && stack_b.top == -1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	print_stacks(stack_a, stack_b);
	free_all(&stack_a, &stack_b, numbers, instructions);
	check_leaks();
}