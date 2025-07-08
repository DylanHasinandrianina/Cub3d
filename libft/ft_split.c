/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:10:22 by shasinan          #+#    #+#             */
/*   Updated: 2025/04/17 18:52:56 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char *sr, char c)
{
	int	count;
	int	word;
	int	i;

	count = 0;
	word = 0;
	i = 0;
	while (sr[i])
	{
		if (sr[i] == c)
			word = 0;
		else if (sr[i] != c && word == 0)
		{
			count++;
			word = 1;
		}
		i++;
	}
	return (count);
}

static char	**free_split(char **split, int j)
{
	while (j > 0)
		free(split[j--]);
	free(split);
	return (NULL);
}

void	set_mem(char **t, char const *s, char c)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		len = 0;
		while (s[i + len] && s[i + len] != c)
			len++;
		if (len > 0)
		{
			t[j] = ft_substr(s, i, len);
			if (!t[j])
				free_split(&t[j], j);
			j++;
		}
		i = i + len;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		len;

	len = count_word((char *)s, c);
	split = (char **)malloc(sizeof(char *) * (len + 1));
	if (!split)
		return (NULL);
	set_mem(split, s, c);
	split[len] = NULL;
	return (split);
}
