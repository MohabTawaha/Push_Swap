/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-tawa <mal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 23:22:13 by mal-tawa          #+#    #+#             */
/*   Updated: 2026/02/25 01:38:33 by mal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *s)
{
	t_node	*a;
	t_node	*b;

	if (!s || s->size < 2)
		return ;
	a = pop_top(s);
	b = pop_top(s);
	push_top(s, a);
	push_top(s, b);
}

void	sa(t_stack *a)
{
	swap(a);
	if (a->bench.enabled)
		bench_inc(&a->bench, OP_SA);
	if (a->emit_ops)
		write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	swap(b);
	if (b->bench.enabled)
		bench_inc(&b->bench, OP_SB);
	if (b->emit_ops)
		write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	if (a->bench.enabled)
		bench_inc(&a->bench, OP_SS);
	if (a->emit_ops)
		write(1, "ss\n", 3);
}
