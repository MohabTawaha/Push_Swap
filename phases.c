/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phases.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-tawa <mal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 02:50:11 by mal-tawa          #+#    #+#             */
/*   Updated: 2026/02/25 02:50:13 by mal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_duplicate(int *vals, int n)
{
	int		i;
	int		j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (vals[i] == vals[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	grow_array(int **vals, int *cap)
{
	int		*new;
	int		i;

	i = 0;
	*cap *= 2;
	new = malloc(sizeof(int) *(*cap));
	if (!new)
		return (0);
	while (i < *cap / 2)
	{
		new[i] = (*vals)[i];
		i++;
	}
	free(*vals);
	*vals = new;
	return (1);
}

static int	parse_arg_push(char *arg, int **vals, int *total, int *cap)
{
	char	**parts;
	int		p;
	int		ok;
	long	x;

	p = 0;
	parts = split_ws(arg);
	if (!parts)
		return (0);
	while (parts[p])
	{
		x = atoi_strict(parts[p], &ok);
		if (!ok)
			return (free_split(parts), 0);
		if (*total == *cap && !grow_array(vals, cap))
			return (free_split(parts), 0);
		(*vals)[(*total)++] = (int)x;
		p++;
	}
	free_split(parts);
	return (1);
}

static int	finalize(int *vals, int total, int *out_count, int **out_vals)
{
	if (has_duplicate(vals, total))
	{
		free(vals);
		return (0);
	}
	*out_count = total;
	*out_vals = vals;
	return (1);
}

int	phase_input(int argc, char **argv, int *out_count, int **out_value)
{
	int		total;
	int		cap;
	int		*vals;
	int		i;

	total = 0;
	cap = 16;
	i = 1;
	vals = malloc((sizeof(int) *(cap)));
	if (!vals)
		return (0);
	while (i < argc)
	{
		if (!parse_arg_push(argv[i], &vals, &total, &cap))
			return (free(vals), 0);
		i++;
	}
	return (finalize(vals, total, out_count, out_value));
}
