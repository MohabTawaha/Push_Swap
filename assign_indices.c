/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_indices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-tawa <mal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 23:11:54 by mal-tawa          #+#    #+#             */
/*   Updated: 2026/02/24 23:13:57 by mal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_int(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

static void	sort_int_array(int *arr, int n)
{
	int	i;
	int	swapped;

	if (!arr || n <= 1)
		return ;
	while (1)
	{
		swapped = 0;
		i = 0;
		while (i < n - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				swap_int(&arr[i], &arr[i + 1]);
				swapped = 1;
			}
			i++;
		}
		if (!swapped)
			break ;
	}
}

static int	binary_search(int *arr, int n, int target)
{
	int	lo;
	int	hi;
	int	mid;

	lo = 0;
	hi = n - 1;
	while (lo <= hi)
	{
		mid = lo + (hi - lo) / 2;
		if (arr[mid] == target)
			return (mid);
		if (arr[mid] < target)
			lo = mid + 1;
		else
			hi = mid - 1;
	}
	return (-1);
}

static int	*create_sorted_array(t_stack *a)
{
	int		*arr;
	int		i;
	t_node	*cur;

	arr = (int *)malloc(sizeof(int) * a->size);
	if (!arr)
		return (NULL);
	cur = a->top;
	i = 0;
	while (cur)
	{
		arr[i] = cur->val;
		i++;
		cur = cur->next;
	}
	sort_int_array(arr, a->size);
	return (arr);
}

void	assign_indices(t_stack *a)
{
	int		*arr;
	t_node	*cur;

	if (!a || a->size <= 0)
		return ;
	arr = create_sorted_array(a);
	if (!arr)
		error_exit();
	cur = a->top;
	while (cur)
	{
		cur->idx = binary_search(arr, a->size, cur->val);
		if (cur->idx < 0)
		{
			free(arr);
			error_exit();
		}
		cur = cur->next;
	}
	free(arr);
}
