/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-tawa <mal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 02:48:47 by mal-tawa          #+#    #+#             */
/*   Updated: 2026/02/25 02:48:48 by mal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bench_inc(t_bench *b, t_op op)
{
	if (!b || !b->enabled)
		return ;
	b->total_ops++;
	if (op == OP_SA)
		b->sa++;
	else if (op == OP_SB)
		b->sb++;
	else if (op == OP_SS)
		b->ss++;
	else if (op == OP_PA)
		b->pa++;
	else if (op == OP_PB)
		b->pb++;
	else if (op == OP_RA)
		b->ra++;
	else if (op == OP_RB)
		b->rb++;
	else if (op == OP_RR)
		b->rr++;
	else if (op == OP_RRA)
		b->rra++;
	else if (op == OP_RRB)
		b->rrb++;
	else if (op == OP_RRR)
		b->rrr++;
}
