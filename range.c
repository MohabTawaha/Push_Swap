/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-tawa <mal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 02:51:12 by mal-tawa          #+#    #+#             */
/*   Updated: 2026/02/25 02:51:16 by mal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_pos_by_idx(t_node *s, int target_idx)
{
	int	i;

	i = 0;
	while (s)
	{
		if (s->idx == target_idx)
			return (i);
		i++;
		s = s -> next;
	}
	return (-1);
}

static void	push_idx_from_b_to_a(t_stack *a, t_stack *b, int target_idx)
{
	int	moves;
	int	pos;
	int	size;

	size = b -> size;
	pos = find_pos_by_idx(b->top, target_idx);
	if (pos == -1)
		return ;
	if (pos < size / 2)
	{
		while (pos-- > 0)
			rb(b);
	}
	else
	{
		moves = size - pos;
		while (moves-- > 0)
			rrb(b);
	}
	pa(a, b);
}

static int	pick_window(int n)
{
	if (n <= 20)
		return (6);
	else if (n <= 100)
		return (15);
	else
		return (40);
}

static void	sort_and_pa_stack_p(t_stack *a, t_stack *b, int max)
{
	while (b ->size > 0)
	{
		push_idx_from_b_to_a(a, b, max);
		max--;
	}
}

void	range_sort(t_stack *a, t_stack *b)
{
	int	low;
	int	high;
	int	max;

	if (!a || a->size <= 1 || sort(a->top))
		return ;
	low = 0;
	high = pick_window(a ->size) - 1;
	max = a -> size - 1;
	while (a ->size > 0)
	{
		if (a -> top -> idx <= high)
		{
			pb(a, b);
			if (b -> top && b-> top -> idx < low)
				rb(b);
			low++;
			high++;
			if (high > max)
				high = max;
		}
		else
			ra(a);
	}
	sort_and_pa_stack_p(a, b, max);
}
