/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_print_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-tawa <mal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 23:18:12 by mal-tawa          #+#    #+#             */
/*   Updated: 2026/02/24 23:19:03 by mal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_percent_2dp(double d, int fd)
{
	long	p100;
	long	ip;
	long	fp;

	if (d < 0.0)
		d = 0.0;
	if (d > 1.0)
		d = 1.0;
	p100 = (long)(d * 10000.0 + 0.5);
	ip = p100 / 100;
	fp = p100 % 100;
	put_nbr_fd(ip, fd);
	write(fd, ".", 1);
	if (fp < 10)
		write(fd, "0", 1);
	put_nbr_fd(fp, fd);
	write(fd, "%", 1);
}

void	bench_print_report(const t_bench *b)
{
	if (!b || !b->enabled)
		return ;
	bench_print_header(b);
	bench_print_counts(b);
}

void	bench_print_header(const t_bench *b)
{
	put_str_fd("disorder: ", 2);
	put_percent_2dp(b->disorder, 2);
	put_str_fd("\n", 2);
	put_str_fd("strategy: ", 2);
	put_str_fd(b->strategy, 2);
	put_str_fd(" / ", 2);
	put_str_fd(b->complexity, 2);
	put_str_fd("\n", 2);
	put_str_fd("total_ops: ", 2);
	put_nbr_fd(b->total_ops, 2);
	put_str_fd("\n", 2);
}
