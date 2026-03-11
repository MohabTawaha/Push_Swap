/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-tawa <mal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:34:59 by mal-tawa          #+#    #+#             */
/*   Updated: 2026/02/14 18:03:28 by abtaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	node_isolate(t_node *n)
{
	if (!n)
		return ;
	n -> next = NULL;
	n -> prev = NULL;
}

t_node	*pop_top(t_stack *s)
{
	t_node	*n;

	if (!s || s -> size == 0)
		return (NULL);
	n = s -> top;
	if (s -> size == 1)
	{
		s -> top = NULL;
		s -> bottom = NULL;
	}
	else
	{
		s -> top = n -> next;
		if (s->top)
			s -> top -> prev = NULL;
	}
	s -> size --;
	node_isolate(n);
	return (n);
}

t_node	*pop_bottom(t_stack *s)
{
	t_node	*n;

	if (!s || s -> size == 0)
		return (NULL);
	n = s -> bottom;
	if (s -> size == 1)
	{
		s -> top = NULL;
		s -> bottom = NULL;
	}
	else
	{
		s -> bottom = n -> prev;
		s -> bottom -> next = NULL;
	}
	s -> size --;
	node_isolate(n);
	return (n);
}

void	push_top(t_stack *s, t_node *n)
{
	if (!s ||!n)
		return ;
	if (s ->size == 0)
	{
		s -> top = n;
		s->bottom = n;
		n ->next = NULL;
		n -> prev = NULL;
	}
	else
	{
		n -> next = s ->top;
		n -> prev = NULL;
		s -> top -> prev = n;
		s -> top = n;
	}
	s ->size++;
}

void	push_bottom(t_stack *s, t_node *n)
{
	if (!s || !n)
		return ;
	if (s -> size == 0)
	{
		s -> top = n;
		s -> bottom = n;
		n -> next = NULL;
		n -> prev = NULL;
	}
	else
	{
		n -> prev = s -> bottom;
		n -> next = NULL;
		s -> bottom -> next = n;
		s -> bottom = n;
	}
	s -> size++;
}
