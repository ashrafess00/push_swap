/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:26:15 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/20 21:51:28 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_HEADER_H
# define MY_HEADER_H
# include "../libft/libft.h"

typedef struct s_stacks
{
	int	top_a;
	int	top_b;
	int	*numbers_a;
	int	*numbers_b;
}	t_stacks;

typedef struct s_arrays
{
	int	top_a;
	int	top_b;
	int	*numbers_a;
	int	*numbers_b;
}	t_arrays;

typedef struct s_position
{
	int	a_pos_in_a;
	int	a_pos_in_b;
	int	a_pos_in_a_tmp;
	int	a_pos_in_b_tmp;
}	t_pos;

void		push(t_stacks *stacks, int num, char stack);
void		pop(t_stacks *stacks, char stack);
void		clear_stack(t_stacks *stacks, char stack);
void		swap_a(t_stacks *stacks, t_arrays *arrays, int print);
void		swap_b(t_stacks *stacks, t_arrays *arrays, int print);
void		push_a(t_stacks *stacks, t_arrays *arrays, int print);
void		rotate_a(t_stacks *stacks, t_arrays *arrays, int print);
void		rotate_b(t_stacks *stacks, t_arrays *arrays, int print);
void		reverse_rotate_a(t_stacks *stacks, t_arrays *arrays, int print);
void		reverse_rotate_b(t_stacks *stacks, t_arrays *arrays, int print);
void		rotate_both(t_stacks *stacks, t_arrays *arrays, int print);
void		reverse_rotate_both(t_stacks *stacks, t_arrays *arrays, int print);
void		push_b(t_stacks *stacks, t_arrays *arrays, int print);
void		fill_stack(t_stacks *stacks, t_arrays *arrays, char stack);
void		sort_3(t_stacks *stacks, t_arrays *arrays);
int			a_pos_in_a(t_arrays *arrays, int num);
int			a_pos_in_b(t_arrays *arrays, int num);
int			b_pos_in_a(t_arrays *arrays, int num);
void		push_all_2_b(t_stacks *stacks, t_arrays *arrays, t_pos pos);
void		push_all_2_a(t_stacks *stacks, t_arrays *arrays, int num);
void		rotate_with_rr(t_stacks *stacks, t_arrays *arrays, int ia, int ib);
void		repeat_rotate_a(t_stacks *stacks, t_arrays *arrays, int c);
void		repeat_rotate_b(t_stacks *stacks, t_arrays *arrays, int c);
void		repeat_reverse_rotate_a(t_stacks *stacks, t_arrays *arrays, int c);
void		repeat_reverse_rotate_b(t_stacks *stacks, t_arrays *arrays, int c);
void		repeat_rr(t_stacks *stacks, t_arrays *arrays, int c);
void		repeat_rrr(t_stacks *stacks, t_arrays *arrays, int c);
int			is_a_sorted(t_arrays *arrays);
void		sort_big(t_stacks *stacks, t_arrays *arrays);
int			find_min(t_arrays *arrays, char stack);
void		rotate_with_rrr(t_stacks *stacks, t_arrays *arrays, int ia, int ib);
void		rotate_with_ra_rrb(t_stacks *stacks, t_arrays *arrays,
				int ia, int ib);
void		rotate_with_rra_rb(t_stacks *stacks, t_arrays *arrays,
				int ia, int ib);
void		repeat_pb(t_stacks *stacks, t_arrays *arrays, int c);
int			*get_args(int c, char **args);
void		initiate_stacks(t_stacks *stacks, t_arrays *arrays, int *numbers);
void		free_elements(char *s1, char *s2, char **s3, int *nums);
void		write_error(char *s1, char *s2, char **s3, int *nums);
int			is_number(char *s);
int			is_duplicated(int *nums);
int			ft_max(int a, int b);
long long	ft_atoi_long(const char *str);
int			ft_strcmp(const char *s1, const char *s2);
void		free_stacks_arrays(t_stacks *stacks, t_arrays *arrays);
void		free_elements(char *s1, char *s2, char **s3, int *nums);
int			ft_strcmp(const char *s1, const char *s2);
#endif
