/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-tawa <mal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 02:50:32 by mal-tawa          #+#    #+#             */
/*   Updated: 2026/02/25 02:50:35 by mal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				val;
	int				idx;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_bench
{
	int			enabled;
	double		disorder;
	char		*strategy;
	char		*complexity;
	long		total_ops;

	long		sa;
	long		sb;
	long		ss;
	long		pa;
	long		pb;
	long		ra;
	long		rb;
	long		rr;
	long		rra;
	long		rrb;
	long		rrr;
}	t_bench;

typedef struct s_stack
{
	int		size;
	char	name;
	t_node	*top;
	t_node	*bottom;
	t_bench	bench;
	int		emit_ops;
}	t_stack;

typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR
}	t_op;

typedef enum e_mode
{
	MODE_AUTO = 0,
	MODE_SIMPLE,
	MODE_MEDIUM,
	MODE_COMPLEX,
	MODE_ADAPTIVE
}	t_mode;

void	error_exit(void);

void	free_split(char **arr);

char	**split_ws( const char *s);

long	atoi_strict( const char *s, int *ok);

int		phase_input(int argc, char **argv, int *out_count, int **out_value);

void	stack_init(t_stack *s, char name);

t_node	*new_node(int val);

void	push_bottom(t_stack *s, t_node *n);

void	stack_clear(t_stack *s);

void	ss(t_stack *a, t_stack *b);

void	sa(t_stack *a);

void	sb(t_stack *b);

void	pa(t_stack *a, t_stack *b);

void	pb(t_stack *a, t_stack *b);

void	rr(t_stack *a, t_stack *b);

void	ra(t_stack *a);

void	rb(t_stack *b);

void	rrr(t_stack *a, t_stack *b);

void	rra(t_stack *a);

void	rrb(t_stack *b);

void	node_isolate(t_node *n);

t_node	*pop_top(t_stack *s);

t_node	*pop_bottom(t_stack *s);

void	push_top(t_stack *s, t_node *n);

void	push_bottom(t_stack *s, t_node *n);

int		sort(t_node *s);

int		min(t_node *n);

int		max(t_node *n);

int		stack_size(t_node *n);

void	rotate_top_a(t_stack *a, int rank);

void	rotate_top_b(t_stack *b, int rank);

void	sort_3(t_stack *a);

void	sort_5(t_stack *a, t_stack *b);

void	simple_sort(t_stack *a, t_stack *b);

void	hybrid_sort(t_stack *a, t_stack *b);

void	bench_init(t_bench *b, int enabled);

void	bench_set_disorder(t_bench *b, double d);

void	bench_set_strategy(t_bench *b, char *name,
			char *complexity);

void	bench_inc(t_bench *b, t_op op);

void	bench_print_report(const t_bench *b);

void	bench_print_header(const t_bench *b);

void	bench_print_counts(const t_bench *b);

void	put_str_fd(const char *s, int fd);

void	put_nbr_fd(long n, int fd);

double	calc_disorder(t_stack *a);

void	adaptive_sort(t_stack *a, t_stack *b);

void	range_sort(t_stack *a, t_stack *b);

void	assign_indices(t_stack *a);

void	parse_flags(int argc, char **argv, int *bench_on, t_mode *mode);

char	**strip_flags(int argc, char **argv, int *new_argc);

void	run_mode(t_mode mode, t_stack *a, t_stack *b);

void	build_stack_a(t_stack *a, int *vals, int n);
#endif
