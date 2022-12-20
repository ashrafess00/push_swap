#include "my_header.h"

void	print_stacks(t_stack stack_a, t_stack stack_b)
{
	int	a;
	int	b;
	int	bigger;
	
	a = stack_a.top;
	b = stack_b.top;
	if (a >= b)
		bigger = a;
	else
		bigger = b;
	
	while (bigger >= 0)
	{
		if (stack_a.top >= bigger)
			printf("%d", stack_a.num_arr[bigger]);
		printf("\t\t");
		if (stack_b.top >= bigger)
			printf("%d", stack_b.num_arr[bigger]);
		printf("\n");
		bigger--;
	}
	printf("--------\t--------\nstack_a\t\tstack_b\n");
}
// void	free_stacks(t_stack_a *stack_a, t_stack_b *stack_b)
// {
// 	free(stack_a->num_arr);
// 	free(stack_b->num_arr);
// 	free(stack_a);
// 	free(stack_b);
// }

int	find_max(t_stack *stack_b)
{
	int	max;
	int	s_t;
	int	s_tt;

	s_t = stack_b->top;
	max = stack_b->num_arr[s_t];
	while (s_t >= 0)
	{
		int	s_tt = s_t - 1;
		while (s_tt >= 0)
		{
			if (max < stack_b->num_arr[s_tt])
				max = stack_b->num_arr[s_tt];
			s_tt--;
		}
		s_t--;
	}
	return(max);
}

int	find_max_in_a(t_stack *stack_a)
{
	int	max;
	int	s_t;
	int	s_tt;

	s_t = stack_a->top;
	max = stack_a->num_arr[s_t];
	while (s_t >= 0)
	{
		int	s_tt = s_t - 1;
		while (s_tt >= 0)
		{
			if (max < stack_a->num_arr[s_tt])
				max = stack_a->num_arr[s_tt];
			s_tt--;
		}
		s_t--;
	}
	return(max);
}
int	find_min(t_stack *stack_b)
{
	int	min;
	int	s_t;
	int	s_tt;

	s_t = stack_b->top;
	min = stack_b->num_arr[s_t];
	while (s_t >= 0)
	{
		int	s_tt = s_t - 1;
		while (s_tt >= 0)
		{
			if (min > stack_b->num_arr[s_tt])
				min = stack_b->num_arr[s_tt];
			s_tt--;
		}
		s_t--;
	}
	return(min);
}
int	find_min_in_a(t_stack *stack_a)
{
	int	min;
	int	s_t;
	int	s_tt;

	s_t = stack_a->top;
	min = stack_a->num_arr[s_t];
	while (s_t >= 0)
	{
		int	s_tt = s_t - 1;
		while (s_tt >= 0)
		{
			if (min > stack_a->num_arr[s_tt])
				min = stack_a->num_arr[s_tt];
			s_tt--;
		}
		s_t--;
	}
	return(min);
}
static int a_pos_in_a(t_stack *stack_a, int num)
{
	int	i;

	i = stack_a->top;
	while (stack_a->num_arr[i] != num && i > -1)
		i--;
	return (i);
}
static int	a_pos_in_b(t_stack *stack_b, int num)
{
	int	s_t;
	int	max;
	int	min;

	max = find_max(stack_b);
	min = find_min(stack_b);
	s_t = stack_b->top;
	if (num > max || num < min)
	{
		num = max;
		while (stack_b->num_arr[s_t] != num && s_t > -1)
			s_t--;
		return (s_t + 1);
	}
	if (stack_b->num_arr[0] > num && stack_b->num_arr[s_t] < num)
		return (s_t + 1);
	while (s_t > 0)
	{
		if (stack_b->num_arr[s_t] > num && stack_b->num_arr[s_t - 1] < num)
			return (s_t);
		s_t--;
	}
	return (s_t);
}

int	b_pos_in_a(t_stack *stack_a, int num)
{
	int	s_t;
	int	max;
	int	min;

	max = find_max_in_a(stack_a);
	min = find_min_in_a(stack_a);
	s_t = stack_a->top;
	if (num > max || num < min)
	{
		num = min;
		while (stack_a->num_arr[s_t] != num && s_t > -1)
			s_t--;
		return (s_t + 1);
	}
	if (stack_a->num_arr[0] < num && stack_a->num_arr[s_t] > num)
		return (s_t + 1);
	while (s_t > 0)
	{
		if (stack_a->num_arr[s_t] <= num && stack_a->num_arr[s_t - 1] >= num)
			return (s_t);
		s_t--;
	}
	return (s_t);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
int  count_rotations(t_stack *stack_a, t_stack *stack_b, int num)
{
	int	ia;
	int	ib;
	int	count = 0;

	ia = a_pos_in_a(stack_a, num);
	ib = a_pos_in_b(stack_b, num);
	if (ia >= (stack_a->top / 2) && ib >= (stack_b->top / 2))
		count = ft_max(stack_a->top - ia, stack_b->top - ib + 1);
	else if (ia <= (stack_a->top / 2) && ib <= (stack_b->top / 2))
		count = ft_max(ia + 1, ib);
	else if (ia <= (stack_a->top / 2) && ib >= (stack_b->top / 2))
		count = ia + 1 + stack_b->top - ib + 1;

	else if (ia >= (stack_a->top / 2) && ib <= (stack_b->top / 2))
		count = stack_a->top - ia + ib;
	return(count + 1);
}

int	cheaper_num_i(t_stack *stack_a, t_stack *stack_b)
{
	int	s_t;
	int	c;
	int index;
	int	c2;

	s_t = stack_a->top;
	c = count_rotations(stack_a, stack_b, stack_a->num_arr[s_t]);
	index = s_t;
	s_t--;
	while (s_t >= 0)
	{
		int	c2 = count_rotations(stack_a, stack_b, stack_a->num_arr[s_t]);
		if (c > c2)
		{
			c = c2;
			index = s_t;
		}
		s_t--;
	}
	return (index);
}

void	push_me_to_b(t_stack *stack_a, t_stack *stack_b, int ra, int rra, int rb, int rrb, int rr, int rrr)
{
	while (ra-- > 0)
		rotate(stack_a);
	while (rra-- > 0)
		reverse_rotate(stack_a);
	while (rb-- > 0)
		rotate(stack_b);
	while (rrb-- > 0)
		reverse_rotate(stack_b);
	while (rr-- > 0)
		rotate_both(stack_a, stack_b);
	while (rrr-- > 0)
		reverse_rotate_both(stack_a, stack_b);
	push_b(stack_a, stack_b);
}

void	fill_instructions(int instructions[6], int i1, int i2)
{
	int	i;
	
	i = 0;
	while (i < 6)
	{
		if (i != i1 && i != i2)
			instructions[i] = -1;
		i++;
	}
}

void	rotate_me_push_a(t_stack *stack_a, t_stack *stack_b, int ra, int rra)
{
	while (ra-- > 0)
		rotate(stack_a);
	while (rra-- > 0)
		reverse_rotate(stack_a);
	push_a(stack_a, stack_b);
}
void	push_all_2_a(t_stack *stack_a, t_stack *stack_b, int num)
{
	int	i;
	int	ra;
	int	rra;

	i = b_pos_in_a(stack_a, num);
	ra = stack_a->top - i + 1;
	rra = i;
	if (ra >= rra)
		ra = -1;
	else
		rra = -1;
	rotate_me_push_a(stack_a, stack_b, ra, rra);
}
void	push_all_2_b(t_stack *stack_a, t_stack *stack_b, int num)
{
	int index;
	int	instructions[6];

	fill_instructions(instructions, -1, -1);
	index = a_pos_in_a(stack_a, num);
	instructions[0] = stack_a->top - index;
	instructions[2] = index + 1;
	index = a_pos_in_b(stack_b, num);
	instructions[1] = stack_b->top - index + 1;
	instructions[3] = index;
	if (instructions[0] <= instructions[2] && instructions[1] <= instructions[3])
	{
		if (instructions[0] >= instructions[1])
		{
			instructions[4] = instructions[1];
			instructions[0] = instructions[0] - instructions[1];
			fill_instructions(instructions, 0, 4);
		}
		else
		{
			instructions[4] = instructions[0];
			instructions[1] = instructions[1] - instructions[0];
			fill_instructions(instructions, 1, 4);
		}
	}
	else if (instructions[2] <= instructions[0] && instructions[3] <= instructions[1])
	{
		if (instructions[2] >= instructions[3])
		{
			instructions[5] = instructions[3];
			instructions[2] = instructions[2] - instructions[3];
			fill_instructions(instructions, 2, 5);
		}
		else
		{
			instructions[5] = instructions[2];
			instructions[3] = instructions[3] - instructions[2];
			fill_instructions(instructions, 3, 5);
		}
	}
	else if (instructions[0] <= instructions[2] && instructions[1] >= instructions[3])
		fill_instructions(instructions, 0, 3);
	else if (instructions[0] >= instructions[2] && instructions[1] <= instructions[3])
		fill_instructions(instructions, 1, 2);
	push_me_to_b (stack_a, stack_b, instructions[0], instructions[2], instructions[1], instructions[3], instructions[4], instructions[5]);
}
void	adapt(t_stack *stack_a)
{
	int	min;
	int	i;
	int	ra;
	int	rra;

	min = find_min_in_a(stack_a);
	i = b_pos_in_a(stack_a, min);
	ra = stack_a->top - i;
	rra = i + 1;
	if (ra < rra)
		rra = -1;
	else
		ra = -1;
	while (ra-- > 0)
		rotate(stack_a);
	while (rra-- > 0)
		reverse_rotate(stack_a);
}

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
	
	
	// stack_a.top = -1;
	// stack_b.top = -1;
	numbers = get_args(c, args);
	if (!numbers)
	{
		printf("error");
		exit(0);
	}
	
	numbers_count = count_numbers(numbers);
	// stack_a.num_arr = malloc(numbers_count  * sizeof(int));
	// stack_b.num_arr = malloc(numbers_count * sizeof(int));
	initiate_stacks(&stack_a, &stack_b, numbers_count);
	if(!fill_a(&stack_a, numbers, numbers_count))
	{
		printf("error");
		exit(0);
	}
	
	if (is_a_sorted(stack_a))
	{
		printf("a is sorted");
		exit(0);
	}
	if (stack_a.top == 2)
		sort_3(&stack_a);
	else
	{
		push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	int s_t = stack_a.top;
	while (s_t >= 3)
	{
		int cheaper = cheaper_num_i(&stack_a, &stack_b);
		push_all_2_b(&stack_a, &stack_b, stack_a.num_arr[cheaper]);
		s_t--;
	}
	sort_3(&stack_a);
	int	s_t_b = stack_b.top;
	while (s_t_b > -1)
	{
		push_all_2_a(&stack_a, &stack_b, stack_b.num_arr[s_t_b]);
		s_t_b--;
	}
	adapt(&stack_a);
	}
}
