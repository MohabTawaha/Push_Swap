/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-tawa <mal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 23:45:06 by mal-tawa          #+#    #+#             */
/*   Updated: 2026/03/03 00:29:04 by mal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_adaptive_complexity(t_stack *a, double d)
{
	if (d <= 0.2 || a->size <= 5)
		a->bench.complexity = "O(n^2)";
	else if (d > 0.2 && d <= 0.5)
		a->bench.complexity = "O(n√n)";
	else
		a->bench.complexity = "O(n log n)";
}

void	run_mode(t_mode mode, t_stack *a, t_stack *b)
{
	if (mode == MODE_SIMPLE)
	{
		a->bench.strategy = "simple";
		a->bench.complexity = "O(n^2)";
		simple_sort(a, b);
	}
	else if (mode == MODE_MEDIUM)
	{
		a->bench.strategy = "medium";
		a->bench.complexity = "O(n√n)";
		range_sort(a, b);
	}
	else if (mode == MODE_COMPLEX)
	{
		a->bench.strategy = "complex";
		a->bench.complexity = "O(n log n)";
		hybrid_sort(a, b);
	}
	else
	{
		a->bench.strategy = "adaptive";
		set_adaptive_complexity(a, calc_disorder(a));
		adaptive_sort(a, b);
	}
}
