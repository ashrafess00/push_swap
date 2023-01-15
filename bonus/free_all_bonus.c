/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:25:37 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/15 18:46:42 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header_bonus.h"

static void	free_arrs_str(char **s)
{
	int	i;

	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
}

static void	free_arrs_int(int **nums)
{
	int	i;

	i = -1;
	while (nums[++i])
		free (nums[i]);
	free (nums);
}

void	free_stacks_arrays(t_stacks *stacks, t_arrays *arrays)
{
	free(stacks->numbers_a);
	free(stacks->numbers_b);
	free(arrays->numbers_a);
	free(arrays->numbers_b);
}

void	free_elements(char *s1, char *s2, char **s3, int *nums)
{
	if (s1)
		free (s1);
	if (s2)
		free (s2);
	if (s3)
		free_arrs_str (s3);
	if (nums)
		free (nums);
}
