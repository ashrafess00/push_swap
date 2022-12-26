/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:02:31 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/24 22:19:04 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/my_header.h"

void	sort_3(t_stack *sa)
{
	int	top_a;

	top_a = sa->top;
	if (sa->num_arr[2] > sa->num_arr[1] && sa->num_arr[2] < sa->num_arr[0])
		swap(sa);
	else if (sa->num_arr[2] > sa->num_arr[1] && sa->num_arr[1] > sa->num_arr[0])
	{
		swap(sa);
		reverse_rotate(sa);
	}
	else if (sa->num_arr[2] > sa->num_arr[1] && sa->num_arr[1] < sa->num_arr[2])
		rotate(sa);
	else if (sa->num_arr[2] < sa->num_arr[1]
		&& sa->num_arr[1] > sa->num_arr[0] && sa->num_arr[2] < sa->num_arr[0])
	{
		swap(sa);
		rotate(sa);
	}
	else if (sa->num_arr[2] < sa->num_arr[1]
		&& sa->num_arr[1] > sa->num_arr[0] && sa->num_arr[2] > sa->num_arr[0])
		reverse_rotate(sa);
}
