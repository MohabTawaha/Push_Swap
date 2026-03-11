/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-tawa <mal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 20:47:47 by mal-tawa          #+#    #+#             */
/*   Updated: 2026/02/24 23:26:08 by mal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	tmp = pop_top(b);
	if (!tmp)
		return ;
	push_top(a, tmp);
	if (a->bench.enabled)
		bench_inc(&a->bench, OP_PA);
	if (a->emit_ops)
		write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	tmp = pop_top(a);
	if (!tmp)
		return ;
	push_top(b, tmp);
	if (a->bench.enabled)
		bench_inc(&a->bench, OP_PB);
	if (a->emit_ops)
		write(1, "pb\n", 3);
}
