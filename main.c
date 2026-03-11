/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-tawa <mal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 00:00:00 by mal-tawa          #+#    #+#             */
/*   Updated: 2026/02/25 02:40:46 by mal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_with_bench(t_stack *a, t_stack *b, t_mode mode, int bench)
{
	if (bench)
	{
		bench_init(&a->bench, 1);
		bench_set_disorder(&a->bench, calc_disorder(a));
	}
	run_mode(mode, a, b);
	if (bench)
		bench_print_report(&a->bench);
}

static t_mode	get_mode(int bench, t_mode mode)
{
	if (mode != MODE_AUTO)
		return (mode);
	if (bench)
		return (MODE_ADAPTIVE);
	return (MODE_AUTO);
}

static int	parse_and_fill(t_stack *a, char **av, int ac)
{
	int	*vals;
	int	cnt;
	int	i;

	if (!phase_input(ac, av, &cnt, &vals))
		return (0);
	i = 0;
	while (i < cnt)
	{
		push_bottom(a, new_node(vals[i]));
		i++;
	}
	free(vals);
	a->size = cnt;
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	int		bench;
	t_mode	mode;

	if (ac < 2)
		return (0);
	parse_flags(ac, av, &bench, &mode);
	av = strip_flags(ac, av, &ac);
	if (!av)
		error_exit();
	stack_init(&a, 'a');
	stack_init(&b, 'b');
	if (!parse_and_fill(&a, av, ac))
		error_exit();
	free(av);
	assign_indices(&a);
	run_with_bench(&a, &b, get_mode(bench, mode), bench);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
