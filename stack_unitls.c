/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_unitls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-tawa <mal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 02:52:54 by mal-tawa          #+#    #+#             */
/*   Updated: 2026/02/25 02:52:58 by mal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack *s, char name)
{
	s -> top = NULL;
	s -> bottom = NULL;
	s -> size = 0;
	s -> name = name;
	s -> emit_ops = 1;
}

t_node	*new_node(int val)
{
	t_node	*n;

	n = (t_node *)malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->val = val;
	n->idx = -1;
	n->prev = NULL;
	n->next = NULL;
	return (n);
}

void	stack_push_bottom(t_stack *s, t_node *n)
{
	if (!n)
		return ;
	if (s->size == 0)
	{
		s->top = n;
		s->bottom = n;
	}
	else
	{
		n->prev = s->bottom;
		s->bottom->next = n;
		s->bottom = n;
	}
	s->size++;
}

void	stack_clear(t_stack *s)
{
	t_node	*cur;
	t_node	*next;

	cur = s->top;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	s->top = NULL;
	s->bottom = NULL;
	s->size = 0;
}
