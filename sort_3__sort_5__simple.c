/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3__sort_5__simple.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-tawa <mal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 02:51:59 by mal-tawa          #+#    #+#             */
/*   Updated: 2026/02/25 02:52:01 by mal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	if (sort(a->top))
		return ;
	x = a->top->val;
	y = a->top->next->val;
	z = a->top->next->next->val;
	if (x > y && x < z && z > y)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && z < x && y < z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}

void	sort_5(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		rotate_top_a(a, min(a->top));
		pb(a, b);
	}
	sort_3(a);
	while (b->size > 0)
	{
		rotate_top_b(b, max(b->top));
		pa(a, b);
	}
	rotate_top_a(a, min(a->top));
}

void	simple_sort(t_stack *a, t_stack *b)
{
	int	i;

	if (!a || a -> size <= 1 || sort(a -> top))
		return ;
	i = a -> size;
	if (i == 2)
		return (sa(a));
	if (i == 3)
	{
		sort_3(a);
		return ;
	}
	if (i <= 5)
	{
		sort_5(a, b);
		return ;
	}
	while (a -> size > 3)
	{
		rotate_top_a(a, min(a->top));
		pb(a, b);
	}
	sort_3(a);
	while (b ->size > 0)
		pa(a, b);
}
