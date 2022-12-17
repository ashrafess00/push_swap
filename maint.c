#include "my_header.h"

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
void	free_stacks(t_stack_a *stack_a, t_stack_b *stack_b)
{
	free(stack_a->num_arr);
	free(stack_b->num_arr);
	free(stack_a);
	free(stack_b);
}

int	find_max(t_stack_b *stack_b)
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
int	find_min(t_stack_b *stack_b)
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
static int	i_pos_a(t_stack_a *stack_a, int num)
{
	int	i;

	i = stack_a->top;
	while (stack_a->num_arr[i] != num && i > -1)
		i--;
	return (i);
}
static int	i_pos_b(t_stack_b *stack_b, int num)
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
	s_t = stack_b->top;
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


int  count_rotations(t_stack_a *stack_a, t_stack_b *stack_b, int num)
{
	int	ra = -1;
	int	rb = -1;
	int	rra = -1;
	int	rrb = -1;
	int	i;
	int	count = 0;

	i = i_pos_a(stack_a, num);
	ra = stack_a->top - i;
	rra = i + 1;
	i = i_pos_b(stack_b, num);
	rb = stack_b->top - i + 1;
	rrb = i;
	if (ra <= rra && rb <= rrb)
	{
		if (ra > rb)
			count = ra;
		else
			count = rb;
	}
	else if (rra <= ra && rrb <= rb)
	{
		if (rra > rrb)
			count = rra;
		else
			count = rrb;
	}
	else if (ra >= rra && rb <= rrb)
		count = rra + rb;
	else if (ra <= rra && rb >= rrb)
		count = ra + rrb;
	// ra rra rb rrb rr rrr
	// printf("count rotaions:\n");
	// printf("ra : %d\n", ra);
	// printf("rra : %d\n", rra);
	// printf("rb : %d\n", rb);
	// printf("rrb : %d\n", rrb);
	// printf("count : %d\n", count);
	return(count + 1);
}

int	cheaper_num_i(t_stack_a *stack_a, t_stack_b *stack_b)
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

void	rotate_me(t_stack_a *stack_a, t_stack_b *stack_b, int ra, int rra, int rb, int rrb, int rr, int rrr)
{
	while (ra-- > 0)
		rotate_a(stack_a);
	while (rra-- > 0)
		reverse_rotate_a(stack_a);
	while (rb-- > 0)
		rotate_b(stack_b);
	while (rrb-- > 0)
		reverse_rotate_b(stack_b);
	while (rr-- > 0)
		rotate_both(stack_a, stack_b);
	while (rrr-- > 0)
		reverse_rotate_both(stack_a, stack_b);
	push_b(stack_a, stack_b);
}

void	instractions(t_stack_a *stack_a, t_stack_b *stack_b, int num)
{
	int	ra = -1;
	int	rb = -1;
	int	rra = -1;
	int	rrb = -1;
	int	rr = -1;
	int	rrr = -1;
	int index;

	index = i_pos_a(stack_a, num);
	ra = stack_a->top - index;
	rra = index + 1;
	index = i_pos_b(stack_b, num);
	rb = stack_b->top - index + 1;
	rrb = index;
	// printf("ra ->%d\n", ra);
	// printf("rra ->%d\n", rra);
	// printf("rb ->%d\n", rb);
	// printf("rrb ->%d\n", rrb);

	if (ra <= rra && rb <= rrb)
	{
		// printf("hi");
		if (ra >= rb)
		{
			rr = rb;
			ra = ra - rb;

			rb = -1;
			rra = -1;
			rrb = -1;
			rrr = -1;
		}
		else
		{
			rr = ra;
			rb = rb - ra;

			ra = -1;
			rra = -1;
			rrb = -1;
			rrr = -1;
		}
	}
	else if (rra <= ra && rrb <= rb)
	{
		if (rra >= rrb)
		{
			rrr = rrb;
			rra = rra - rrb;

			ra = -1;
			rb = -1;
			rrb = -1;
			rr = -1;
		}
		else
		{
			rrr = rra;
			rrb = rrb - rra;

			ra = -1;
			rb = -1;
			rra = -1;
			rr = -1;
		}
	}
	else if (ra <= rra && rb >= rrb)
	{
		rb = -1;
		rra = -1;
		rr = -1;
		rrr = -1;
	}
	else if (ra >= rra && rb <= rrb)
	{
		ra = -1;
		rrb = -1;
		rr = -1;
		rrr = -1;
	}
	// printf("\nra %d - rra %d - rb %d - rrb %d - rr %d - rrr %d\n", ra, rra, rb, rrb, rr, rrr);
	rotate_me (stack_a, stack_b, ra, rra, rb, rrb, rr, rrr);
}

int main(int c, char **args)
{

	int i = 0;
	t_stack_a *stack_a = cr_stack_a(c - 1);
	t_stack_b *stack_b = cr_stack_b(c - 1);
	fill_a(stack_a, args, c);
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	// push_b(stack_a, stack_b);
	// push_b(stack_a, stack_b);
	// int j = count_rotations(stack_a, stack_b, 17);
	// printf("(%d)\n", j);
	int s_t = stack_a->top;
	// printf("ins[0] %d :\n", ins[0]);
	// printf("ins[1] %d :\n", ins[1]);
	// printf("ins[2] %d :\n", ins[2]);
	// printf("ins[3] %d :\n", ins[3]);
	// printf("ins[4] %d :\n", ins[4]);
	// printf("ins[5] %d :\n", ins[5]);
	print_stacks(stack_a, stack_b);
	while (s_t >= 3)
	{
		// printf("number %d needs %d moves to be in stack b -> ", stack_a->num_arr[s_t], count_rotations(stack_a, stack_b, stack_a->num_arr[s_t]));
		// printf("\n");
		// s_t--;
		int cheaper = cheaper_num_i(stack_a, stack_b);
		// printf("cheaper num : (%d)\n", stack_a->num_arr[cheaper]);
		instractions(stack_a, stack_b, stack_a->num_arr[cheaper]);
		// print_stacks(stack_a, stack_b);
		// printf("\n----------------------------------------------------\n");

		s_t--;
		// stack_a->top -= 1;
	}
	// instractions(stack_a, stack_b, 5);
	// printf("(%d)", count_rotations(stack_a, stack_b, 3));
	// instractions(stack_a, stack_b, 6);
	// instractions(stack_a, stack_b, 15);
	// instractions(stack_a, stack_b, 13);
	// instractions(stack_a, stack_b, 12);
	// instractions(stack_a, stack_b, 7);
	// instractions(stack_a, stack_b, 11);
	// instractions(stack_a, stack_b, 14);
	// instractions(stack_a, stack_b, 2);
	// instractions(stack_a, stack_b, 3);
	// instractions(stack_a, stack_b, 5);

	// printf("(%d)", count_rotations(stack_a, stack_b, 9));
	// instractions(stack_a, stack_b, 9);

	// instractions(stack_a, stack_b, 8);

	// print_stacks(stack_a, stack_b);
	// print_stacks(stack_a, stack_b);

	free_stacks(stack_a, stack_b);
}

/*
	*after we got the number with minimum instructions index, it's time to get 
*/
