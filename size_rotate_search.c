/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_rotate_search.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-tawa <mal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 02:51:40 by mal-tawa          #+#    #+#             */
/*   Updated: 2026/02/25 02:51:43 by mal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_node *n)
{
	int	i;

	i = 0;
	while (n)
	{
		i++;
		n = n ->next;
	}
	return (i);
}

int	find_pos_by_idx(t_node *s, int target_idx)
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

void	rotate_top_a(t_stack *a, int rank)
{
	int	pos;
	int	size;
	int	moves;

	size = a ->size;
	pos = find_pos_by_idx(a->top, rank);
	if (!pos)
		return ;
	if (pos <= (size / 2))
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		moves = size - pos;
		while (moves -- > 0)
			rra(a);
	}
}

void	rotate_top_b(t_stack *b, int rank)
{
	int	pos;
	int	size;
	int	moves;

	size = b ->size;
	pos = find_pos_by_idx(b->top, rank);
	if (!pos)
		return ;
	if (pos <= (size / 2))
	{
		while (pos-- > 0)
			rb(b);
	}
	else
	{
		moves = size - pos;
		while (moves -- > 0)
			rrb(b);
	}
}
