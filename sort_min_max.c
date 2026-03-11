/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-tawa <mal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 02:52:15 by mal-tawa          #+#    #+#             */
/*   Updated: 2026/02/25 02:52:16 by mal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort(t_node *s)
{
	if (!s)
		return (1);
	while (s ->next)
	{
		if (s -> val > s -> next ->val)
			return (0);
		s = s->next;
	}
	return (1);
}

int	min(t_node *n)
{
	int	min;
	int	pos;
	int	i;

	min = n ->val;
	pos = 0;
	i = 0;
	while (n)
	{
		if (min > n ->val)
		{
			min = n ->val;
			pos = i;
		}
		n = n ->next;
		i++;
	}
	return (pos);
}

int	max(t_node *n)
{
	int	max;
	int	pos;
	int	i;

	max = n ->val;
	pos = 0;
	i = 0;
	while (n)
	{
		if (max < n ->val)
		{
			max = n ->val;
			pos = i;
		}
		n = n ->next;
		i++;
	}
	return (pos);
}
