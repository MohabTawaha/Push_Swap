/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-tawa <mal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 23:42:42 by mal-tawa          #+#    #+#             */
/*   Updated: 2026/02/24 23:43:08 by mal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

static int	streq(const char *a, const char *b)
{
	int	i;

	i = 0;
	while (a && b && a[i] && b[i] && a[i] == b[i])
		i++;
	return (a && b && a[i] == '\0' && b[i] == '\0');
}

static int	is_flag(const char *s)
{
	return (s && s[0] == '-' && s[1] == '-');
}

void	parse_flags(int argc, char **argv, int *bench_on, t_mode *mode)
{
	int	i;

	i = 1;
	*bench_on = 0;
	*mode = MODE_AUTO;
	while (i < argc)
	{
		if (is_flag(argv[i]))
		{
			if (streq(argv[i], "--bench"))
				*bench_on = 1;
			else if (streq(argv[i], "--simple"))
				*mode = MODE_SIMPLE;
			else if (streq(argv[i], "--medium"))
				*mode = MODE_MEDIUM;
			else if (streq(argv[i], "--complex"))
				*mode = MODE_COMPLEX;
			else if (streq(argv[i], "--adaptive"))
				*mode = MODE_ADAPTIVE;
			else
				error_exit();
		}
		i++;
	}
}
