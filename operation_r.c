/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-tawa <mal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 20:55:01 by mal-tawa          #+#    #+#             */
/*   Updated: 2026/02/24 23:25:00 by mal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *s)
{
	push_bottom(s, pop_top(s));
}

void	ra(t_stack *a)
{
	rotate(a);
	if (a->bench.enabled)
		bench_inc(&a->bench, OP_RA);
	if (a->emit_ops)
		write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	rotate(b);
	if (b->emit_ops)
		write(1, "rb\n", 3);
	if (b->bench.enabled)
		bench_inc(&b->bench, OP_RB);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	if (a->bench.enabled)
		bench_inc(&a->bench, OP_RR);
	if (a->emit_ops)
		write(1, "rr\n", 3);
}
