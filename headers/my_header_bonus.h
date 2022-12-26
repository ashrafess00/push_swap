/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_header_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:12:54 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/26 12:19:49 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_HEADER_BONUS_H
# define MY_HEADER_BONUS_H
# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int	top;
	int	*num_arr;
	int	which_stack;
}	t_stack;

void	swap(t_stack *stack);
void	swap_both(t_stack *stack_a, t_stack *stack_b);
void	rotate(t_stack *stack_a);
void	rotate_both(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate(t_stack *stack_a);
void	reverse_rotate_both(t_stack *stack_a, t_stack *stack_b);
void	push_a(t_stack *stack_a, t_stack *stack_b);
void	push_b(t_stack *stack_a, t_stack *stack_b);
char	**get_args(int c, char **args);
void	print_stacks(t_stack stack_a, t_stack stack_b);
void	free_arrs(char **s);
void	free_stacks(t_stack *stack_a, t_stack *stack_b);
int		is_duplicated(char **nums);
int		is_number(char *s);
int		is_a_sorted(t_stack *stack_a);
void	sort_with_(t_stack *stack_a, t_stack *stack_b, char **instructions);
void	initiate_stacks(t_stack *stack_a, t_stack *stack_b, char **nums, int s);
int		is_instruction(char *ins);
void	write_error_1(char *numbers_string);
void	write_error_2(char **numbers);
void	write_error_3(char *numbers_string, char **numbers);
void	write_error_4(char *s1, char *s2, char **numbers);
#endif