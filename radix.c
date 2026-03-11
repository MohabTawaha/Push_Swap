/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-tawa <mal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 02:50:50 by mal-tawa          #+#    #+#             */
/*   Updated: 2026/02/25 02:50:52 by mal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	pick_chunk(int size)
{
	if (size <= 100)
		return (15);
	return (30);
}

static void	push_chunks(t_stack *a, t_stack *b)
{
	int	chunk;
	int	low;
	int	high;
	int	max;

	chunk = pick_chunk(a -> size);
	low = 0;
	high = chunk - 1;
	max = a->size - 1;
	while (a ->size > low)
	{
		if (a -> top -> idx >= low && a ->top -> idx <= high)
		{
			pb(a, b);
			if (b ->top -> idx < (low + high) / 2)
				rb(b);
			low++;
			high++;
			if (high > max)
				high = max;
		}
		else
			ra(a);
	}
}

static int	find_max_pos(t_stack *b)
{
	t_node	*tmp;
	int		max;
	int		pos;
	int		i;

	tmp = b ->top;
	max = tmp -> idx;
	pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp -> idx > max)
		{
			max = tmp -> idx;
			pos = i;
		}
		tmp = tmp -> next;
		i++;
	}
	return (pos);
}

static void	smart_pa(t_stack *a, t_stack *b)
{
	int	pos;
	int	moves;

	pos = find_max_pos(b);
	if (pos <= b -> size / 2)
		while (pos-- > 0)
			rb(b);
	else
	{
		moves = b -> size - pos;
		while (moves-- > 0)
			rrb(b);
	}
	pa(a, b);
}

void	hybrid_sort(t_stack *a, t_stack *b)
{
	if (!a || a -> size <= 1)
		return ;
	push_chunks(a, b);
	while (b->size > 0)
		smart_pa(a, b);
}
