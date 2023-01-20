/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_header_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:12:54 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/20 21:51:35 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_HEADER_BONUS_H
# define MY_HEADER_BONUS_H
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

void		swap_a(t_stacks *stacks, t_arrays *arrays, int print);
void		swap_b(t_stacks *stacks, t_arrays *arrays, int print);
void		push_a(t_stacks *stacks, t_arrays *arrays, int print);
void		push_b(t_stacks *stacks, t_arrays *arrays, int print);
void		rotate_a(t_stacks *stacks, t_arrays *arrays, int print);
void		rotate_b(t_stacks *stacks, t_arrays *arrays, int print);
void		reverse_rotate_a(t_stacks *stacks, t_arrays *arrays, int print);
void		reverse_rotate_b(t_stacks *stacks, t_arrays *arrays, int print);
void		swap_both(t_stacks *stacks, t_arrays *arrays, int print);
void		rotate_both(t_stacks *stacks, t_arrays *arrays, int print);
void		reverse_rotate_both(t_stacks *stacks, t_arrays *arrays, int print);
int			*get_args(int c, char **args);
int			is_duplicated(int *nums);
int			is_number(char *s);
int			is_a_sorted(t_arrays *arrays);
void		sort_with_(t_stacks *stacks, t_arrays *arrays, char **instructions);
void		initiate_stacks(t_stacks *stacks, t_arrays *arrays, int *numbers);
int			is_instruction(char *ins);
void		write_error(char *s1, char *s2, char **s3, int *nums);
void		free_elements(char *s1, char *s2, char **s3, int *nums);
void		free_stacks_arrays(t_stacks *stacks, t_arrays *arrays);
int			ft_strcmp(const char *s1, const char *s2);
long long	ft_atoi_long(const char *str);
void		clear_stack(t_stacks *stacks, char stack);
void		fill_stack(t_stacks *stacks, t_arrays *arrays, char stack);
void		pop(t_stacks *stacks, char stack);
void		push(t_stacks *stacks, int num, char stack);

#endif