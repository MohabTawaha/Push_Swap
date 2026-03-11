/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-tawa <mal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 02:48:25 by mal-tawa          #+#    #+#             */
/*   Updated: 2026/02/25 02:53:56 by mal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bench_init(t_bench *b, int enabled)
{
	if (!b)
		return ;
	b->enabled = enabled;
	b ->disorder = 0.0;
	b->strategy = "unknown";
	b->complexity = "Unknown";
	b->total_ops = 0;
	b->sa = 0;
	b->sb = 0;
	b->ss = 0;
	b->pa = 0;
	b->pb = 0;
	b->ra = 0;
	b->rb = 0;
	b->rr = 0;
	b->rra = 0;
	b->rrb = 0;
	b->rrr = 0;
}

void	bench_set_disorder(t_bench *b, double d)
{
	if (!b)
		return ;
	b -> disorder = d;
}

void	bench_set_strategy(t_bench *b, char *name, char *complexity)
{
	if (!b)
		return ;
	if (name)
		b->strategy = name;
	if (complexity)
		b->complexity = complexity;
}
