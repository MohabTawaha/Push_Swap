/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-tawa <mal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 21:00:04 by mal-tawa          #+#    #+#             */
/*   Updated: 2026/02/25 01:52:26 by mal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	r_rotate(t_stack *s)
{
	push_top(s, pop_bottom(s));
}

void	rra(t_stack *a)
{
	r_rotate(a);
	if (a->bench.enabled)
		bench_inc(&a->bench, OP_RRA);
	if (a->emit_ops)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	r_rotate(b);
	if (b->bench.enabled)
		bench_inc(&b->bench, OP_RRB);
	if (b->emit_ops)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	r_rotate(a);
	r_rotate(b);
	if (a->bench.enabled)
		bench_inc(&a->bench, OP_RRR);
	if (a->emit_ops)
		write(1, "rrr\n", 4);
}
