/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_builder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-tawa <mal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 23:43:46 by mal-tawa          #+#    #+#             */
/*   Updated: 2026/02/24 23:49:37 by mal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

static int	is_flag(const char *s)
{
	return (s && s[0] == '-' && s[1] == '-');
}

char	**strip_flags(int argc, char **argv, int *new_argc)
{
	char	**out;
	int		i;
	int		j;

	out = malloc(sizeof(char *) * (argc + 1));
	if (!out)
		return (NULL);
	i = 0;
	j = 0;
	while (i < argc)
	{
		if (!is_flag(argv[i]))
			out[j++] = argv[i];
		i++;
	}
	out[j] = NULL;
	*new_argc = j;
	return (out);
}

void	build_stack_a(t_stack *a, int *vals, int n)
{
	int		i;
	t_node	*node;

	i = 0;
	while (i < n)
	{
		node = new_node(vals[i]);
		if (!node)
			error_exit();
		push_bottom(a, node);
		i++;
	}
}
