/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-tawa <mal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 02:49:41 by mal-tawa          #+#    #+#             */
/*   Updated: 2026/02/25 02:49:43 by mal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_str_fd(const char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
}

void	put_nbr_fd(long n, int fd)
{
	char	c;

	if (n >= 10)
		put_nbr_fd(n / 10, fd);
	c = '0' + (n % 10);
	write(fd, &c, 1);
}
