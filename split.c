/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-tawa <mal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 02:52:30 by mal-tawa          #+#    #+#             */
/*   Updated: 2026/02/25 02:52:33 by mal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	is_space( const char s)
{
	return ((s == ' ') || (s >= 9 && s <= 13));
}

static int	count_word(const char *s)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && is_space(s[i]))
			i++;
		if (s[i] && !is_space(s[i]))
			count++;
		while (s[i] && !is_space(s[i]))
			i++;
	}
	return (count);
}

static char	*word_dup(const char *s, int start, int end)
{
	char	*n;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	n = malloc (end - start + 1);
	if (!n)
		return (NULL);
	while (start < end)
	{
		n[i] = s[start];
		i++;
		start++;
	}
	n[i] = '\0';
	return (n);
}

static void	fill_split(char **arr, const char *s, int word)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i] && j < word)
	{
		while (s[i] && is_space(s[i]))
			i++;
		start = i;
		while (s[i] && !is_space(s[i]))
			i++;
		arr[j] = word_dup(s, start, i);
		if (!arr[j])
		{
			free_split(arr);
			return ;
		}
		j++;
	}
}

char	**split_ws(const char *s)
{
	int		word;
	char	**arr;

	if (!s)
		return (0);
	word = count_word(s);
	arr = malloc(sizeof(char *) * (word + 1));
	if (!arr)
		return (0);
	fill_split(arr, s, word);
	arr[word] = NULL;
	return (arr);
}
