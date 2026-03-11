/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-tawa <mal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 02:48:08 by mal-tawa          #+#    #+#             */
/*   Updated: 2026/03/03 00:28:49 by mal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_to_idx_array(t_stack *a, int *arr)
{
	t_node	*cur;
	int		i;

	cur = a->top;
	i = 0;
	while (cur)
	{
		arr[i++] = cur->idx;
		cur = cur->next;
	}
}

static long	count_inversions(const int *arr, int n)
{
	long	inv;
	int		i;
	int		j;

	inv = 0;
	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (arr[i] > arr[j])
				inv++;
			j++;
		}
		i++;
	}
	return (inv);
}

double	calc_disorder(t_stack *a)
{
	int		n;
	int		*arr;
	long	inv;
	long	max_pairs;

	if (!a || a->size <= 1)
		return (0.0);
	n = a->size;
	arr = ((int *)malloc(sizeof(int) * n));
	if (!arr)
		error_exit();
	stack_to_idx_array(a, arr);
	inv = count_inversions(arr, n);
	free(arr);
	max_pairs = (long)n * (n - 1) / 2;
	if (max_pairs == 0)
		return (0.0);
	return ((double)inv / (double)max_pairs);
}

void	adaptive_sort(t_stack *a, t_stack *b)
{
	double	d;
	int		n;

	if (!a || a->size <= 1)
		return ;
	n = a->size;
	if (n <= 5)
	{
		simple_sort(a, b);
		return ;
	}
	d = calc_disorder(a);
	if (d <= 0.2)
		simple_sort(a, b);
	else if (d > 0.2 && d <= 0.5)
		range_sort(a, b);
	else
		hybrid_sort(a, b);
}
