/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_print_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-tawa <mal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 02:49:12 by mal-tawa          #+#    #+#             */
/*   Updated: 2026/02/25 02:49:15 by mal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_kv(const char *k, long v)
{
	put_str_fd(k, 2);
	put_nbr_fd(v, 2);
	put_str_fd(" ", 2);
}

static void	bench_print_counts_1(const t_bench *b)
{
	print_kv("sa=", b->sa);
	print_kv("sb=", b->sb);
	print_kv("ss=", b->ss);
	print_kv("pa=", b->pa);
	print_kv("pb=", b->pb);
	print_kv("ra=", b->ra);
}

static void	bench_print_counts_2(const t_bench *b)
{
	print_kv("rb=", b->rb);
	print_kv("rr=", b->rr);
	print_kv("rra=", b->rra);
	print_kv("rrb=", b->rrb);
	put_str_fd("rrr=", 2);
	put_nbr_fd(b->rrr, 2);
}

void	bench_print_counts(const t_bench *b)
{
	put_str_fd("counts: ", 2);
	bench_print_counts_1(b);
	bench_print_counts_2(b);
	put_str_fd("\n", 2);
}
