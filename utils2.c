/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-tawa <mal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 02:53:36 by mal-tawa          #+#    #+#             */
/*   Updated: 2026/02/25 02:53:40 by mal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static long	atoi_check(const char *s, long *sign)
{
	long		i;

	*sign = 1;
	i = 0;
	while (is_space(s[i]))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			*sign = -1;
		i++;
	}
	if (!s[i] || !is_digit(s[i]))
		error_exit();
	return (i);
}

long	atoi_strict(const char *s, int *ok)
{
	long		sign;
	long		res;
	long		i;

	res = 0;
	i = atoi_check(s, &sign);
	while (s[i])
	{
		if (!is_digit(s[i]))
			error_exit();
		if (sign == 1 && (res > (INT_MAX - (s[i] - '0')) / 10))
			error_exit();
		if (sign == -1 && (res > (-(long)INT_MIN - (s[i] - '0')) / 10))
			error_exit();
		res = res * 10 + (s[i] - '0');
		i++;
	}
	*ok = 1;
	return (res * sign);
}
