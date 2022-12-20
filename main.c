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

int	cheaper_num(t_stack *stack_a, t_stack *stack_b)
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
	return (stack_a->num_arr[index]);
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
	while (ra-- > 0)
		rotate(stack_a);
	while (rra-- > 0)
		reverse_rotate(stack_a);
	push_a(stack_a, stack_b);
}

void	rotate_with_rr(t_stack *stack_a, t_stack *stack_b, int ia, int ib)
{
	int	ra;
	int rb;
	
	ra = stack_a->top - ia;
	rb = stack_b->top - ib + 1;
	if (ra <= rb)
	{
		repeat_rr(stack_a, stack_b, ra);
		repeat_rb(stack_b, rb - ra);
	}
	else
	{
		repeat_rr(stack_a, stack_b, rb);
		repeat_ra(stack_a, ra - rb);
	}
}

void	rotate_with_rrr(t_stack *stack_a, t_stack *stack_b, int ia, int ib)
{
	int	rra;
	int rrb;
	
	rra = ia + 1;
	rrb = ib;
	if (rra <= rrb)
	{
		repeat_rrr(stack_a, stack_b, rra);
		repeat_rrb(stack_b, rrb - rra);
	}
	else
	{
		repeat_rrr(stack_a, stack_b, rrb);
		repeat_rra(stack_a, rra - rrb);
	}
}

void	rotate_with_ra_rrb(t_stack *stack_a, t_stack *stack_b, int ia, int ib)
{
	int ra;
	int	rrb;

	ra = stack_a->top - ia;
	rrb = ib;
	repeat_ra(stack_a, ra);
	repeat_rrb(stack_b, rrb);
}

void	rotate_with_rra_rb(t_stack *stack_a, t_stack *stack_b, int ia, int ib)
{
	int rra;
	int	rb;

	rra = ia + 1;
	rb = stack_b->top - ib + 1;
	repeat_rra(stack_a, rra);
	repeat_rb(stack_b, rb);
}

void	push_all_2_b(t_stack *stack_a, t_stack *stack_b, int num)
{
	int ia = a_pos_in_a(stack_a, num);
	int	ib = a_pos_in_b(stack_b, num);

	if (ia >= (stack_a->top / 2) && ib >= (stack_b->top / 2))
		rotate_with_rr(stack_a, stack_b, ia, ib);
	else if (ia <= (stack_a->top / 2) && ib <= (stack_b->top / 2))
		rotate_with_rrr(stack_a, stack_b, ia, ib);
	else if (ia >= (stack_a->top / 2) && ib <= (stack_b->top / 2))
		rotate_with_ra_rrb(stack_a, stack_b, ia, ib);
	else if (ia <= (stack_a->top / 2) && ib >= (stack_b->top / 2))
		rotate_with_rra_rb(stack_a, stack_b, ia, ib);
	push_b(stack_a, stack_b);
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
	int	cheaper;
	// return (0);
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
		cheaper = cheaper_num(&stack_a, &stack_b);
		push_all_2_b(&stack_a, &stack_b, cheaper);
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
